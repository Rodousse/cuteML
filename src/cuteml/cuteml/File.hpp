#pragma once

#include "cuteml/Expression.hpp"

#include <filesystem>
#include <memory>
#include <optional>
#include <string>
namespace cuteml
{
class File
{
  public:
    File(const std::filesystem::path& path);

    std::string format();

    const std::optional<std::string>& content() const;

  private:
    std::optional<std::string> m_content{};
    std::unique_ptr<FileExpression> m_root;
};

} // namespace cuteml
