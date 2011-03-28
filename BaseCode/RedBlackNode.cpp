#include "RedBlackNode.h"


RedBlackNode::Ptr RedBlackNode::construct(uint32_t key, RedBlackNode::Ptr nil)
{
    left = nil;
    right = nil;
    RedBlackNode::Ptr c(new RedBlackNode());
    return c;
}

RedBlackNode::RedBlackNode(){ }
RedBlackNode::~RedBlackNode(){ }

RedBlackNode::Ptr RedBlackNode::Left() const
{
    return this->left;
}

RedBlackNode::Ptr RedBlackNode::Right() const
{
    return this->right;
}

RedBlackNode::Ptr RedBlackNode::Uncle() const
{
    if(isLeftChild())
    {
        return this->Parent()->Right();
    }
    else
    {
        return this->Parent()->Left();
    }
}

bool RedBlackNode::isLeftChild() const
{
    if((this->Parent()->Left()) == this)
        return true;
    return false;
}

bool RedBlackNode::operator==(RedBlackNode::Ptr const & other) const
{
    return (other->Key() == key);
}
