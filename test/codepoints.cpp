/*
 * codepoints.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: zmij
 */

#include <gtest/gtest.h>
#include <psst/json/json_io_base.hpp>
#include <string>
#include <iostream>
#include <codecvt>


namespace psst::json::test {

TEST(Codepoint, Convert)
{
    std::string expected = u8"\u00a9";
    std::cerr << expected << "\n";

    std::wstring_convert<::std::codecvt_utf8<char32_t>, char32_t> converter;
    std::string test = converter.to_bytes(0x00a9);
    std::cerr << test << "\n";

    EXPECT_EQ(expected, test);
}

TEST(Codepoint, Unescape)
{
    {
        std::string seq = "\\u00a9";
        auto beg = seq.begin() + 2;
        auto end = seq.end();
        auto val = __1::unicode_escape_sequence(beg, end);
        EXPECT_TRUE(val.second);
        EXPECT_EQ(0x00a9, val.first);
        beg = seq.begin() + 2;
        val = __1::unicode_codepoint(beg, end);
        EXPECT_TRUE(val.second);
        EXPECT_EQ(0x00a9, val.first);
    }
    {
        std::string seq = "\\u00a";
        auto beg = seq.begin() + 2;
        auto end = seq.end();
        auto val = __1::unicode_escape_sequence(beg, end);
        EXPECT_FALSE(val.second);
        EXPECT_EQ(3, val.first);
    }
}

TEST(Codepoint, SurrogatePair)
{
    using json_io = __1::json_io_base<char>;
    {
        std::string seq = "\\ud834\\udf06";
        auto beg = seq.begin() + 2;
        auto end = seq.end();
        auto val = __1::unicode_codepoint(beg, end);
        EXPECT_TRUE(val.second);
        EXPECT_EQ(0x1d306, val.first);

        std::string res;
        json_io::add_codepoint(res, val.first);
        std::cerr << res << "\n";
    }
    {
        std::string seq = "\\ud83";
        auto beg = seq.begin() + 2;
        auto end = seq.end();
        auto val = __1::unicode_codepoint(beg, end);
        EXPECT_FALSE(val.second);
        EXPECT_EQ(3, val.first);
    }
    {
        std::string seq = "\\ud834";
        auto beg = seq.begin() + 2;
        auto end = seq.end();
        auto val = __1::unicode_codepoint(beg, end);
        EXPECT_FALSE(val.second);
        EXPECT_EQ(4, val.first);
    }
    {
        std::string seq = "\\ud834\\";
        auto beg = seq.begin() + 2;
        auto end = seq.end();
        auto val = __1::unicode_codepoint(beg, end);
        EXPECT_FALSE(val.second);
        EXPECT_EQ(5, val.first);
    }
    {
        std::string seq = "\\ud834\\u";
        auto beg = seq.begin() + 2;
        auto end = seq.end();
        auto val = __1::unicode_codepoint(beg, end);
        EXPECT_FALSE(val.second);
        EXPECT_EQ(6, val.first);
    }
    {
        std::string seq = "\\ud834\\uab";
        auto beg = seq.begin() + 2;
        auto end = seq.end();
        auto val = __1::unicode_codepoint(beg, end);
        EXPECT_FALSE(val.second);
        EXPECT_EQ(8, val.first);
    }
}

TEST(JsonParse, Unescape)
{
    std::string json_val = R"~("value\n\ud834\udf06")~";
    auto beg = json_val.begin();
    auto end = json_val.end();
    std::string res;
    EXPECT_TRUE(__1::unescape(beg, end, res));
    std::cerr << res << "\n";
}

}  // namespace psst::json::test
