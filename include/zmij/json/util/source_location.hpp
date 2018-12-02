/*
 * source_location.hpp
 *
 *  Created on: 18 апр. 2016 г.
 *      Author: sergey.fedorov
 */

#ifndef ZMIJ_JSON_UTIL_SOURCE_LOCATION_HPP_
#define ZMIJ_JSON_UTIL_SOURCE_LOCATION_HPP_

#include <string>
#include <cstdint>
#include <iostream>

namespace zmij {
namespace idl {

struct source_location {
    ::std::string file;
    ::std::size_t line;
    ::std::size_t character;
};

inline ::std::ostream&
operator << (::std::ostream& os, source_location const& val)
{
    ::std::ostream::sentry s(os);
    if (s) {
        os << val.file << ":" << val.line << ":" << val.character;
    }
    return os;
}

}  /* namespace idl */
}  /* namespace zmij */


#endif /* ZMIJ_JSON_UTIL_SOURCE_LOCATION_HPP_ */
