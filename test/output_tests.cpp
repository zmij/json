/*
 * output_tests.cpp
 *
 *  Created on: 4 нояб. 2016 г.
 *      Author: sergey.fedorov
 */

#include <gtest/gtest.h>
#include <psst/json/json_stream.hpp>
#include <sstream>
#include <iostream>
#include "debug_parser.hpp"
#include "test_data_structure.hpp"

namespace psst::json::__1::test {

TEST(JOstream, SimpleDatatypesOut)
{
    std::string const k{R"~(bla"bla"bla)~"};
    test_structure ts{"foo", 100500, 3.14};
    test_structure* p_ts{nullptr};

    std::ostringstream os;
    json::__1::json_ostream jos{os, true};
    jos << json::__1::start_object
            << "foo" << "bar"
            << std::string{"str"} << 42
            << 100500 << -3.14
            << k << k
            << true << false
            << "struct" << test_structure{"foo", 100500, 3.14}
            << "array" << json::__1::start_array
                << "foo" << "bar"
                << std::string{"str"} << 42
                << 100500 << -3.14
                << k << k
                << true << false
                << nullptr
                << test_structure{"foo", 100500, 3.14}
                << json::__1::start_array
                    << "foo" << "bar"
                    << std::string{"str"} << 42
                    << 100500 << -3.14
                    << k << k
                    << true << false
                    << json::__1::start_object
                    << json::__1::end_object
                    << json::__1::start_array
                    << json::__1::end_array
                << json::__1::end_array
                << &ts
                << p_ts
            << json::__1::end_array
            << "by_ref" << ts
            << "by_ptr" << &ts
            << "by_null_ptr" << p_ts
        << json::__1::end_object
    ;

    EXPECT_ANY_THROW(jos << "error");
    std::cerr << os.str() << "\n";

    std::istringstream is(os.str());
    json::__1::test::debug_parser parser;
    bool r = detail::parse(parser, is);
    EXPECT_TRUE(r) << "Successful parse";
}

TEST(JOstream, VectorOut)
{
    std::vector<::std::string> strings{
        "one", "two", "three"
    };
    std::vector<int> ints {1, 2, 3};
    {
        std::ostringstream os;
        json::__1::json_ostream jos{os};
        jos << strings;

        EXPECT_ANY_THROW(jos << "error");
        EXPECT_EQ(R"~(["one","two","three"])~", os.str()) << "Output vector of strings";

        std::istringstream is(os.str());
        json::__1::test::debug_parser parser;
        bool r = detail::parse(parser, is);
        EXPECT_TRUE(r) << "Successful parse";
    }
    {
        std::ostringstream os;
        json::__1::json_ostream jos{os};
        jos << ints;

        EXPECT_ANY_THROW(jos << "error");
        EXPECT_EQ("[1,2,3]", os.str()) << "Output vector of ints";

        std::istringstream is(os.str());
        json::__1::test::debug_parser parser;
        bool r = detail::parse(parser, is);
        EXPECT_TRUE(r) << "Successful parse";
    }
    {
        std::ostringstream os;
        json::__1::json_ostream jos{os};
        jos << json::__1::start_array
            << strings << ints
            << json::__1::end_array;
        EXPECT_ANY_THROW(jos << "error");
        EXPECT_EQ(R"~([["one","two","three"],[1,2,3]])~", os.str()) << "Correct output";

        std::istringstream is(os.str());
        json::__1::test::debug_parser parser;
        bool r = detail::parse(parser, is);
        EXPECT_TRUE(r) << "Successful parse";
    }
}

}  // namespace psst::json::test
