/**
 *  @file TransformationExceptionTest.hpp
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

#ifndef TRANSFORMATIONEXCEPTIONTEST_HPP
#define TRANSFORMATIONEXCEPTIONTEST_HPP

#include "perseid/util/Exception.hpp"
#include <QObject>

#define message "test message"

using perseid::Exception;

class TransformationExceptionTest: public QObject
{
  Q_OBJECT
public:
  TransformationExceptionTest(QObject* parent = 0) {
    testException = new TransformationException(message);
  }
  virtual ~ExceptionTest() {
    delete testException;
  }
private:
  TransformationException * testException;
private slots:
  void messageTest();
};

#endif