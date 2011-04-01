/**
 * @brief Red Black Tree Implementation
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */

#include "RedBlackTree.h"

RedBlackTree::Ptr RedBlackTree::construct()
{
    RedBlackTree::Ptr c(new RedBlackTree());
    c->self = c;
    return c;
}

RedBlackTree::RedBlackTree()
{
    nil = RedBlackNode::construct(0);
    nil->Color(RedBlackNode::BLACK);
    root = nil;
}

RedBlackTree::~RedBlackTree()
{
}

void RedBlackTree::Insert(uint32_t key)
{
    Insert(key, RedBlackNode::RED);
} 
void RedBlackTree::Insert(uint32_t key, RedBlackNode::color_t color)
{
    RedBlackNode::Ptr z = RedBlackNode::construct(key);
    RedBlackNode::Ptr x = root;
    RedBlackNode::Ptr y = nil;

    while(x != nil)
    {
        y = x;
        if(z->Key() < x->Key())
            x = x->Left();
        else
            x = x->Right();
    }

    z->Parent(y);
    if(y == nil)
        root = z;
    else if(z->Key() < y->Key())
        y->Left(z);
    else
        y->Right(z);
    z->Left(nil);
    z->Right(nil);
    z->Color(color);
    Insert_Fixup(z);


}

void RedBlackTree::Delete(uint32_t key)
{
}

void RedBlackTree::Insert_Fixup(RedBlackNode::Ptr z)
{
    while(z->Parent()->isRed())
    {
        if(z->Parent() == z->Parent()->Parent()->Left())
        {
            RedBlackNode::Ptr y = z->Parent()->Parent()->Right();
            if(y->isRed())
            {
                z->Parent()->Color(RedBlackNode::BLACK); //Case 1
                y->Color(RedBlackNode::BLACK);
                z->Parent()->Parent()->Color(RedBlackNode::RED);
                z = z->Parent()->Parent();
            }
            else if(z == z->Parent()->Right())
            {
                z = z->Parent();            //Case 2
                Left_Rotate(z);             //Case 2
                z->Parent()->Color(RedBlackNode::BLACK);  //Case 3
                z->Parent()->Parent()->Color(RedBlackNode::RED); //Case 3
                Right_Rotate(z->Parent()->Parent()); //Case 3
            }
        }
        else
        {
            RedBlackNode::Ptr y = z->Parent()->Parent()->Left();
            if(y->isRed())
            {
                z->Parent()->Color(RedBlackNode::BLACK); //Case 1
                y->Color(RedBlackNode::BLACK);
                z->Parent()->Parent()->Color(RedBlackNode::RED);
                z = z->Parent()->Parent();
            }
            else if(z == z->Parent()->Left())
            {
                z = z->Parent();            //Case 2
                Right_Rotate(z);             //Case 2
                z->Parent()->Color(RedBlackNode::BLACK);  //Case 3
                z->Parent()->Parent()->Color(RedBlackNode::RED); //Case 3
                Left_Rotate(z->Parent()->Parent()); //Case 3
            }

        }
    }
    root->Color(RedBlackNode::BLACK);
}

void RedBlackTree::Left_Rotate(RedBlackNode::Ptr x)
{
    RedBlackNode::Ptr y = x->Right();
    x->Right(y->Left());
    if(y->Left() != nil)
        y->Left()->Parent(x);
    y->Parent(x->Parent());
    if(x->Parent() == nil)
        root = y;
    else if(x == x->Parent()->Left())
        x->Parent()->Left(y);
    else
        x->Parent()->Right(y);

    y->Left(x);
    x->Parent(y);
}

void RedBlackTree::Right_Rotate(RedBlackNode::Ptr x)
{
    RedBlackNode::Ptr y = x->Left();
    x->Left(y->Right());
    if(y->Right() != nil)
        y->Right()->Parent(x);
    y->Parent(x->Parent());
    if(x->Parent() == nil)
        root = y;
    else if(x == x->Parent()->Right())
        x->Parent()->Right(y);
    else
        x->Parent()->Left(y);

    y->Right(x);
    x->Parent(y);

}

PreOrderIterator RedBlackTree::getPreOrderItr() const
{
   return PreOrderIterator(root, nil); 
}
