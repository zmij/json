/*
 * container_output.hpp
 *
 *  Created on: 5 нояб. 2016 г.
 *      Author: sergey.fedorov
 */

#ifndef PSST_JSON_DETAIL_CONTAINER_OUTPUT_HPP_
#define PSST_JSON_DETAIL_CONTAINER_OUTPUT_HPP_

#include <psst/json/json_stream.hpp>

namespace psst::json::__1 {

template < typename CharT, typename Traits, typename T, typename ... Rest >
basic_json_ostream<CharT, Traits>&
json_write(basic_json_ostream<CharT, Traits>& os, std::vector<T, Rest...> const& v)
{
    for (auto const& e : v) {
        os << e;
    }
    return os;
}

}  // namespace psst::json

#endif /* PSST_JSON_DETAIL_CONTAINER_OUTPUT_HPP_ */
