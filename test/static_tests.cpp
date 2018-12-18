/*
 * static_tests.cpp
 *
 *  Created on: 22 мая 2016 г.
 *      Author: sergey.fedorov
 */

#include <gtest/gtest.h>
#include <psst/json/traits.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace psst::json::test {

static_assert( traits::json_type_v< bool > == traits::value_type::boolean,
        "Correct json value type" );
static_assert( traits::json_type_v< int > == traits::value_type::integral,
        "Correct json value type" );
static_assert( traits::json_type_v< unsigned long > == traits::value_type::integral,
        "Correct json value type" );
static_assert( traits::json_type_v< std::int64_t > == traits::value_type::integral,
        "Correct json value type" );
static_assert( traits::json_type_v< char > == traits::value_type::string,
        "Correct json value type" );

static_assert( traits::json_type_v< traits::value_type > == traits::value_type::integral,
        "Correct json value type" );

static_assert( traits::json_type_v< double > == traits::value_type::floating,
        "Correct json value type" );

static_assert( traits::json_type_v< std::string > == traits::value_type::string,
        "Correct json value type");
//static_assert( traits::json_type< std::string_view >::value == traits::value_type::string,
//        "Correct json value type");
static_assert( traits::json_type_v< boost::uuids::uuid > == traits::value_type::string,
        "Correct json value type");

TEST(Dummy, Dummy)
{

}

}  // namespace psst::json::test
