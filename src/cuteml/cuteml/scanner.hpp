#pragma once

#include "cuteml/Expression.hpp"

#include <optional>
#include <string>

namespace cuteml
{
std::unique_ptr<FileExpression> scanQmlContent(const std::string& fileContent);
}
