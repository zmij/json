/*
 * parser_traits.hpp
 *
 *  Created on: 20 июня 2016 г.
 *      Author: sergey.fedorov
 */

#ifndef PSST_JSON_DETAIL_PARSER_TRAITS_HPP_
#define PSST_JSON_DETAIL_PARSER_TRAITS_HPP_

#include <psst/json/detail/json_lexer.hpp>
#include <psst/json/detail/json_fsm.hpp>

namespace psst::json::__1::detail {

template < typename BaseIterator, typename CharT,
        typename Traits = std::char_traits<CharT> >
struct parser_traits {
    using base_iterator     = BaseIterator;
    using json_io            = json_io_base<CharT, Traits>;
    using string_type       = typename json_io::string_type;
    using integral_type     = typename json_io::integral_type;
    using float_type        = typename json_io::float_type;

    using attribs           = boost::mpl::vector< string_type, integral_type, float_type, bool >;
    using token_type        = boost::spirit::lex::lexertl::token< base_iterator, attribs >;
    using lexer_type        = boost::spirit::lex::lexertl::lexer< token_type >;
    using tokenizer_type    = lexer::basic_json_tokens< lexer_type, CharT, Traits >;
    using token_iterator    = typename tokenizer_type::iterator_type;
    using fsm_type          = basic_json_fsm<CharT, Traits>;
};

}  // namespace psst::json::__1::detail

#endif /* PSST_JSON_DETAIL_PARSER_TRAITS_HPP_ */
