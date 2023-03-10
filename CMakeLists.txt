# PARTIO SOFTWARE
# Copyright 2010 Disney Enterprises, Inc. All rights reserved
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
# 
# * Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
# 
# * Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in
# the documentation and/or other materials provided with the
# distribution.
# 
# * The names "Disney", "Walt Disney Pictures", "Walt Disney Animation
# Studios" or the names of its contributors may NOT be used to
# endorse or promote products derived from this software without
# specific prior written permission from Walt Disney Pictures.
# 
# Disclaimer: THIS SOFTWARE IS PROVIDED BY WALT DISNEY PICTURES AND
# CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
# BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE, NONINFRINGEMENT AND TITLE ARE DISCLAIMED.
# IN NO EVENT SHALL WALT DISNEY PICTURES, THE COPYRIGHT HOLDER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND BASED ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test_mypartio)

file(GLOB io_cpp "io/*.cpp")
file(GLOB core_cpp "core/*.cpp")

add_library(mypartio  ${io_cpp} ${core_cpp})
set_target_properties(mypartio PROPERTIES
    OUTPUT_NAME mypartio
    POSITION_INDEPENDENT_CODE ON
)


IF(MSVC)
  target_compile_definitions(mypartio 
  PUBLIC 
    PARTIO_WIN32=1
    _USE_MATH_DEFINES=1
    )
    target_compile_options(mypartio 
    PUBLIC 
      /W0)
  # ADD_DEFINITIONS (-DPARTIO_WIN32 -D_USE_MATH_DEFINES)
  # set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W0")
ELSE(MSVC)
  target_compile_options(mypartio 
  PUBLIC  
    -Wextra 
    -Wno-unused-parameter
    -fPIC
    -w)
  # ADD_DEFINITIONS (-Wextra -Wno-unused-parameter)
  # SET( CMAKE_CXX_FLAGS "-fPIC -w")
ENDIF(MSVC)

target_compile_definitions(mypartio 
PUBLIC 
  PARTIO_USE_ZLIB=1)
# ADD_DEFINITIONS (-DPARTIO_USE_ZLIB)


target_include_directories(mypartio
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    )

find_package(ZLIB REQUIRED)
if (ZLIB_FOUND)
    target_link_libraries(mypartio PUBLIC ZLIB::ZLIB)
endif()
# target_include_directories(mypartio PRIVATE ../zlib/src)


option(TEST_MYPARTIO "test my partio" ON)
if(TEST_MYPARTIO)

    enable_testing()

    file(GLOB data_files "${CMAKE_CURRENT_SOURCE_DIR}/tests/data/*")
    message(STATUS "Copying data_files: ${data_files}")

    # ?????????????????????????????????????????????addtest(name)??????
    function(addtest testname)
        add_executable(test_${testname} tests/test_${testname}.cpp)
        target_include_directories(test_${testname} PRIVATE src)
        target_link_libraries(test_${testname} mypartio)
        add_test(NAME test_${testname} COMMAND test_${testname})

        add_custom_command(TARGET test_${testname} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${data_files}
            $<TARGET_FILE_DIR:test_${testname}>)

      endfunction(addtest)
          
      #?????????????????????
      addtest(mypartio)
      addtest(iterator)
      addtest(heapdata)
      
endif()
