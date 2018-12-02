/*
 * json_stream_fwd.hpp
 *
 *  Created on: 5 нояб. 2016 г.
 *      Author: sergey.fedorov
 */

#ifndef ZMIJ_JSON_JSON_STREAM_FWD_HPP_
#define ZMIJ_JSON_JSON_STREAM_FWD_HPP_

#include <string>

namespace zmij {
namespace json {

template < typename CharT, typename Traits = ::std::char_traits<CharT> >
class basic_json_ostream;

using json_ostream  = basic_json_ostream<char>;
using wjson_ostream = basic_json_ostream<wchar_t>;

template < typename CharT, typename Traits = ::std::char_traits<CharT> >
class basic_json_istream;

using json_istream  = basic_json_istream<char>;
using wjson_istream = basic_json_istream<wchar_t>;

}  /* namespace json */
}  /* namespace zmij */

#endif /* ZMIJ_JSON_JSON_STREAM_FWD_HPP_ */
