/**
 * @brief Main Application.
 *
 * @par
 * C++ Practicum Solutions
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#include <iostream>
#include <fstream>
#include <string>
#include "RedBlackTree.h"
#include "RedBlackNode.h"
#include <stdint.h>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::string;
enum {
    INSERT = 0,
    DELETE
};
int main(int argc, const char *argv[])
{
    if(argc != 2)
    {
        cout << "Incorrect Input Arguments." << endl;
        return -1;
    }
    ifstream fin(argv[1]);
    ofstream fout("output.txt");
    
    int color = 0;
    uint32_t key_value;
    int command = 0;
    int command_count;
    RedBlackTree::Ptr RB = RedBlackTree::construct();
    //Build the give tree
    do {
        fin >> color;
        if(color == -1)
            break;
        fin >> key_value;
        RB->Insert(key_value, static_cast<RedBlackNode::color_t>(color));
    } while(color != -1);
    
    fin >> command_count;
    //Process the commands
    while(command_count > 0)
    {
        fin >> command;
        fin >> key_value;
        if(command == INSERT)
            RB->Insert(key_value);
        else
            RB->Delete(key_value);
        --command_count;
    }
    
    PreOrderIterator it = RB->getPreOrderItr();
    while(it.complete() == false)
    {
        ++it;
        fout << (*it)->Color() << " " << (*it)->Key() << "\r\n";
    } 
    fout << -1 << "\r\n";
    return 0;
}
