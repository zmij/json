/*
 * json_stream.cpp
 *
 *  Created on: 4 нояб. 2016 г.
 *      Author: sergey.fedorov
 */

#include <psst/json/basic_ostream.hpp>

namespace psst::json {

template class basic_ostream<char>;
template class basic_ostream<wchar_t>;

}  // namespace psst::json

// below is deprecated
#include <psst/json/json_stream.hpp>

namespace psst::json::__1 {

template class basic_json_ostream<char>;
template class basic_json_ostream<wchar_t>;

template class basic_json_istream<char>;
template class basic_json_istream<wchar_t>;

}  // namespace psst::json
