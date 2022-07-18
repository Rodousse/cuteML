#pragma once

#include "cuteml/ExpressionNode.hpp"

#include <vector>

namespace cuteml
{
enum class FlattenMethod
{
    PreorderTraversal
};

template<FlattenMethod>
std::vector<ExpressionNode*> flatten();

template<>
std::vector<ExpressionNode*> flatten<FlattenMethod::PreorderTraversal>();

// class ExpressionTree
//{
//  public:
//    ExpressionTree(ExpressionNode root);
//    ExpressionTree(ExpressionTree&&) = default;
//    ExpressionTree& operator=(ExpressionTree&&) = default;
//    ExpressionTree(const ExpressionTree&) = default;
//    ExpressionTree& operator=(const ExpressionTree&) = default;
//    ~ExpressionTree() = default;
//
//  private:
//    ExpressionNode m_root;
//};

class PreorderTraversalIterator
{
  public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = ExpressionNode;
    using pointer = value_type*;   // or also value_type*
    using reference = value_type&; // or also value_type&

    PreorderTraversalIterator() = default;
    PreorderTraversalIterator(const ExpressionNode& tree);

  private:
    pointer* m_value;
};
} // namespace cuteml
