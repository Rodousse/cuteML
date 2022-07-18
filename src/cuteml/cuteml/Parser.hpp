#pragma once

#include "cuteml/Expression.hpp"
#include "cuteml/Token.hpp"

namespace cuteml
{
FileExpression parse(const TokenList& tokens);

} // namespace cuteml
