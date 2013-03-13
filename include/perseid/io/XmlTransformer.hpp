/**
 *  @file XmlTransformer.hpp
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

#ifndef XMLTRANSFORMER_HPP
#define XMLTRANSFORMER_HPP

#include "perseid/io/Transformer.hpp"

namespace perseid {

/**
 * Transforms a Review to and from XML.
 */
class XmlTransformer : public perseid::Transformer {
public:
  /**
   * Default constructor.
   */
  XmlTransformer();
  /**
   * Default destructor.
   */
  virtual ~XmlTransformer();
  /**
   * {@inheritdoc}
   */
  virtual Review input(string const & filename)
  throw (IOException, TransformationException);
  /**
   * {@inheritdoc}
   */
  virtual void output(Review const & review, string const & filename)
  throw (IOException);
};

};

#endif // XMLTRANSFORMER_HPP
