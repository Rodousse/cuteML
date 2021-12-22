#pragma once

#include "cuteml/FormatParameters.hpp"

#include <memory>
#include <vector>
namespace cuteml
{
class ExpressionNode
{
  public:
    using OrderedChildrenUPtrList = std::vector<std::unique_ptr<ExpressionNode>>;

    ExpressionNode() = delete;
    ExpressionNode(ExpressionNode* parent, std::string_view contentView) noexcept;
    ExpressionNode(ExpressionNode&&) noexcept = default;
    ExpressionNode& operator=(ExpressionNode&&) noexcept = default;
    ExpressionNode(const ExpressionNode&) = delete;
    ExpressionNode& operator=(const ExpressionNode&) = delete;
    virtual ~ExpressionNode() = default;

    const OrderedChildrenUPtrList& children() const;
    OrderedChildrenUPtrList& children();

    [[nodiscard]] virtual std::string format(const FormatParameters& param) const = 0;

    ExpressionNode* parent() const;

    bool empty() const;

  protected:
    OrderedChildrenUPtrList m_children{};
    ExpressionNode* m_parent{nullptr};
    std::string_view m_contentView;
};
} // namespace cuteml
