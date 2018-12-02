/*
 * integral_constants.hpp
 *
 *  Created on: 22 мая 2016 г.
 *      Author: sergey.fedorov
 */

#ifndef ZMIJ_JSON_UTIL_INTEGRAL_CONSTANTS_HPP_
#define ZMIJ_JSON_UTIL_INTEGRAL_CONSTANTS_HPP_

#include <type_traits>

namespace zmij::json::util {

template < typename ConstantType, bool Condition, ConstantType ifTrue, ConstantType ifFalse >
struct conditional_constant : ::std::integral_constant<ConstantType, ifTrue> {};

template < typename ConstantType, ConstantType ifTrue, ConstantType ifFalse >
struct conditional_constant< ConstantType, false, ifTrue, ifFalse >
    : ::std::integral_constant<ConstantType, ifFalse> {};

}  // namespace zmij::json::util

#endif /* ZMIJ_JSON_UTIL_INTEGRAL_CONSTANTS_HPP_ */
