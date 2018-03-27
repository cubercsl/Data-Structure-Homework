#include "tree.h"
#include <iostream>

int main()
{
    Tree t;
    t.test();
    std::cout << "宽度:" << t.width() << std::endl;
    std::cout << "深度:" << t.depth() << std::endl;
}