/*
    Perseid is a graphical paper review system that gives the user control
    of their data through a transparent xml standard.
    Copyright (C) 2013  William Martin <will.st4@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef REVIEW_HPP
#define REVIEW_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace perseid {

class Review {
public:
  /**
   * Default constructor.
   */
  Review();
  /**
   * Copy constructor.
   *
   * @param other the Review to copy.
   */
  Review(const Review& other);
  /**
   * Deletes this Review.
   */
  virtual ~Review();
  /**
   * Copies the given Review to this Review.
   */
  virtual Review& operator=(const Review& other);
  /**
   * Checks if the given Review is equal to this Review.
   *
   * @param other the Review to compare to.
   * @returns true if the given Review is equal to this Review, false 
   * otherwise.
   */
  bool operator==(const Review& other) const;
  /**
   * Checks if the given Review is not equal to this Review.
   *
   * @param other the Review to compare to.
   * @returns false if the given Review is equal to this Review, true
   * otherwise.
   */
  bool operator!=(const Review& other) const;
  /**
   * Checks if the given Review is equal to this Review.
   *
   * @param other the Review to compare to.
   * @returns true if the given Review is equal to this Review, false 
   * otherwise.
   */
  virtual bool const equals(Review const * const other) const;
  /**
   * Gets the abstract.
   *
   * @returns the abstract.
   */
  string const getAbstract() const;
  /**
   * Sets the abstract.
   *
   * @param abstract the abstract.
   */
  void setAbstract(string const & abstract);
  /**
   * Gets the Author identification number.
   *
   * @returns the Author identification number.
   */
  int const getAuthorID() const;
  /**
   * Sets the Author identification number.
   *
   * @param authorID the Author identification number.
   */
  void setAuthorID(int const & authorID);
  /**
   * Gets the comments.
   *
   * @returns the comments.
   */
  string const getComments() const;
  /**
   * Sets the comments.
   *
   * @param comments the comments.
   */
  void setComments(string const & comments);
  /**
   * Gets the name for this Review.
   *
   * @returns the name for this Review.
   */
  string const getName() const;
  /**
   * Sets the name for this Review.
   *
   * @param name the name for this Review.
   */
  void setName(string const & name);
  /**
   * Gets the Paper identification number.
   *
   * @returns the Paper identification number.
   */
  int const getPaperID() const;
  /**
   * Sets the Paper identification number.
   *
   * @param paperID the Paper identification number.
   */
  void setPaperID(int const & paperID);
  /**
   * Gets the summary.
   *
   * @returns the summary.
   */
  string const getSummary() const;
  /**
   * Sets the summary.
   *
   * @param summary the summary.
   */
  void setSummary(string const & summary);
private:
  string abstract;
  int authorID;
  string comments;
  string name;
  int paperID;
  string summary;
};

};

#endif // REVIEW_HPP
