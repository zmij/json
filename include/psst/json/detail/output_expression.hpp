/*
 * output_expression.hpp
 *
 *  Created on: Dec 19, 2018
 *      Author: ser-fedorov
 */

#ifndef PSST_JSON_DETAIL_OUTPUT_EXPRESSION_HPP_
#define PSST_JSON_DETAIL_OUTPUT_EXPRESSION_HPP_

#include <string>

namespace psst::json {
namespace detail {

template < typename T, typename CharT, typename CharTraits = std::char_traits<CharT> >
struct basic_output_expression_base {

};

}  // namespace detail

template < typename T, typename CharT, typename CharTraits, typename U >
auto
operator << (detail::basic_output_expression_base<T, CharT, CharTraits>& exp,
    U const& val)
{

}

}  // namespace psst::json



#endif /* PSST_JSON_DETAIL_OUTPUT_EXPRESSION_HPP_ */
