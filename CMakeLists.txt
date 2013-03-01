#
# CMake build script for perseid.
#
########################################################################
#                                                                      #
# This file is part of perseid.                                        #
#                                                                      #
# perseid is free software: you can redistribute it and/or modify      #
# it under the terms of the GNU General Public License as published by #
# the Free Software Foundation, either version 3 of the License, or    #
# (at your option) any later version.                                  #
#                                                                      #
# perseid is distributed in the hope that it will be useful,           #
# but WITHOUT ANY WARRANTY; without even the implied warranty of       #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        #
# GNU General Public License for more details.                         #
#                                                                      #
# You should have received a copy of the GNU General Public License    #
# along with perseid.  If not, see <http://www.gnu.org/licenses/>.     #
#                                                                      #
########################################################################
#

cmake_minimum_required(VERSION 2.6)

########
# Main #
########

project(perseid)

set(TESTING "NONE" CACHE STRING "NONE")
set(COVERAGE "NONE" CACHE STRING "NONE")

set(PERSEID_NAME perseid)
set(PERSEID_LIB perseid)
set(PERSEID_SOURCE_DIR src)
set(PERSEID_INCLUDE_DIR include)
set(PERSEID_TEST_DIR test/src)

find_package(Qt4 REQUIRED)
include_directories(
  ${PERSEID_INCLUDE_DIR}
  ${QT_INCLUDES}
  ${CMAKE_CURRENT_BINARY_DIR}
)

add_library(${PERSEID_LIB}
  ${PERSEID_SOURCE_DIR}/io/IOException.cpp
  ${PERSEID_SOURCE_DIR}/io/TransformationException.cpp
  ${PERSEID_SOURCE_DIR}/io/XmlTransformer.cpp
  ${PERSEID_SOURCE_DIR}/model/Review.cpp
  ${PERSEID_SOURCE_DIR}/util/Exception.cpp
}

set(PERSEID_SRCS
  ${PERSEID_SOURCE_DIR}/perseid.cpp
  ${PERSEID_SOURCE_DIR}/main.cpp
)
qt4_automoc(${PERSEID_SRCS})
add_executable(
  ${PERSEID_NAME}
  ${PERSEID_SRCS}
)
target_link_libraries(
  ${PERSEID_NAME}
  ${PERSEID_LIB}
  ${QT_QTCORE_LIBRARY}
  ${QT_QTGUI_LIBRARY}
)
#install(TARGETS perseid RUNTIME DESTINATION bin)

