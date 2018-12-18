/*
 * parser.hpp
 *
 *  Created on: 24 мая 2016 г.
 *      Author: sergey.fedorov
 */

#ifndef PSST_JSON_PARSER_HPP_
#define PSST_JSON_PARSER_HPP_

#include <psst/json/traits.hpp>
#include <psst/json/detail/parser_base.hpp>
#include <psst/json/detail/streamable_parser.hpp>
#include <psst/json/detail/integral_parser.hpp>
#include <psst/json/detail/floating_parser.hpp>
#include <psst/json/detail/object_parser.hpp>

//#include <psst/json/detail/map_parser.hpp>

namespace psst::json::__1 {

namespace detail {

template < traits::value_type, typename T, typename CharT,
    typename Traits = std::char_traits<CharT> >
struct basic_parser_impl;

template < typename CharT, typename Traits >
struct basic_parser_impl< traits::value_type::boolean, bool, CharT, Traits >
        : basic_boolean_parser<CharT, Traits> {
    using base_type = basic_boolean_parser<CharT, Traits>;
    basic_parser_impl(bool& val) : base_type{val} {}
};

template < typename T, typename CharT, typename Traits >
struct basic_parser_impl<traits::value_type::integral, T, CharT, Traits>
        : basic_integral_parser< T, CharT, Traits > {
    using base_type = basic_integral_parser< T, CharT, Traits >;
    basic_parser_impl(T& val) : base_type{val} {}
};

template < typename T, typename CharT, typename Traits >
struct basic_parser_impl<traits::value_type::floating, T, CharT, Traits>
        : basic_floating_parser< T, CharT, Traits > {
    using base_type = basic_floating_parser< T, CharT, Traits >;
    basic_parser_impl(T& val) : base_type{val} {}
};

template < typename T, typename CharT, typename Traits >
struct basic_parser_impl< traits::value_type::string, T, CharT, Traits >
        : basic_streamable_object_parser< T, CharT, Traits > {
    using base_type = basic_streamable_object_parser< T, CharT, Traits >;
    basic_parser_impl(T& val) : base_type{val} {}
};

//// FIXME Use a generic object parser
template < typename T, typename CharT, typename Traits >
struct basic_parser_impl< traits::value_type::object, T, CharT, Traits >
        : basic_object_parser< CharT, Traits > {
    using base_type = basic_object_parser< CharT, Traits >;
    basic_parser_impl(T& /*val*/) : base_type{} {}
};

}  /* namespace detail */

template < typename T, typename CharT, typename Traits >
struct basic_parser
        : detail::basic_parser_impl< traits::json_type< T >::value, T, CharT, Traits > {
    using base_type = detail::basic_parser_impl< traits::json_type< T >::value, T, CharT, Traits >;
    basic_parser(T& val) : base_type{val} {}
};

}  // namespace psst::json::_1

#endif /* PSST_JSON_PARSER_HPP_ */
