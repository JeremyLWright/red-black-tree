#include <gtest/gtest.h>
#include <limits.h>
#include "RedBlackNode.h"


class RedBlackNodeTest: public ::testing::Test {
    protected:
        virtual void SetUp() {
            root = RedBlackNode::construct(7);
            root->Left(RedBlackNode::construct(6));
            root->Left()->Parent(root);
            root->Right(RedBlackNode::construct(8));
            root->Right()->Parent(root);
            root->Right()->Color(RedBlackNode::BLACK);
            nil = RedBlackNode::construct(0);
            root->Parent(nil);

        }

        RedBlackNode::Ptr root;
        RedBlackNode::Ptr nil;

};


TEST_F(RedBlackNodeTest, Left)
{
    EXPECT_EQ(root->Left()->Key(), 6);
}

TEST_F(RedBlackNodeTest, Right)
{
    EXPECT_EQ(root->Right()->Key(), 8);
}

TEST_F(RedBlackNodeTest, isRed)
{
    EXPECT_TRUE(root->isRed());
    EXPECT_FALSE(root->Right()->isRed());
    EXPECT_TRUE(root->Left()->isRed());
}

TEST_F(RedBlackNodeTest, Key)
{
    EXPECT_EQ(root->Key(), 7);
    EXPECT_EQ(root->Right()->Key(), 8);
    EXPECT_EQ(root->Left()->Key(), 6);
}

TEST_F(RedBlackNodeTest, Parent)
{
    EXPECT_EQ(root, root->Right()->Parent());
    EXPECT_EQ(root, root->Left()->Parent());
}



