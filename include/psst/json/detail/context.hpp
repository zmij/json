/*
 * context.hpp
 *
 *  Created on: Dec 2, 2018
 *      Author: ser-fedorov
 */

#ifndef PSST_JSON_DETAIL_CONTEXT_HPP_
#define PSST_JSON_DETAIL_CONTEXT_HPP_

#include <memory>

namespace psst::json::detail {

enum class value_context : std::uint8_t{
    root,
    value_key,
    value,
    object,
    array,
};

namespace events {

//@{
/** @name Punctuation */
struct comma {};
struct colon {};
struct eol {};
//@}

//@{
struct null_literal {};
//@}

//@{
struct start_object {};
struct end_object {};
//@}

//@{
struct start_array {};
struct end_array {};
//@}

}  // namespace events

class context {
public:
    context();

    value_context
    current_context() const;

    void
    process_event(events::comma&&);
    void
    process_event(events::colon&&);
    void
    process_event(events::eol&&);

    void
    process_event(events::null_literal&&);

    void
    process_event(events::start_array&&);
    void
    process_event(events::end_array&&);

    void
    process_event(events::start_object&&);
    void
    process_event(events::end_object&&);
private:
    struct impl;
    using pimpl = std::unique_ptr<impl>;
    pimpl pimpl_;
};

}  // namespace psst::json::detail



#endif /* PSST_JSON_DETAIL_CONTEXT_HPP_ */
