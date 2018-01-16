
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

# configure import libs

add_library(lib_two STATIC IMPORTED)

set_target_properties(lib_two
                      PROPERTIES IMPORTED_LOCATION
                      ${CMAKE_CURRENT_SOURCE_DIR}/lib/${ANDROID_ABI}/libOne.a)

# build application's shared lib

add_library(two-lib SHARED ${CMAKE_CURRENT_SOURCE_DIR}/../two-lib.cpp)

target_include_directories(two-lib
                           PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/headers)

target_link_libraries(two-lib
                      android
                      lib_two
                      log)
