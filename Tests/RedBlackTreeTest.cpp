#include <gtest/gtest.h>
#include <limits.h>
#include "RedBlackTree.h"


class RedBlackTreeTest: public ::testing::Test {
    protected:
        virtual void SetUp() {
            RB_Ex1 = RedBlackTree::construct();
            RB_Ex1->Insert(2);
            RB_Ex1->Insert(4);
            RB_Ex1->Delete(3);
            
            RB_Ex2 = RedBlackTree::construct();
            RB_Ex2->Insert(5, RedBlackNode::BLACK);
            RB_Ex2->Insert(3, RedBlackNode::BLACK);
            RB_Ex2->Insert(17, RedBlackNode::RED);
            RB_Ex2->Insert(15, RedBlackNode::BLACK);
            RB_Ex2->Insert(13, RedBlackNode::RED);
            RB_Ex2->Insert(16, RedBlackNode::RED);
            RB_Ex2->Insert(20, RedBlackNode::BLACK);

            RB_Ex2->Insert(12);

            RB_Ex3 = RedBlackTree::construct();
            RB_Ex3->Insert(9, RedBlackNode::BLACK);
            RB_Ex3->Insert(5, RedBlackNode::BLACK);
            RB_Ex3->Insert(2, RedBlackNode::RED);
            RB_Ex3->Insert(1, RedBlackNode::BLACK);
            RB_Ex3->Insert(3, RedBlackNode::BLACK);
            RB_Ex3->Insert(4, RedBlackNode::RED);
            RB_Ex3->Insert(8, RedBlackNode::BLACK);
            RB_Ex3->Insert(15, RedBlackNode::BLACK);
            RB_Ex3->Insert(13, RedBlackNode::BLACK);
            RB_Ex3->Insert(16, RedBlackNode::BLACK);

            RB_Ex3->Delete(8);
            
        }

        RedBlackTree::Ptr RB_Ex3;
        RedBlackTree::Ptr RB_Ex2;
        RedBlackTree::Ptr RB_Ex1;

};


TEST_F(RedBlackTreeTest, Example_1_Output)
{
    PreOrderIterator it = RB_Ex1->getPreOrderItr();
    ++it;
    EXPECT_EQ((*it)->Key(), 2);
    EXPECT_FALSE((*it)->isRed());
    ++it;
    EXPECT_EQ((*it)->Key(), 4);
    EXPECT_TRUE((*it)->isRed());
}

TEST_F(RedBlackTreeTest, Example_2_Output)
{
    PreOrderIterator it = RB_Ex2->getPreOrderItr();
    int expected_keys[] = {15, 5, 3, 13, 12, 17, 16, 20} ;
    int* keys = expected_keys;
    while(it.complete() == false)
    {
        ++it;
        EXPECT_EQ(*keys, (*it)->Key());
        ++keys;
    }

}

TEST_F(RedBlackTreeTest, Example_3_Output)
{
    PreOrderIterator it = RB_Ex3->getPreOrderItr();
    int expected_keys[] = {9,2,1,4,3,5,15,13,16};
    int* keys = expected_keys;
    while(it.complete() == false)
    {
        ++it;
        EXPECT_EQ(*keys, (*it)->Key());
        ++keys;
    }

}



