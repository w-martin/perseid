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

set(BUILD "ALL" CACHE STRING "ALL")
set(TESTING "NONE" CACHE STRING "NONE")
set(COVERAGE "NONE" CACHE STRING "NONE")

set(PERSEID_NAME perseid)
set(PERSEID_LIB perseidcore)
set(PERSEID_SOURCE_DIR src)
set(PERSEID_INCLUDE_DIR include)
set(PERSEID_TEST_DIR test/src)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

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
)

###########
# Testing #
###########

message("-- Testing mode: ${TESTING}")

IF(("FAST" STREQUAL TESTING) OR ("ALL" STREQUAL TESTING))

  message("-- Tests enabled.")
  enable_testing(true)
  include_directories(
    ${PERSEID_MOCK_DIR}
  )

  #################
  # Code coverage #
  #################

  message("-- Coverage mode: ${COVERAGE}")
  
  IF(("LCOV" STREQUAL COVERAGE) OR ("COBERTURA" STREQUAL COVERAGE))
    SET(CMAKE_BUILD_TYPE "Debug")
    IF(NOT CMAKE_COMPILER_IS_GNUCXX)
      message("-- Compiler not GNU, cannot create coverage report.")
    ELSE()
      FIND_PROGRAM(PYTHON_EXECUTABLE
        NAMES python python3
        PATHS /usr/bin /usr/local/bin /usr/pkg/bin
      )
      include(CodeCoverage)
      message("-- Code coverage enabled.")

      IF("LCOV" STREQUAL COVERAGE)
        SETUP_TARGET_FOR_COVERAGE(coverage ctest coverage)
      ELSE()
        SETUP_TARGET_FOR_COVERAGE_COBERTURA(coverage ctest coverage)
      ENDIF()
    ENDIF()
  ENDIF()

  SET(UtilTests_SRCS
    ${PERSEID_TEST_DIR}/util/ExceptionTest.cpp
  )
  QT4_AUTOMOC(${UtilTests_SRCS})
  add_executable(UtilTests
    ${UtilTests_SRCS}
  )
  target_link_libraries(UtilTests
    ${QT_QTTEST_LIBRARY}
    ${QT_LIBRARIES}
    ${PERSEID_LIB}
  )
  add_test(UtilTests UtilTests)
ENDIF()

IF("ALL" STREQUAL TESTING)
  message("-- Integration tests enabled.")
  set(IntegrationTests_SRCS
    ${PERSEID_TEST_DIR}/integration/IntegrationTests.cpp
  )
  QT4_AUTOMOC(${IntegrationTests_SRCS})
  add_executable(IntegrationTests
    ${IntegrationTests_SRCS}
  )
  target_link_libraries(IntegrationTests
    ${PERSEID_LIB}
    ${QT_QTTEST_LIBRARY}
    ${QT_LIBRARIES}
  )
  add_test(IntegrationTests IntegrationTests)
ENDIF()

IF("EXECUTABLE" STREQUAL ${BUILD} OR "ALL" STREQUAL ${BUILD})
  message("-- Executable enabled.")
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
ENDIF()

