/**
 * @brief Iterator Object for traversing a RedBlack tree in preorder
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */

#include <stack>
#include <iterator>
#include "RedBlackNode.h"
using namespace std;
#ifndef PREORDERITERATOR_H
#define PREORDERITERATOR_H

class PreOrderIterator  : public std::iterator<input_iterator_tag, RedBlackNode::Ptr>{
public:
    PreOrderIterator (RedBlackNode::Ptr root, RedBlackNode::Ptr nil);
    PreOrderIterator& operator++();
    RedBlackNode::Ptr operator*() const;
    bool complete() const;

private:
    RedBlackNode::Ptr p;
    RedBlackNode::Ptr const root;
    RedBlackNode::Ptr const nil;
    std::stack<RedBlackNode::Ptr> nodeStack;
};

#endif

