# Copyright (C) 2018-2021 Intel Corporation
# SPDX-License-Identifier: Apache-2.0
#

set (TARGET_NAME "ov_auto_plugin")

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/utils/*.cpp)

ie_add_plugin(NAME ${TARGET_NAME}
              DEVICE_NAME "MULTI"
              SOURCES ${SOURCES} 
              VERSION_DEFINES_FOR plugin.cpp)

ie_add_plugin(NAME ${TARGET_NAME}
              DEVICE_NAME "AUTO"
              PSEUDO_PLUGIN_FOR "MULTI"
              DEFAULT_CONFIG "MULTI_WORK_MODE_AS_AUTO:YES")

target_link_libraries(${TARGET_NAME} PRIVATE ngraph inference_engine_transformations)

set_ie_threading_interface_for(${TARGET_NAME})

ie_add_api_validator_post_build_step(TARGET ${TARGET_NAME})

set_target_properties(${TARGET_NAME} PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE ${ENABLE_LTO})