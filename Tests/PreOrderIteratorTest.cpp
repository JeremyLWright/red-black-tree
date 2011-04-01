#include <gtest/gtest.h>
#include <limits.h>
#include "RedBlackTree.h"
#include <iostream>

using std::cout;

class PreOrderIteratorTest: public ::testing::Test {
    protected:
        virtual void SetUp() {
            RB_Ex1 = RedBlackTree::construct();
            RB_Ex1->Insert(1);
            RB_Ex1->Insert(2);
//            RB_Ex1->Insert(3);
       /*     RB_Ex1->Insert(4);
            RB_Ex1->Insert(5);
            RB_Ex1->Insert(6);
            RB_Ex1->Insert(7);
            RB_Ex1->Insert(8);
            RB_Ex1->Insert(9);
            RB_Ex1->Insert(10);
            RB_Ex1->Insert(11);
            RB_Ex1->Insert(12);
            RB_Ex1->Insert(13);
            RB_Ex1->Insert(14);
            RB_Ex1->Insert(15);
            RB_Ex1->Insert(16);
            RB_Ex1->Insert(17);
            RB_Ex1->Insert(18);*/

        }

        RedBlackTree::Ptr RB_Ex1;

};


TEST_F(PreOrderIteratorTest, Example_1_Output)
{
    PreOrderIterator it = RB_Ex1->getPreOrderItr();
    while((it.complete()))
    {
        cout << (*it)->Key() << ", " ;
    }
}
