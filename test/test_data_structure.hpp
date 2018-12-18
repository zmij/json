/*
 * test_datat_structure.hpp
 *
 *  Created on: 6 нояб. 2016 г.
 *      Author: sergey.fedorov
 */

#ifndef PSST_JSON_TEST_DATA_STRUCTURE_HPP_
#define PSST_JSON_TEST_DATA_STRUCTURE_HPP_

#include <psst/json/json_stream.hpp>

namespace psst::json::__1::test {

struct test_structure {
    std::string   str;
    int             ival;
    float           fval;
};

inline json::__1::json_ostream&
json_write(json::__1::json_ostream& os, test_structure const& v)
{
    os  << "str" << v.str
        << "ival" << v.ival
        << "fval" << v.fval;
    return os;
}

inline json::__1::json_istream&
json_read(json::__1::json_istream& is, test_structure& v)
{
    is  >> "str" >> v.str
        >> "ival" >> v.ival
        >> "fval" >> v.fval;
    return is;
}

}  // namespace psst::json::test

#endif /* PSST_JSON_TEST_DATA_STRUCTURE_HPP_ */
