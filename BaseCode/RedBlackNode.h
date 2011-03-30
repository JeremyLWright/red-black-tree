/**
 * @brief Encapsulates the Nodes of the Tree.
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */

#include <tr1/memory>
#include <stdint.h>
#include <string>
#ifndef REDBLACKNODE
#define REDBLACKNODE

using std::tr1::shared_ptr;
using std::tr1::weak_ptr;
using std::string;

class RedBlackNode {
public:
    typedef enum { RED, BLACK } color_t;
    typedef shared_ptr<RedBlackNode> Ptr;
    typedef weak_ptr<RedBlackNode> WeakPtr;
    static RedBlackNode::Ptr construct(uint32_t key);
    virtual ~RedBlackNode ();
    virtual bool isRed() const;
    virtual void Color(color_t);
    virtual uint32_t Key() const;
    virtual RedBlackNode::Ptr Left() const;
    virtual void Left(RedBlackNode::Ptr);
    virtual RedBlackNode::Ptr Right() const;
    virtual void Right(RedBlackNode::Ptr);
    virtual RedBlackNode::Ptr Parent() const;
    virtual void Parent(RedBlackNode::Ptr);
    virtual bool isLeftChild() const;
private:
    RedBlackNode::WeakPtr self;
    RedBlackNode(uint32_t key);
    uint32_t key;
    RedBlackNode::Ptr parent;
    RedBlackNode::Ptr left;
    RedBlackNode::Ptr right;
    color_t color;
};

#endif /* end of include guard: REDBLACKNODE */
