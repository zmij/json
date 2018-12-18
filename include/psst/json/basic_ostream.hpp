/*
 * ostream.hpp
 *
 *  Created on: Dec 2, 2018
 *      Author: ser-fedorov
 */

#ifndef PSST_JSON_BASIC_OSTREAM_HPP_
#define PSST_JSON_BASIC_OSTREAM_HPP_

#include <psst/json/json_stream_fwd.hpp>

// TODO Check standard library for string view
#include <string_view>

namespace psst::json {

template <typename CharT, typename Traits>
basic_ostream<CharT, Traits>
operator << (basic_ostream<CharT, Traits>& os, std::basic_string<CharT, Traits> const& val);

template <typename CharT, typename Traits>
class basic_ostream {
public:
    using this_type = basic_ostream<CharT, Traits>;
    using string_type = std::basic_string<CharT, Traits>;
    using string_view_type = std::basic_string_view<CharT, Traits>;
    using ostream_type = std::basic_ostream<CharT, Traits>;
private:
    friend this_type& operator << (this_type&, string_type const&);
    friend this_type& operator << (this_type&, string_view_type const&);

    this_type&
    write(string_type const&)
    {
        return *this;
    }
    this_type&
    write(string_view_type const&)
    {
        return *this;
    }
};

//@{
/** @name Basic output functions */
template <typename CharT, typename Traits>
basic_ostream<CharT, Traits>
operator << (basic_ostream<CharT, Traits>& os, std::basic_string<CharT, Traits> const& val)
{
    return os.write(val);
}

template <typename CharT, typename Traits>
basic_ostream<CharT, Traits>
operator << (basic_ostream<CharT, Traits>& os, std::basic_string_view<CharT, Traits> const& val)
{
    return os.write(val);
}

template <typename CharT, typename Traits>
basic_ostream<CharT, Traits>
operator << (basic_ostream<CharT, Traits>& os, std::int32_t)
{
    return os;
}

template <typename CharT, typename Traits>
basic_ostream<CharT, Traits>
operator << (basic_ostream<CharT, Traits>& os, float)
{
    return os;
}

template <typename CharT, typename Traits>
basic_ostream<CharT, Traits>
operator << (basic_ostream<CharT, Traits>& os, double)
{
    return os;
}

template <typename CharT, typename Traits>
basic_ostream<CharT, Traits>
operator << (basic_ostream<CharT, Traits>& os, bool)
{
    return os;
}

//@}
}  // namespace psst::json


#endif /* PSST_JSON_BASIC_OSTREAM_HPP_ */
