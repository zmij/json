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
#include <psst/json/util/container_traits.hpp>

#include <type_traits>
#include <string>
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

template < typename T, typename CharT = char, typename Traits = std::char_traits<CharT> >
struct json_type : conditional_tag<
    std::is_enum_v<T>,                                              /* if */
        conditional_tag_v<
          // TODO Enum literal helpers
          util::has_iostream_operators_v< T, CharT, Traits >,       /* if */
          value_type::string,
          value_type::integral
        >,
        conditional_tag_v<
            std::is_fundamental_v< T >,                             /* if */
            conditional_tag_v<
                std::is_integral_v< T >,                            /* if */
                conditional_tag_v<
                    std::is_same_v< T, bool >,                      /* if */
                    value_type::boolean,
                    conditional_tag_v<
                      std::is_same_v< T, char >,                    /* if */
                      value_type::string,
                      value_type::integral
                    >
                >,
                conditional_tag_v<
                    std::is_floating_point_v<T>,                    /* if */
                    value_type::floating,
                    value_type::void_
                >
            >,
            conditional_tag_v<
                util::has_iostream_operators_v< T, CharT, Traits >, /* if */
                value_type::string,
                conditional_tag_v<
                  util::is_array_type_v<T>,                         /* if */
                  value_type::array,
                  value_type::object
                >
            >
         > > {};
template < typename T, typename CharT = char, typename Traits = std::char_traits<CharT> >
constexpr value_type json_type_v = json_type<T, CharT, Traits>::value;

//@{
/** @name Pointer and reference types */
//template < typename T >
//struct json_type<T*> : json_type<T> {};
//template < typename T >
//struct json_type<T const *> : json_type<T> {};
template < typename T, typename CharT, typename Traits >
struct json_type<T&, CharT, Traits> : json_type<T, CharT, Traits> {};
template < typename T, typename CharT, typename Traits >
struct json_type<T const&, CharT, Traits> : json_type<T, CharT, Traits> {};
template < typename T, typename CharT, typename Traits >
struct json_type< std::shared_ptr<T>, CharT, Traits > : json_type<T, CharT, Traits> {};
template < typename T, typename CharT, typename Traits >
struct json_type< std::unique_ptr<T>, CharT, Traits > : json_type<T, CharT, Traits> {};

template < typename T, std::size_t N, typename CharT, typename Traits >
struct json_type< T[N], CharT, Traits > : json_type_constant< value_type::array > {};

template <typename Traits>
struct json_type<char*, char, Traits> : json_type_constant< value_type::string > {};
template <typename Traits>
struct json_type<char const*, char, Traits> : json_type_constant< value_type::string > {};
//@}

template <typename T, typename CharT = char, typename Traits = std::char_traits<CharT> >
struct json_quote : std::conditional_t<
        json_type_v<T, CharT, Traits> == value_type::string,
        std::true_type,
        std::false_type
    > {};
template <typename T, typename CharT = char, typename Traits = std::char_traits<CharT> >
constexpr bool json_quote_v = json_quote<T, CharT, Traits>::value;

}  // namespace psst::json::traits

#endif /* PSST_JSON_TRAITS_HPP_ */
