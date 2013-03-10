/**
 *  @file ReviewTest.cpp
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
#define BOOST_TEST_MODULE ModelTests

#include <boost/test/unit_test.hpp>
#include "perseid/model/Review.hpp"

#define message "hello world\nhello again"

using perseid::Review;

struct ReviewTest {
  ReviewTest() {
    testReview = new Review();
  }
  virtual ~ReviewTest() {
    delete testReview;
  }
  Review * testReview;
};

BOOST_FIXTURE_TEST_SUITE(ReviewTests, ReviewTest)

/**
 * Tests whether the abstract getter and setter work correctly.
 */
BOOST_AUTO_TEST_CASE(AbstractTest) {
  string expected = message;
  testReview->setAbstract(expected);
  BOOST_CHECK_EQUAL(expected, testReview->getAbstract());
}

/**
 * Tests whether the authorID getter and setter work correctly.
 */
BOOST_AUTO_TEST_CASE(AuthorIDTest) {
  int expected = 64673;
  testReview->setAuthorID(expected);
  BOOST_CHECK_EQUAL(expected, testReview->getAuthorID());
}

/**
 * Tests whether the comments getter and setter work correctly.
 */
BOOST_AUTO_TEST_CASE(CommentsTest) {
  string expected = message;
  testReview->setComments(expected);
  BOOST_CHECK_EQUAL(expected, testReview->getComments());
}

/**
 * Tests whether the name getter and setter work correctly.
 */
BOOST_AUTO_TEST_CASE(NameTest) {
  string expected = message;
  testReview->setName(expected);
  BOOST_CHECK_EQUAL(expected, testReview->getName());
}

/**
 * Tests whether the paperID getter and setter work correctly.
 */
BOOST_AUTO_TEST_CASE(PaperIDTest) {
  int expected = 64673;
  testReview->setPaperID(expected);
  BOOST_CHECK_EQUAL(expected, testReview->getPaperID());
}

/**
 * Tests whether the summary getter and setter work correctly.
 */
BOOST_AUTO_TEST_CASE(SummaryTest) {
  string expected = message;
  testReview->setSummary(expected);
  BOOST_CHECK_EQUAL(expected, testReview->getSummary());
}

/**
 * Tests whether the default constructor works correctly.
 */
BOOST_AUTO_TEST_CASE(DefaultConstuctorTest) {
  BOOST_CHECK_EQUAL("", testReview->getAbstract());
  BOOST_CHECK_EQUAL(-1, testReview->getAuthorID());
  BOOST_CHECK_EQUAL("", testReview->getComments());
  BOOST_CHECK_EQUAL("", testReview->getName());
  BOOST_CHECK_EQUAL(-1, testReview->getPaperID());
  BOOST_CHECK_EQUAL("", testReview->getSummary());
}

/**
 * Tests whether the copy constructor works correctly.
 */
BOOST_AUTO_TEST_CASE(CopyConstuctorTest) {
  testReview->setAbstract("a");
  testReview->setAuthorID(1);
  testReview->setComments("b");
  testReview->setName("c");
  testReview->setPaperID(2);
  testReview->setSummary("d");
  
  Review copy(*testReview);
  BOOST_CHECK_EQUAL("a", copy.getAbstract());
  BOOST_CHECK_EQUAL(1, copy.getAuthorID());
  BOOST_CHECK_EQUAL("b", copy.getComments());
  BOOST_CHECK_EQUAL("c", copy.getName());
  BOOST_CHECK_EQUAL(2, copy.getPaperID());
  BOOST_CHECK_EQUAL("d", copy.getSummary());
}

/**
 * Tests whether the assignment operator works correctly.
 */
BOOST_AUTO_TEST_CASE(AssignmentOperatorTest) {
  testReview->setAbstract("a");
  testReview->setAuthorID(1);
  testReview->setComments("b");
  testReview->setName("c");
  testReview->setPaperID(2);
  testReview->setSummary("d");

  Review copy;
  copy = *testReview;
  BOOST_CHECK_EQUAL("a", copy.getAbstract());
  BOOST_CHECK_EQUAL(1, copy.getAuthorID());
  BOOST_CHECK_EQUAL("b", copy.getComments());
  BOOST_CHECK_EQUAL("c", copy.getName());
  BOOST_CHECK_EQUAL(2, copy.getPaperID());
  BOOST_CHECK_EQUAL("d", copy.getSummary());
}

/**
 * Tests whether the equals method works correctly.
 */
BOOST_AUTO_TEST_CASE(EqualsTest) {
  Review copy(*testReview);
  BOOST_CHECK(copy.equals(testReview));
  
  testReview->setAbstract("a");
  BOOST_CHECK(!copy.equals(testReview));
  copy.setAbstract("a");
  BOOST_CHECK(copy.equals(testReview));

  testReview->setAuthorID(1);
  BOOST_CHECK(!copy.equals(testReview));
  copy.setAuthorID(1);
  BOOST_CHECK(copy.equals(testReview));

  testReview->setComments("b");
  BOOST_CHECK(!copy.equals(testReview));
  copy.setComments("b");
  BOOST_CHECK(copy.equals(testReview));

  testReview->setName("c");
  BOOST_CHECK(!copy.equals(testReview));
  copy.setName("c");
  BOOST_CHECK(copy.equals(testReview));

  testReview->setPaperID(2);
  BOOST_CHECK(!copy.equals(testReview));
  copy.setPaperID(2);
  BOOST_CHECK(copy.equals(testReview));

  testReview->setSummary("d");
  BOOST_CHECK(!copy.equals(testReview));
  copy.setSummary("d");
  BOOST_CHECK(copy.equals(testReview));
}

/**
 * Tests whether the equals operators works correctly.
 */
BOOST_AUTO_TEST_CASE(EqualsOperatorTest) {
  Review copy(*testReview);
  BOOST_CHECK(copy == *testReview);
  BOOST_CHECK(!(copy != *testReview));

  testReview->setAbstract("a");
  BOOST_CHECK(copy != *testReview);
  BOOST_CHECK(!(copy == *testReview));
  copy.setAbstract("a");
  BOOST_CHECK(copy == *testReview);

  testReview->setAuthorID(1);
  BOOST_CHECK(copy != *testReview);
  copy.setAuthorID(1);
  BOOST_CHECK(copy == *testReview);

  testReview->setComments("b");
  BOOST_CHECK(copy != *testReview);
  copy.setComments("b");
  BOOST_CHECK(copy == *testReview);

  testReview->setName("c");
  BOOST_CHECK(copy != *testReview);
  copy.setName("c");
  BOOST_CHECK(copy == *testReview);

  testReview->setPaperID(2);
  BOOST_CHECK(copy != *testReview);
  copy.setPaperID(2);
  BOOST_CHECK(copy == *testReview);

  testReview->setSummary("d");
  BOOST_CHECK(copy != *testReview);
  copy.setSummary("d");
  BOOST_CHECK(copy == *testReview);
}

BOOST_AUTO_TEST_SUITE_END()
