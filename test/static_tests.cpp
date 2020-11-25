/*
 * static_tests.cpp
 *
 *  Created on: 22 мая 2016 г.
 *      Author: sergey.fedorov
 */

#include <gtest/gtest.h>
#include <psst/json/traits.hpp>
#include <psst/json/detail/key_value_pair.hpp>

#include <string>
#include <string_view>
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

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace psst::json::test {

using value_type = traits::value_type;

static_assert( traits::json_type_v< bool > == value_type::boolean,
        "Correct json value type" );
static_assert( traits::json_type_v< int > == value_type::integral,
        "Correct json value type" );
static_assert( traits::json_type_v< unsigned long > == value_type::integral,
        "Correct json value type" );
static_assert( traits::json_type_v< std::int64_t > == value_type::integral,
        "Correct json value type" );
static_assert( traits::json_type_v< char > == value_type::string,
        "Correct json value type" );

static_assert( traits::json_type_v< value_type > == value_type::integral,
        "Correct json value type" );

static_assert( traits::json_type_v< double > == value_type::floating,
        "Correct json value type" );

static_assert( traits::json_type_v< std::string > == value_type::string,
        "Correct json value type");
//static_assert( traits::json_type< std::string_view >::value == traits::value_type::string,
//        "Correct json value type");
static_assert( traits::json_type_v< boost::uuids::uuid > == value_type::string,
        "Correct json value type");

enum no_io {};
enum with_io {};
std::ostream&
operator << (std::ostream& os, with_io)
{ return os; }
std::istream&
operator >> (std::istream& is, with_io)
{ return is; }

static_assert( traits::json_type_v<no_io> == value_type::integral, "");
static_assert( traits::json_type_v<with_io> == value_type::string, "");

static_assert( util::has_value_type_member_v< std::vector<int> >, "" );
static_assert( util::has_value_type_member_v< std::list<int> >, "" );
static_assert( util::has_value_type_member_v< std::set<int> >, "" );
static_assert( util::has_value_type_member_v< std::multiset<int> >, "" );
static_assert( util::has_value_type_member_v< std::unordered_set<int> >, "" );
static_assert( util::has_value_type_member_v< std::unordered_multiset<int> >, "" );
static_assert( (util::has_value_type_member_v< std::array<int, 3> >), "" );
static_assert( util::has_value_type_member_v< std::deque<int> >, "" );
static_assert( (util::has_value_type_member_v< std::map<int, int> >), "");
static_assert( (util::has_value_type_member_v< std::multimap<int, int> >), "");
static_assert( (util::has_value_type_member_v< std::unordered_map<int, int> >), "");
static_assert( (util::has_value_type_member_v< std::unordered_multimap<int, int> >), "");

static_assert( util::has_iterator_type_member_v< std::vector<int> >, "" );
static_assert( util::has_iterator_type_member_v< std::list<int> >, "" );
static_assert( util::has_iterator_type_member_v< std::set<int> >, "" );
static_assert( util::has_iterator_type_member_v< std::multiset<int> >, "" );
static_assert( util::has_iterator_type_member_v< std::unordered_set<int> >, "" );
static_assert( util::has_iterator_type_member_v< std::unordered_multiset<int> >, "" );
static_assert( (util::has_iterator_type_member_v< std::array<int, 3> >), "" );
static_assert( util::has_iterator_type_member_v< std::deque<int> >, "" );
static_assert( (util::has_iterator_type_member_v< std::map<int, int> >), "");
static_assert( (util::has_iterator_type_member_v< std::multimap<int, int> >), "");
static_assert( (util::has_iterator_type_member_v< std::unordered_map<int, int> >), "");
static_assert( (util::has_iterator_type_member_v< std::unordered_multimap<int, int> >), "");

static_assert( !util::has_key_type_member_v< std::vector<int> >, "" );
static_assert( !util::has_key_type_member_v< std::list<int> >, "" );
static_assert( util::has_key_type_member_v< std::set<int> >, "" );
static_assert( util::has_key_type_member_v< std::multiset<int> >, "" );
static_assert( util::has_key_type_member_v< std::unordered_set<int> >, "" );
static_assert( util::has_key_type_member_v< std::unordered_multiset<int> >, "" );
static_assert( (!util::has_key_type_member_v< std::array<int, 3> >), "" );
static_assert( !util::has_key_type_member_v< std::deque<int> >, "" );
static_assert( (util::has_key_type_member_v< std::map<int, int> >), "");
static_assert( (util::has_key_type_member_v< std::multimap<int, int> >), "");
static_assert( (util::has_key_type_member_v< std::unordered_map<int, int> >), "");
static_assert( (util::has_key_type_member_v< std::unordered_multimap<int, int> >), "");

static_assert( !util::has_mapped_type_member_v< std::vector<int> >, "" );
static_assert( !util::has_mapped_type_member_v< std::list<int> >, "" );
static_assert( !util::has_mapped_type_member_v< std::set<int> >, "" );
static_assert( !util::has_mapped_type_member_v< std::multiset<int> >, "" );
static_assert( !util::has_mapped_type_member_v< std::unordered_set<int> >, "" );
static_assert( !util::has_mapped_type_member_v< std::unordered_multiset<int> >, "" );
static_assert( (!util::has_mapped_type_member_v< std::array<int, 3> >), "" );
static_assert( !util::has_mapped_type_member_v< std::deque<int> >, "" );
static_assert( (util::has_mapped_type_member_v< std::map<int, int> >), "");
static_assert( (util::has_mapped_type_member_v< std::multimap<int, int> >), "");
static_assert( (util::has_mapped_type_member_v< std::unordered_map<int, int> >), "");
static_assert( (util::has_mapped_type_member_v< std::unordered_multimap<int, int> >), "");

static_assert( util::is_array_type_v< std::vector<int> >, "" );
static_assert( util::is_array_type_v< std::list<int> >, "" );
static_assert( util::is_array_type_v< std::set<int> >, "" );
static_assert( util::is_array_type_v< std::multiset<int> >, "" );
static_assert( util::is_array_type_v< std::unordered_set<int> >, "" );
static_assert( util::is_array_type_v< std::unordered_multiset<int> >, "" );
static_assert( (util::is_array_type_v< std::array<int, 3> >), "" );
static_assert( util::is_array_type_v< std::deque<int> >, "" );
static_assert( (!util::is_array_type_v< std::map<int, int> >), "");
static_assert( (!util::is_array_type_v< std::multimap<int, int> >), "");
static_assert( (!util::is_array_type_v< std::unordered_map<int, int> >), "");
static_assert( (!util::is_array_type_v< std::unordered_multimap<int, int> >), "");

static_assert( !util::is_map_type_v< std::vector<int> >, "" );
static_assert( !util::is_map_type_v< std::list<int> >, "" );
static_assert( !util::is_map_type_v< std::set<int> >, "" );
static_assert( !util::is_map_type_v< std::multiset<int> >, "" );
static_assert( !util::is_map_type_v< std::unordered_set<int> >, "" );
static_assert( !util::is_map_type_v< std::unordered_multiset<int> >, "" );
static_assert( (!util::is_map_type_v< std::array<int, 3> >), "" );
static_assert( !util::is_map_type_v< std::deque<int> >, "" );
static_assert( (util::is_map_type_v< std::map<int, int> >), "");
static_assert( (util::is_map_type_v< std::multimap<int, int> >), "");
static_assert( (util::is_map_type_v< std::unordered_map<int, int> >), "");
static_assert( (util::is_map_type_v< std::unordered_multimap<int, int> >), "");

static_assert( traits::json_type_v< std::vector<int> >                    == value_type::array, "" );
static_assert( traits::json_type_v< std::list<int> >                      == value_type::array, "" );
static_assert( traits::json_type_v< std::set<int> >                       == value_type::array, "" );
static_assert( traits::json_type_v< std::multiset<int> >                  == value_type::array, "" );
static_assert( traits::json_type_v< std::unordered_set<int> >             == value_type::array, "" );
static_assert( traits::json_type_v< std::unordered_multiset<int> >        == value_type::array, "" );
static_assert( (traits::json_type_v< std::array<int, 3> >                 == value_type::array), "" );
static_assert( traits::json_type_v< std::deque<int> >                     == value_type::array, "" );
static_assert( (traits::json_type_v< std::map<int, int> >                 == value_type::object), "");
static_assert( (traits::json_type_v< std::multimap<int, int> >            == value_type::object), "");
static_assert( (traits::json_type_v< std::unordered_map<int, int> >       == value_type::object), "");
static_assert( (traits::json_type_v< std::unordered_multimap<int, int> >  == value_type::object), "");

using string_int_const_kvp = detail::key_value_pair<std::string const&, int const&>;
static_assert(string_int_const_kvp::readonly == true, "");
static_assert(string_int_const_kvp::read_key == false, "");

using string_int_ro_key_kvp = detail::key_value_pair<std::string const&, int&>;
static_assert(string_int_ro_key_kvp::readonly == false, "");
static_assert(string_int_ro_key_kvp::read_key == false, "");

using string_int_rw_kvp = detail::key_value_pair<std::string&, int&>;
static_assert(string_int_rw_kvp::readonly == false, "");
static_assert(string_int_rw_kvp::read_key == true, "");

using char_int_const_kvp = detail::key_value_pair<char const*, int const&>;
static_assert(char_int_const_kvp::readonly == true, "");
static_assert(char_int_const_kvp::read_key == false, "");

using char_int_ro_key_kvp = detail::key_value_pair<char const*, int&>;
static_assert(char_int_ro_key_kvp::readonly == false, "");
static_assert(char_int_ro_key_kvp::read_key == false, "");

using string_int_const_kvp1 = decltype(make_kvp(std::declval<std::string const&>(), std::declval<int const&>()));
static_assert(string_int_const_kvp1::readonly == true, "");
static_assert(string_int_const_kvp1::read_key == false, "");

using string_int_ro_key_kvp1 = decltype(make_kvp(std::declval<std::string const&>(), std::declval<int&>()));
static_assert(string_int_ro_key_kvp1::readonly == false, "");
static_assert(string_int_ro_key_kvp1::read_key == false, "");

using char_int_const_kvp1 = decltype(make_kvp("", std::declval<int const&>()));
static_assert(char_int_const_kvp1::readonly == true, "");
static_assert(char_int_const_kvp1::read_key == false, "");

using char_int_ro_key_kvp1 = decltype(make_kvp("", std::declval<int&>()));
static_assert(char_int_ro_key_kvp1::readonly == false, "");
static_assert(char_int_ro_key_kvp1::read_key == false, "");


TEST(Dummy, Dummy)
{
  int foo;
  PSST_JSON_KVP(foo);
}

}  // namespace psst::json::test
