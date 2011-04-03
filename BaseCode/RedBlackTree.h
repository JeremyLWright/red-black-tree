/**
 * @brief Red Black Tree Root Node
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */

#include <stdint.h>
#include <tr1/memory>
#include "RedBlackNode.h"
#include "PreOrderIterator.h"

#ifndef REDBLACKTREE
#define REDBLACKTREE

using std::tr1::shared_ptr;
using std::tr1::weak_ptr;
class RedBlackTree {
public:
    typedef shared_ptr<RedBlackTree> Ptr;
    typedef weak_ptr<RedBlackTree> WeakPtr;
    static RedBlackTree::Ptr construct();
    virtual ~RedBlackTree ();
    virtual void Insert(uint32_t key);
    virtual void Insert(uint32_t key, RedBlackNode::color_t color);
    virtual void Delete(uint32_t key);
    virtual PreOrderIterator getPreOrderItr() const;
private:
    virtual RedBlackNode::Ptr Search(uint32_t key) const;
    virtual void Transplant(RedBlackNode::Ptr u, RedBlackNode::Ptr v);
    virtual RedBlackNode::Ptr Minimum(RedBlackNode::Ptr x) const;
    virtual void Insert_Fixup(RedBlackNode::Ptr z);
    virtual void Delete_Fixup(RedBlackNode::Ptr x);
    virtual void Left_Rotate(RedBlackNode::Ptr);
    virtual void Right_Rotate(RedBlackNode::Ptr);
    RedBlackNode::Ptr nil;
    RedBlackNode::Ptr root;
    RedBlackTree::WeakPtr self;
    RedBlackTree ();
};

#endif /* end of include guard: REDBLACKTREE */
