#include "cuteml/ExpressionNode.hpp"

namespace cuteml
{
ExpressionNode::ExpressionNode(ExpressionNode* parent, std::string_view contentView) noexcept:
  m_parent(parent),
  m_contentView(contentView)
{
}

const ExpressionNode::OrderedChildrenUPtrList& ExpressionNode::children() const
{
    return m_children;
}

ExpressionNode::OrderedChildrenUPtrList& ExpressionNode::children()
{
    return m_children;
}

ExpressionNode* ExpressionNode::parent() const
{
    return m_parent;
}

bool ExpressionNode::empty() const
{
    return m_children.empty();
}
} // namespace cuteml
