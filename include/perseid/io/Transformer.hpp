/*
  @file Transformer.hpp
  @author William Martin <will.st4@gmail.com>
  @since 0.0
    
  @section LICENCE
    
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

#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP

#include <string>
#include "perseid/model/Review.hpp"

using std::string;
using perseid::Review;

namespace perseid {

  /**
   * Interface for converting between Review objects and files.
   */
  class Transformer {
  public:
    /**
     * Inputs the given file and transforms it into a Review object.
     * 
     * @param filename the name of the file to transform.
     * @returns the input Review.
     * @throws TransformationException if there was an error reading the 
     * Review.
     */
    virtual Review input(string const & filename) 
      throw (TransformationException) = 0;
    
    /**
     * Writes the given review to the given file.
     * 
     * @param review the Review to write.
     * @param filename the name of the file to write to.
     * @throws IOException if there was an error writing the Review.
     */
    virtual void output(Review const * const review, string const & filename) 
      throw (IOException) = 0;
  };

};

#endif // TRANSFORMER_HPP

