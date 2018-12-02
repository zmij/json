/*
 * json_stream.cpp
 *
 *  Created on: 4 нояб. 2016 г.
 *      Author: sergey.fedorov
 */

#include <zmij/json/json_stream.hpp>

namespace zmij::json {

template class basic_json_ostream<char>;
template class basic_json_ostream<wchar_t>;

template class basic_json_istream<char>;
template class basic_json_istream<wchar_t>;

}  // namespace zmij::json
