# Copyright (C) 2018-2021 Intel Corporation
# SPDX-License-Identifier: Apache-2.0
#

set(TARGET_NAME "benchmark_app")

file (GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file (GLOB HDR ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

ie_add_sample(NAME ${TARGET_NAME}
              SOURCES ${SRC}
              HEADERS ${HDR}
              DEPENDENCIES format_reader ie_samples_utils)

# Optional OpenCL dependnency

find_package(OpenCL)

find_path(OpenCL_HPP_INCLUDE_DIR
    NAMES
      CL/cl2.hpp OpenCL/cl2.hpp
    HINTS
      ${opencl_root_hints}
      ENV "PROGRAMFILES(X86)"
      ENV AMDAPPSDKROOT
      ENV INTELOCLSDKROOT
      ENV NVSDKCOMPUTE_ROOT
      ENV CUDA_PATH
      ENV ATISTREAMSDKROOT
      ENV OCL_ROOT
    PATH_SUFFIXES
      include
      OpenCL/common/inc
      "AMD APP/include")

if(TARGET OpenCL)
    # Use OpenCL CPP headers from sources if present
    set(OpenCL_HEADERS ${OPENCL_HEADERS_DIR})
    set(OpenCL_LIB "OpenCL")
elseif(OpenCL_HPP_INCLUDE_DIR)
    # Append OpenCL CPP headers to C headers and use both
    set(OpenCL_HEADERS ${OpenCL_INCLUDE_DIR} ${OpenCL_HPP_INCLUDE_DIR})
    set(OpenCL_LIB "OpenCL::OpenCL")
endif()

if(OpenCL_FOUND AND OpenCL_HEADERS)
    target_link_libraries(${TARGET_NAME} PRIVATE ${OpenCL_LIB})
    target_include_directories(${TARGET_NAME} PRIVATE ${OpenCL_HEADERS})
    target_compile_definitions(${TARGET_NAME} PRIVATE HAVE_GPU_DEVICE_MEM_SUPPORT)
endif()

# Optional OpenCV dependnency

find_package(OpenCV COMPONENTS core QUIET)
if(NOT OpenCV_FOUND)
    message(WARNING "OpenCV is disabled or not found, ${TARGET_NAME} will be built without OpenCV support. Set OpenCV_DIR")
else()
    target_compile_definitions(${TARGET_NAME} PRIVATE USE_OPENCV)
    target_link_libraries(${TARGET_NAME} PRIVATE opencv_core)
endif()