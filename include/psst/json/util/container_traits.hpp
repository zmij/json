/*
 * container_traits.hpp
 *
 *  Created on: Dec 19, 2018
 *      Author: ser-fedorov
 */

#ifndef PSST_JSON_UTIL_CONTAINER_TRAITS_HPP_
#define PSST_JSON_UTIL_CONTAINER_TRAITS_HPP_

#include <type_traits>
#include <utility>

namespace psst::json::util {

//@{
template < typename T, typename = std::void_t<> >
struct has_value_type_member : std::false_type {};
template < typename T >
struct has_value_type_member< T, std::void_t< typename T::value_type > >
    : std::true_type {};
template < typename T >
constexpr bool has_value_type_member_v = has_value_type_member<T>::value;
//@}

//@{
template < typename T, typename = std::void_t<> >
struct has_key_type_member : std::false_type {};
template < typename T >
struct has_key_type_member< T, std::void_t< typename T::key_type > >
    : std::true_type {};
template < typename T >
constexpr bool has_key_type_member_v = has_key_type_member<T>::value;
//@}

//@{
template < typename T, typename = std::void_t<> >
struct has_mapped_type_member : std::false_type {};
template < typename T >
struct has_mapped_type_member< T, std::void_t< typename T::mapped_type > >
    : std::true_type {};
template < typename T >
constexpr bool has_mapped_type_member_v = has_mapped_type_member<T>::value;
//@}

//@{
template < typename T, typename = std::void_t<> >
struct has_iterator_type_member : std::false_type {};
template < typename T >
struct has_iterator_type_member< T, std::void_t< typename T::iterator > >
    : std::true_type {};
template < typename T >
constexpr bool has_iterator_type_member_v = has_iterator_type_member<T>::value;
//@}

//@{
template < typename T >
struct is_array_type : std::integral_constant<bool,
        has_value_type_member_v<T> &&
        has_iterator_type_member_v<T> &&
        !has_mapped_type_member_v<T>> {};
template < typename T >
constexpr bool is_array_type_v = is_array_type<T>::value;

template < typename T >
struct is_set_type : std::integral_constant<bool,
        has_value_type_member_v<T> &&
        has_iterator_type_member_v<T> &&
        has_key_type_member_v<T> &&
        !has_mapped_type_member_v<T>> {};
template < typename T >
constexpr bool is_set_type_v = is_set_type<T>::value;

template < typename T >
struct is_map_type : std::integral_constant<bool,
        has_value_type_member_v<T> &&
        has_iterator_type_member_v<T> &&
        has_key_type_member_v<T> &&
        has_mapped_type_member_v<T>> {};
template < typename T >
constexpr bool is_map_type_v = is_map_type<T>::value;

//@}

}  // namespace psst::json::util


#endif /* PSST_JSON_UTIL_CONTAINER_TRAITS_HPP_ */
