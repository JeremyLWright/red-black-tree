/**
 * @brief Implementation for PreOrder Iterator
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */

#include "PreOrderIterator.h"

PreOrderIterator::PreOrderIterator(RedBlackNode::Ptr _root,
        RedBlackNode::Ptr _nil):
    p(_root),
    root(_root),
    nil(_nil)
{
    nodeStack.push(_root);
}
    

PreOrderIterator& PreOrderIterator::operator++()
{
    p = nodeStack.top(); //This is what the iterator will see.
    nodeStack.pop();
    if(p->Right() != nil)
        nodeStack.push(p->Right());
    if(p->Left() != nil)
        nodeStack.push(p->Left());
    return *this;
}

bool PreOrderIterator::complete() const
{
    return nodeStack.empty();   
}

RedBlackNode::Ptr PreOrderIterator::operator*() const
{
    return p;
}
