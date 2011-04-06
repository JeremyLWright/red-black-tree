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
	nil->Left(nil);
	nil->Right(nil);
	nil->Parent(nil);
    nil->Color(RedBlackNode::BLACK);
    root = nil;
}

RedBlackTree::~RedBlackTree()
{
}

void RedBlackTree::Insert(uint32_t key)
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
    z->Color(RedBlackNode::RED);
    Insert_Fixup(z);
}

/**
 * Inserts as a binary tree, without respecting color
 */
void RedBlackTree::Insert(uint32_t key, RedBlackNode::color_t color)
{
    RedBlackNode::Ptr z = RedBlackNode::construct(key);
    z->Color(color);

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
        root = z; //Tree was empty
    else if(z->Key() < y->Key())
        y->Left(z);
    else
        y->Right(z);
    z->Left(nil);
    z->Right(nil);

}

void RedBlackTree::Delete(uint32_t key)
{
    
    RedBlackNode::Ptr z = Search(key);
    RedBlackNode::Ptr x;
    if(z == nil)
        return;
    
    RedBlackNode::Ptr y = z;
    RedBlackNode::color_t original_color = y->Color();
    if(z->Left() == nil)
    {
        x = z->Right();
        Transplant(z,z->Right());
    }
    else if(z->Right() == nil)
    {
        x = z->Left();
        Transplant(z,z->Left());
    }
    else
    {
        y = Minimum(z->Right());
        original_color = y->Color();
        x = y->Right();
        if(y->Parent() == z)
        {
            x->Parent(y);
        }
        else
        {
            Transplant(y,y->Right());
            y->Right(z->Right());
            y->Right()->Parent(y);
        }
        Transplant(z,y);
        y->Left(z->Left());
        y->Left()->Parent(y);
        y->Color(z->Color());
    }
    if(original_color == RedBlackNode::BLACK)
    {
        Delete_Fixup(x);
    }
}


void RedBlackTree::Delete_Fixup(RedBlackNode::Ptr x)
{
    while(x != root && x->Color() == RedBlackNode::BLACK)
    {
        if(x == x->Parent()->Left())
        {
            RedBlackNode::Ptr w = x->Parent()->Right();
            if(w->isRed())
            {
                w->Color(RedBlackNode::BLACK);                  //Case 1
                x->Parent()->Color(RedBlackNode::RED);            //Case 1
                Left_Rotate(x->Parent());                       //Case 1
                w = x->Parent()->Right();                       //Case 1
            }

            if(w->Left()->Color() == RedBlackNode::BLACK &&
               w->Right()->Color() == RedBlackNode::BLACK)
            {
                w->Color(RedBlackNode::RED);                    //Case 2
                x = x->Parent();                                //Case 2
            }
            else
            {
                if(w->Right()->Color() == RedBlackNode::BLACK)
                {
                    w->Left()->Color(RedBlackNode::BLACK);      //Case 3
                    w->Color(RedBlackNode::RED);                //Case 3
                    Right_Rotate(w);                            //Case 3
                    w = x->Parent()->Right();                   //Case 3
                }

                w->Color(x->Parent()->Color());                 //Case 4
                x->Parent()->Color(RedBlackNode::BLACK);        //Case 4
                w->Right()->Color(RedBlackNode::BLACK);         //Case 4
                Left_Rotate(x->Parent());
                x = root;

            }
        }
        else
        {
            RedBlackNode::Ptr w = x->Parent()->Left();
            if(w->isRed())
            {
                w->Color(RedBlackNode::BLACK);                  //Case 1
                x->Parent()->Color(RedBlackNode::RED);            //Case 1
                Right_Rotate(x->Parent());                       //Case 1
                w = x->Parent()->Left();                       //Case 1
            }

            if(w->Right()->Color() == RedBlackNode::BLACK &&
               w->Left()->Color() == RedBlackNode::BLACK)
            {
                w->Color(RedBlackNode::RED);                    //Case 2
                x = x->Parent();                                //Case 2
            }
            else
            {
                if(w->Left()->Color() == RedBlackNode::BLACK)
                {
                    w->Right()->Color(RedBlackNode::BLACK);      //Case 3
                    w->Color(RedBlackNode::RED);                //Case 3
                    Left_Rotate(w);                            //Case 3
                    w = x->Parent()->Left();                   //Case 3
                }

                w->Color(x->Parent()->Color());                 //Case 4
                x->Parent()->Color(RedBlackNode::BLACK);        //Case 4
                w->Left()->Color(RedBlackNode::BLACK);         //Case 4
                Right_Rotate(x->Parent());
                x = root;

            }
        }
    }
    x->Color(RedBlackNode::BLACK);
}

RedBlackNode::Ptr RedBlackTree::Search(uint32_t key) const
{
    RedBlackNode::Ptr search = root;
    while(search != nil)
    {
        if(key == search->Key())
            return search;
        else if (key < search->Key())
            search = search->Left();
        else
            search = search->Right();
    }
    return nil;
}


void RedBlackTree::Insert_Fixup(RedBlackNode::Ptr z)
{
    while(z->Parent()->isRed() && z->Parent() != nil)
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
            else 
			{
				if(z == z->Parent()->Right())
				{
					z = z->Parent();            //Case 2
					Left_Rotate(z);             //Case 2
				}
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
            else 
			{
				if(z == z->Parent()->Left())
				{
					z = z->Parent();            //Case 2
					Right_Rotate(z);             //Case 2
				}
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

void RedBlackTree::Transplant(RedBlackNode::Ptr u, RedBlackNode::Ptr v)
{
    if(u->Parent() == nil)
        root = v;
    else if(u == u->Parent()->Left())
        u->Parent()->Left(v);
    else
        u->Parent()->Right(v);
    v->Parent(u->Parent());
}

RedBlackNode::Ptr RedBlackTree::Minimum(RedBlackNode::Ptr x) const
{
    while(x->Left() != nil)
    {
        x = x->Left();
    }
    return x;
}


    
