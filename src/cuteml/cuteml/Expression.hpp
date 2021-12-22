#pragma once

#include "cuteml/ExpressionNode.hpp"

#include <string>
#include <string_view>
namespace cuteml
{
class FileExpression : public ExpressionNode
{
  public:
    using ExpressionNode::ExpressionNode;
    [[nodiscard]] std::string format(const FormatParameters& params) const override
    {
        std::string returnedVal;
        for(const auto& child: children())
        {
            returnedVal += child->format(params);
        }
        return returnedVal;
    }
};

class NoFormatExpression : public ExpressionNode
{
  public:
    using ExpressionNode::ExpressionNode;
    [[nodiscard]] std::string format(const FormatParameters&) const override
    {
        return std::string(m_contentView);
    }
};

} // namespace cuteml
