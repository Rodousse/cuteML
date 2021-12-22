#include "cuteml/scaner.hpp"

#include "cuteml/Expression.hpp"

#include <memory>
#include <optional>

namespace cuteml
{
std::unique_ptr<FileExpression> scanQmlContent(const std::string& fileContent)
{
    std::unique_ptr<FileExpression> expressionTree = std::make_unique<FileExpression>(nullptr, fileContent);
    auto& children = expressionTree->children();
    children.emplace_back(
      std::make_unique<NoFormatExpression>(expressionTree.get(), std::string_view(fileContent.data(), 20)));
    children.emplace_back(
      std::make_unique<NoFormatExpression>(expressionTree.get(), std::string_view(fileContent.data() + 20, 20)));
    return expressionTree;
}
} // namespace cuteml
