/*
 * key_value_pair.hpp
 *
 *  Created on: Dec 19, 2018
 *      Author: ser-fedorov
 */

#ifndef PSST_JSON_DETAIL_KEY_VALUE_PAIR_HPP_
#define PSST_JSON_DETAIL_KEY_VALUE_PAIR_HPP_

#include <psst/json/traits.hpp>

#include <string>

namespace psst::json {
namespace detail {

template <typename Key, typename Value, bool Readonly, bool ReadKey>
struct key_value_pair_impl {
  static constexpr bool readonly  = Readonly;
  static constexpr bool read_key  = ReadKey;
  using key_type                  = Key;
  using value_type                = Value;
  template <typename CharT, typename CharTraits = std::char_traits<CharT>>
  using json_type = traits::json_type<value_type, CharT, CharTraits>;
  template <typename CharT, typename CharTraits = std::char_traits<CharT>>
  static constexpr traits::value_type json_type_v = json_type<CharT, CharTraits>::value;

  key_type    key;
  value_type  value;

  constexpr key_value_pair_impl(key_type k, value_type v)
      : key{k}, value{v} {}
};

template <typename Key, typename Value>
struct key_value_pair;

template <typename Key, typename Value>
struct key_value_pair<Key const&, Value const&>
    : key_value_pair_impl<Key const&, Value const&, true, false> {
  using base_type = key_value_pair_impl<Key const&, Value const&, true, false>;
  using base_type::base_type;
};

template <typename Key, typename Value>
struct key_value_pair<Key const&, Value&>
    : key_value_pair_impl<Key const&, Value&, false, false> {
  using base_type = key_value_pair_impl<Key const&, Value&, false, false>;
  using base_type::base_type;
};

template <typename Key, typename Value>
struct key_value_pair<Key&, Value&>
    : key_value_pair_impl<Key&, Value&, false, true> {
  using base_type = key_value_pair_impl<Key&, Value&, false, true>;
  using base_type::base_type;
};

template <typename Value>
struct key_value_pair<char const*, Value const&>
    : key_value_pair_impl<char const*, Value const&, true, false> { // TODO use string view
  using base_type = key_value_pair_impl<char const*, Value const&, true, false>;
  using base_type::base_type;
};

template <typename Value>
struct key_value_pair<char const*, Value&>
    : key_value_pair_impl<char const*, Value&, false, false> { // TODO use string view
  using base_type = key_value_pair_impl<char const*, Value&, false, false>;
  using base_type::base_type;
};

}  // namespace detail

template <typename Key, typename Value>
auto make_kvp(Key&& key, Value&& value)
{
  return detail::key_value_pair<Key, Value>{std::forward<Key>(key),
      std::forward<Value>(value)};
}

}  // namespace psst::json::detail

#define PSST_JSON_KVP(var) psst::json::make_kvp(#var, var);

#endif /* PSST_JSON_DETAIL_KEY_VALUE_PAIR_HPP_ */
