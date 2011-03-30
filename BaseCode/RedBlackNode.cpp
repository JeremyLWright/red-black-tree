#include "RedBlackNode.h"


RedBlackNode::Ptr RedBlackNode::construct(uint32_t key)
{
    RedBlackNode::Ptr c(new RedBlackNode(key));
    c->self = c;
    return c;
}

RedBlackNode::RedBlackNode(uint32_t key):
    key(key),
    color(RED)
{
}

RedBlackNode::~RedBlackNode(){ }

RedBlackNode::Ptr RedBlackNode::Left() const
{
    return this->left;
}

RedBlackNode::Ptr RedBlackNode::Right() const
{
    return this->right;
}

RedBlackNode::Ptr RedBlackNode::Parent() const
{
    return this->parent;
}

bool RedBlackNode::isLeftChild() const
{
    RedBlackNode::Ptr locked_self = self.lock();
    if((this->Parent()->Left()) == locked_self)
        return true;
    return false;
}

bool RedBlackNode::isRed() const
{
    return (color == RED);
}

uint32_t RedBlackNode::Key() const
{
    return key;
}

void RedBlackNode::Left(RedBlackNode::Ptr new_node)
{
    left = new_node;
    
}

void RedBlackNode::Right(RedBlackNode::Ptr new_node)
{
    right = new_node;
}

void RedBlackNode::Parent(RedBlackNode::Ptr parent_node)
{
    parent = parent_node;
}

void RedBlackNode::Color(color_t new_color)
{
    color = new_color;
}

