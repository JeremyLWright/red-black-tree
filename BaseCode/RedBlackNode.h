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
using std::string;

class RedBlackNode {
public:
    typedef enum { RED, BLACK } color_t;
    typedef shared_ptr<RedBlackNode> Ptr;
    virtual RedBlackNode::Ptr construct(uint32_t key, RedBlackNode::Ptr nil);
    virtual ~RedBlackNode ();
    bool isRed() const;
    uint32_t Key() const;
    color_t Color() const;
    string toString() const;
    bool operator==(RedBlackNode::Ptr const & other) const;
    RedBlackNode::Ptr Left() const;
    RedBlackNode::Ptr Right() const;
    RedBlackNode::Ptr Uncle() const;
    RedBlackNode::Ptr Parent() const;
    bool isLeftChild() const;
private:
    RedBlackNode();
    uint32_t key;
    RedBlackNode::Ptr left;
    RedBlackNode::Ptr right;
    color_t color;
};

#endif /* end of include guard: REDBLACKNODE */
