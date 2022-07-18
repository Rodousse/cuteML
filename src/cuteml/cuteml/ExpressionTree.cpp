#include "cuteml/ExpressionTree.hpp"

namespace cuteml
{
template<>
std::vector<ExpressionNode*> flatten<FlattenMethod::PreorderTraversal>()
{
    return {};
}
} // namespace cuteml
