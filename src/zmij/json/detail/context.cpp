/*
 * context.cpp
 *
 *  Created on: Dec 2, 2018
 *      Author: ser-fedorov
 */

#include <afsm/fsm.hpp>
#include <psst/json/detail/context.hpp>

namespace psst::json::detail {

struct context::impl {
    value_context current_;
};

context::context()
    : pimpl_(std::make_unique<impl>())
{
}

value_context
context::current_context() const
{
    return pimpl_->current_;
}

}  // namespace psst::json::detail

