/**
 *  @file ExceptionTest.cpp
 *  @author William Martin <will.st4@gmail.com>
 *  @since 0.0
 *
 *  @section LICENCE
 *
 *  Perseid is a graphical paper review system that gives the user control
 *  of their data through a transparent xml standard.
 *  Copyright (C) 2013  William Martin <will.st4@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE UtilTests

#include <boost/test/unit_test.hpp>
#include "perseid/util/Exception.hpp"

#define message "test message"

using perseid::Exception;

struct ExceptionTest {
  ExceptionTest() {
    testException = new Exception(message);
  }
  virtual ~ExceptionTest() {
    delete testException;
  }
  Exception * testException;
};

BOOST_FIXTURE_TEST_SUITE(ExceptionTests, ExceptionTest)

/**
 * Tests whether the Exception's message was set correctly.
 */
BOOST_AUTO_TEST_CASE(MessageTest) {
  BOOST_CHECK_EQUAL(message, testException->what());
}

BOOST_AUTO_TEST_SUITE_END()
