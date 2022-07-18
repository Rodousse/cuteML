#pragma once

#include "cuteml/Token.hpp"

#include <vector>

namespace cuteml
{
[[nodiscard]] TokenList scanQmlContent(std::string_view fileContent);

} // namespace cuteml
