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


#include "perseid/model/Review.hpp"

using perseid::Review;

perseid::Review::Review() {
  abstract = "";
  author = "-1""";
  comments = "";
  name = "";
  summary = "";
}

perseid::Review::Review(const Review& other) {
  author = other.getAuthor();
  abstract = other.getAbstract();
  comments = other.getComments();
  name = other.getName();
  summary = other.getSummary();
}

perseid::Review::~Review() {

}

Review& perseid::Review::operator=(const Review& other) {
  author = other.getAuthor();
  abstract = other.getAbstract();
  comments = other.getComments();
  name = other.getName();
  summary = other.getSummary();
  return *this;
}

bool perseid::Review::operator==(const Review& other) const {
  return equals(&other);
}

bool perseid::Review::operator!=(const Review& other) const {
  return !equals(&other);
}

bool const perseid::Review::equals(Review const * const other) const {
  return (author == other->getAuthor()
          && abstract == other->getAbstract()
          && comments == other->getComments()
          && name == other->getName()
          && summary == other->getSummary()
         );
}

string const perseid::Review::getAbstract() const {
  return abstract;
}

void perseid::Review::setAbstract(string const & abstract) {
  this->abstract = abstract;
}

string const perseid::Review::getAuthor() const {
  return author;
}

void perseid::Review::setAuthor(string const & author) {
  this->author = author;
}

string const perseid::Review::getComments() const {
  return comments;
}

void perseid::Review::setComments(string const & comments) {
  this->comments = comments;
}

string const perseid::Review::getName() const {
  return name;
}

void perseid::Review::setName(string const & name) {
  this->name = name;
}

string const perseid::Review::getSummary() const {
  return summary;
}

void perseid::Review::setSummary(string const & summary) {
  this->summary = summary;
}
