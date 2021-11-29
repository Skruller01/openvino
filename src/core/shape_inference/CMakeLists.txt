# Copyright (C) 2018-2021 Intel Corporation
# SPDX-License-Identifier: Apache-2.0
#

set(TARGET_NAME "ov_shape_inference")

file(GLOB_RECURSE LIBRARY_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE PUBLIC_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

set(SHAPE_INFER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Create named folders for the sources within the .vcproj
# Empty name lists them directly under the .vcproj

source_group("src" FILES ${LIBRARY_SRC})
source_group("include" FILES ${PUBLIC_HEADERS})

# Create static library
add_library(${TARGET_NAME} STATIC ${LIBRARY_SRC} ${PUBLIC_HEADERS})

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${SHAPE_INFER_INCLUDE_DIR}>
    $<BUILD_INTERFACE:${NGRAPH_INCLUDE_PATH}>)

if(NOT BUILD_SHARED_LIBS)
    target_compile_definitions(${TARGET_NAME} PUBLIC OPENVINO_STATIC_LIBRARY)
endif()

ov_install_static_lib(${TARGET_NAME} ngraph)

# developer package
openvino_developer_export_targets(COMPONENT ngraph TARGETS ${TARGET_NAME})