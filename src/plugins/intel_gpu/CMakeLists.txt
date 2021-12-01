# Copyright (C) 2018-2021 Intel Corporation
# SPDX-License-Identifier: Apache-2.0
#

set (TARGET_NAME "clDNNPlugin")

if(CMAKE_COMPILER_IS_GNUCXX)
    ie_add_compiler_flags(-Wno-all)
    ie_add_compiler_flags(-msse4.1 -msse4.2)
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7.0)
        ie_add_compiler_flags(-Wno-error=terminate)
    endif()
endif()

if(ENABLE_GPU_DEBUG_CAPS)
  add_definitions(-DGPU_DEBUG_CONFIG=1)
endif()

file(GLOB_RECURSE PLUGIN_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/plugin/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/intel_gpu/plugin/*.h)

addVersionDefines(src/plugin/cldnn_engine.cpp CI_BUILD_NUMBER CLDNN_VERSION)

ie_add_plugin(NAME ${TARGET_NAME}
              DEVICE_NAME "GPU"
              SOURCES ${PLUGIN_SOURCES}
              VERSION_DEFINES_FOR src/plugin/cldnn_engine.cpp)

target_compile_options(${TARGET_NAME} PRIVATE
    $<$<CONFIG:Release>:$<IF:$<CXX_COMPILER_ID:MSVC>,/Os,-Os>>)

target_link_libraries(${TARGET_NAME} PRIVATE clDNN_lib pugixml::static
                                             inference_engine_transformations
                                             inference_engine_lp_transformations
                                             ngraph)

target_include_directories(${TARGET_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/intel_gpu/plugin/
        $<TARGET_PROPERTY:inference_engine_transformations,INTERFACE_INCLUDE_DIRECTORIES>
        ${clDNN_SOURCE_DIR}/api)

set_target_properties(${TARGET_NAME} PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE ${ENABLE_LTO})

# Workaround to avoid warnings during LTO build
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set_target_properties(${TARGET_NAME} PROPERTIES LINK_FLAGS_RELEASE "-Wno-error=maybe-uninitialized -Wno-maybe-uninitialized")
endif()

# Failed because of OpenCL
# ie_add_api_validator_post_build_step(TARGET ${TARGET_NAME})

# install

install(FILES "${clDNN_SOURCE_DIR}/kernel_selector/core/cache/cache.json"
        DESTINATION ${IE_CPACK_RUNTIME_PATH}
        COMPONENT gpu)