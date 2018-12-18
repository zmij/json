/*
 * static_tests.cpp
 *
 *  Created on: 22 мая 2016 г.
 *      Author: sergey.fedorov
 */

#include <gtest/gtest.h>
#include <psst/json/parser.hpp>
#include <psst/json/traits.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace psst::json::test {

static_assert( traits::json_type< bool >::value == traits::value_type::boolean,
        "Correct json value type" );
static_assert( traits::json_type< int >::value == traits::value_type::integral,
        "Correct json value type" );
static_assert( traits::json_type< unsigned long >::value == traits::value_type::integral,
        "Correct json value type" );
static_assert( traits::json_type< std::int64_t >::value == traits::value_type::integral,
        "Correct json value type" );
static_assert( traits::json_type< char >::value == traits::value_type::string,
        "Correct json value type" );

static_assert( traits::json_type< traits::value_type >::value == traits::value_type::integral,
        "Correct json value type" );

static_assert( traits::json_type< double >::value == traits::value_type::floating,
        "Correct json value type" );

static_assert( traits::json_type< std::string >::value == traits::value_type::string,
        "Correct json value type");
static_assert( traits::json_type< boost::uuids::uuid >::value == traits::value_type::string,
        "Correct json value type");

TEST(Dummy, Dummy)
{

}

}  // namespace psst::json::test
