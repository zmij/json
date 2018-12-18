/*
 * json_stream_fwd.hpp
 *
 *  Created on: 5 нояб. 2016 г.
 *      Author: sergey.fedorov
 */

#ifndef PSST_JSON_JSON_STREAM_FWD_HPP_
#define PSST_JSON_JSON_STREAM_FWD_HPP_

#include <string>

namespace psst::json {
template <typename CharT, typename Traits = std::char_traits<CharT>>
class basic_ostream;

using ostream = basic_ostream<char>;
using wostream = basic_ostream<wchar_t>;

template <typename CharT, typename Traits = std::char_traits<CharT>>
class basic_istream;

using istream = basic_istream<char>;
using wistream = basic_istream<wchar_t>;

// below is deprecated
namespace __1 {

template < typename CharT, typename Traits = std::char_traits<CharT> >
class basic_json_ostream;

using json_ostream  = basic_json_ostream<char>;
using wjson_ostream = basic_json_ostream<wchar_t>;

template < typename CharT, typename Traits = std::char_traits<CharT> >
class basic_json_istream;

using json_istream  = basic_json_istream<char>;
using wjson_istream = basic_json_istream<wchar_t>;

}  // namespace __1

}  // namespace psst::json

#endif /* PSST_JSON_JSON_STREAM_FWD_HPP_ */
