/*
 * traits.hpp
 *
 *  Created on: 22 мая 2016 г.
 *      Author: sergey.fedorov
 */

#ifndef PSST_JSON_TRAITS_HPP_
#define PSST_JSON_TRAITS_HPP_

#include <psst/json/util/has_io_operator.hpp>
#include <psst/json/util/integral_constants.hpp>

#include <string>
#include <cstdint>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>

#include <memory>

namespace psst::json::traits {

enum class value_type {
    void_,
    boolean,
    integral,
    floating,
    string,
    array,
    object,
};

template < value_type V >
using json_type_constant = std::integral_constant< value_type, V >;
template < bool Condition, value_type IfTrue, value_type IfFalse >
using conditional_tag
        = util::conditional_constant< value_type, Condition, IfTrue, IfFalse >;

template < bool Condition, value_type IfTrue, value_type IfFalse >
static constexpr value_type conditional_tag_v = conditional_tag<Condition, IfTrue, IfFalse>();

template < typename T >
struct json_type : conditional_tag<
    std::is_enum_v<T>,                                /*if*/
        value_type::integral,
        conditional_tag_v<
            std::is_fundamental_v< T >,               /* if */
            conditional_tag_v<
                std::is_integral_v< T >,              /* if */
                conditional_tag_v<
                    std::is_same_v< T, bool >,        /* if */
                    value_type::boolean,
                    conditional_tag_v<
                      std::is_same_v< T, char >,      /* if */
                      value_type::string,
                      value_type::integral
                    >
                >,
                conditional_tag_v<
                    std::is_floating_point_v<T>,      /* if */
                    value_type::floating,
                    value_type::void_
                >
            >,
            conditional_tag_v<
                util::has_iostream_operators_v< T >,   /* if */
                value_type::string,
                value_type::object>
         > > {};

//@{
/** @name Pointer types */
template < typename T >
struct json_type<T*> : json_type<T> {};
template < typename T >
struct json_type<T&> : json_type<T> {};
template < typename T >
struct json_type< std::shared_ptr<T> > : json_type<T> {};
template < typename T >
struct json_type< std::unique_ptr<T> > : json_type<T> {};

template <typename T, std::size_t N>
struct json_type< T[N] > : json_type_constant< value_type::array > {};

template <>
struct json_type<char*> : json_type_constant< value_type::string > {};
template <>
struct json_type<char const*> : json_type_constant< value_type::string > {};
//@}

//@{
/** @name Container types */
template < typename T, typename ... Rest>
struct json_type< std::vector< T, Rest ... > > : json_type_constant< value_type::array >{};
template < typename T, typename ... Rest>
struct json_type< std::list< T, Rest ... > > : json_type_constant< value_type::array >{};
template < typename T, typename ... Rest>
struct json_type< std::deque< T, Rest ... > > : json_type_constant< value_type::array >{};
template < typename T, typename ... Rest>
struct json_type< std::set< T, Rest ... > > : json_type_constant< value_type::array >{};
template < typename T, typename ... Rest>
struct json_type< std::multiset< T, Rest ... > > : json_type_constant< value_type::array >{};
template < typename T, typename ... Rest>
struct json_type< std::unordered_set< T, Rest ... > > : json_type_constant< value_type::array >{};
template < typename T, typename ... Rest>
struct json_type< std::unordered_multiset< T, Rest ... > > : json_type_constant< value_type::array >{};
template < typename K, typename V, typename ... Rest >
struct json_type< std::map< K, V, Rest ... > > : json_type_constant< value_type::object >{};
template < typename K, typename V, typename ... Rest >
struct json_type< std::multimap< K, V, Rest ... > > : json_type_constant< value_type::object >{};
template < typename K, typename V, typename ... Rest >
struct json_type< std::unordered_map< K, V, Rest ... > > : json_type_constant< value_type::object >{};
template < typename K, typename V, typename ... Rest >
struct json_type< std::unordered_multimap< K, V, Rest ... > > : json_type_constant< value_type::object >{};
//@}

template <typename T>
struct json_quote : std::conditional<
        json_type<T>::value == value_type::string,
        std::true_type,
        std::false_type
    >::type {};

}  // namespace psst::json::traits

#endif /* PSST_JSON_TRAITS_HPP_ */
