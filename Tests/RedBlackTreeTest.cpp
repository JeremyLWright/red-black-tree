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
        }

        RedBlackTree::Ptr RB_Ex1;
        RedBlackNode::Ptr RB_Ex1_root() {
            return RB_Ex1->root;
        }

};


TEST_F(RedBlackTreeTest, Example_1_Output)
{
    RedBlackNode::Ptr root = RB_Ex1_root();
    EXPECT_EQ(root->Key(), 2);
    EXPECT_EQ(root->Right()->Key(), 4);
    EXPECT_FALSE(root->isRed());
    EXPECT_TRUE(root->Right()->isRed());
}



