/*
 * has_io_operator.hpp
 *
 *  Created on: 22 мая 2016 г.
 *      Author: sergey.fedorov
 */

#ifndef PSST_JSON_UTIL_HAS_IO_OPERATOR_HPP_
#define PSST_JSON_UTIL_HAS_IO_OPERATOR_HPP_

#include <iosfwd>
#include <type_traits>
#include <utility>

namespace psst::json::util {

//@{
template < typename T, typename CharT = char,
        typename CharTraits = std::char_traits<CharT>,
        typename = std::void_t<> >
struct has_input_operator : std::false_type {};
template < typename T, typename CharT, typename CharTraits >
struct has_input_operator< T, CharT, CharTraits,
  std::void_t<decltype(
      std::declval<std::basic_istream<CharT, CharTraits>&>() >> std::declval<T&>()
  )> >
    : std::true_type {};
template < typename T, typename CharT = char,
    typename CharTraits = std::char_traits<CharT> >
constexpr bool has_input_operator_v = has_input_operator<T, CharT, CharTraits>::value;
//@}

//@{
template < typename T, typename CharT = char,
    typename CharTraits = std::char_traits<CharT>,
    typename = std::void_t<> >
struct has_output_operator : std::false_type {};
template < typename T, typename CharT, typename CharTraits >
struct has_output_operator< T, CharT, CharTraits,
  std::void_t<decltype(
      std::declval<std::basic_ostream<CharT, CharTraits>&>() << std::declval<T const&>()
  )> >
    : std::true_type {};
template < typename T, typename CharT = char,
    typename CharTraits = std::char_traits<CharT> >
constexpr bool has_output_operator_v = has_output_operator<T, CharT, CharTraits>::value;
//@}

//@{
template < typename T, typename CharT = char,
    typename CharTraits = std::char_traits<CharT> >
struct has_iostream_operators
    : std::integral_constant<bool,
        has_input_operator_v<T, CharT, CharTraits> &&
        has_output_operator_v<T, CharT, CharTraits>> {};

template < typename T, typename CharT = char,
    typename CharTraits = std::char_traits<CharT> >
constexpr bool has_iostream_operators_v =
      has_iostream_operators<T, CharT, CharTraits>::value;
//@}

template <>
struct has_input_operator< std::nullptr_t > : ::std::false_type{};
template <>
struct has_output_operator< std::nullptr_t > : ::std::false_type{};

}  // namespace psst::json::util


#endif /* PSST_JSON_UTIL_HAS_IO_OPERATOR_HPP_ */
