/**
 *  @file XmlTransformer.cpp
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

#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <fstream>
#include "perseid/io/XmlTransformer.hpp"

using boost::filesystem::exists;
using boost::format;
    using boost::property_tree::ptree;

perseid::XmlTransformer::XmlTransformer() {

}

perseid::XmlTransformer::~XmlTransformer() {

}

Review perseid::XmlTransformer::input(string const & filename)
throw (IOException, TransformationException) {

  if(!exists(filename)){
    throw IOException(format("Error. %1 does not exist.") % filename);
  }

  ptree pt;
  std::ifstream is(filename.c_str());
  read_xml(is, pt);
  is.close();

  Review review;
  ptree::value_type const& v = pt.get("review");
  review.setAbstract(v.second.get<string>("abstract"));
  review.setAuthorID(v.);
  
  return review;
}

void perseid::XmlTransformer::output(Review const & review,
                                     string const & filename)
throw (IOException) {

}

Sked read( std::istream & is )
{
    ptree pt;
    read_xml(is, pt);

    // traverse pt
    Sked ans;
    BOOST_FOREACH( ptree::value_type const& v, pt.get_child("sked") ) {
        if( v.first == "flight" ) {
            Flight f;
            f.carrier = v.second.get<std::string>("carrier");
            f.number = v.second.get<unsigned>("number");
            f.date = v.second.get<Date>("date");
            f.cancelled = v.second.get("<xmlattr>.cancelled", false);
            ans.push_back(f);
        }
    }

    return ans;
}
