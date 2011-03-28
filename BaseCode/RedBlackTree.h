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

#ifndef REDBLACKTREE
#define REDBLACKTREE

using std::tr1::shared_ptr;
using RedBlackNode::color_t;
class RedBlackTree {
public:
    typedef shared_ptr<RedBlackTree> Ptr;
    virtual RedBlackTree::Ptr construct();
    virtual ~RedBlackTree ();
    virtual void Insert(uint32_t key);
    virtual void Insert(uint32_t key, color_t color);
    virtual void Delete(uint32_t key);    
private:
    RedBlackNode::Ptr nil;
    RedBlackNode::Ptr root;
    RedBlackTree ();
};

#endif /* end of include guard: REDBLACKTREE */
