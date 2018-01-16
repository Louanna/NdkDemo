
#
# Copyright (C) The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#aux_source_directory(${CMAKE_HOME_DIRECTORY}/src/api SRC_LIST)
#aux_source_directory(${CMAKE_HOME_DIRECTORY}/src/core CORE_SRC_LIST)
#list(APPEND SRC_LIST ${CORE_SRC_LIST})
#add_library(native-lib SHARED ${SRC_LIST})


set(SRC_FILES file1.c file2.c)

add_library(One STATIC ${SRC_FILES})

# copy out the lib binary... need to leave the static lib around to pass gradle check

set(STATIC_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(One
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY
                      "${STATIC_LIB_DIR}/lib/${ANDROID_ABI}")

# copy out lib header file...
add_custom_command(TARGET One POST_BUILD
                   COMMAND "${CMAKE_COMMAND}" -E
                   copy "${CMAKE_CURRENT_SOURCE_DIR}/file1.h"
                   "${STATIC_LIB_DIR}/headers/file1.h"
                   COMMAND "${CMAKE_COMMAND}" -E
                   copy "${CMAKE_CURRENT_SOURCE_DIR}/file2.h"
                    "${STATIC_LIB_DIR}/headers/file2.h")

# configure import libs
add_library(lib_One STATIC IMPORTED)
set_target_properties(lib_One
                      PROPERTIES IMPORTED_LOCATION
                      ${STATIC_LIB_DIR}/lib/${ANDROID_ABI}/libOne.a)

# build application's shared lib
add_library(one-lib SHARED ${STATIC_LIB_DIR}/../one-lib.cpp)

target_include_directories(one-lib
                           PRIVATE
                           ${STATIC_LIB_DIR}/headers)

target_link_libraries(one-lib
                      android
                      lib_One
                      log)
