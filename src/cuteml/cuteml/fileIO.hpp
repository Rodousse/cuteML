#pragma once

#include <filesystem>
#include <optional>
#include <string>

namespace cuteml::IO
{
std::optional<std::string> loadFileContent(const std::filesystem::path& path);
} // namespace cuteml::IO
