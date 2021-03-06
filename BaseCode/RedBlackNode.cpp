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

RedBlackNode::Ptr const RedBlackNode::Left() const
{
    return this->left;
}

RedBlackNode::Ptr const RedBlackNode::Right() const
{
    return this->right;
}

RedBlackNode::Ptr const RedBlackNode::Parent() const
{
    if(RedBlackNode::Ptr shared_parent = this->parent.lock())
        return shared_parent;
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
    parent = RedBlackNode::WeakPtr(parent_node);
}

void RedBlackNode::Color(color_t new_color)
{
    color = new_color;
}

RedBlackNode::color_t RedBlackNode::Color() const
{
    return color;
}

