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

namespace perseid {

  class Review {
  public:
    Review();
    Review(const Review& other);
    virtual ~Review();
    virtual Review& operator=(const Review& other);
    virtual bool operator==(const Review& other) const;
  };

};

#endif // REVIEW_HPP
