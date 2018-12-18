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

template < typename T, typename = std::void_t<> >
struct has_input_operator : std::false_type {};
template < typename T >
struct has_input_operator< T,
  std::void_t<decltype(
      std::declval<std::istream&>() >> std::declval<T&>()
  )> >
    : std::true_type {};
template < typename T >
constexpr bool has_input_operator_v = has_input_operator<T>::value;

template < typename T, typename = std::void_t<> >
struct has_output_operator : std::false_type {};
template < typename T >
struct has_output_operator< T,
  std::void_t<decltype(
      std::declval<std::ostream&>() << std::declval<T const&>()
  )> >
    : std::true_type {};
template < typename T >
constexpr bool has_output_operator_v = has_output_operator<T>::value;

template < typename T >
struct has_iostream_operators
    : std::integral_constant<bool,
        has_input_operator_v<T> && has_output_operator_v<T>> {};

template < typename T >
constexpr bool has_iostream_operators_v = has_iostream_operators<T>::value;

template <>
struct has_input_operator< std::nullptr_t > : ::std::false_type{};
template <>
struct has_output_operator< std::nullptr_t > : ::std::false_type{};

}  // namespace psst::json::util


#endif /* PSST_JSON_UTIL_HAS_IO_OPERATOR_HPP_ */
