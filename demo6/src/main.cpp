#include <iostream>
#include "add.h"
int main (int argc , char *argv[])
{

    Add add(1, 2);
    int ret = add.ret();
    std:: cout << ret << std::endl;
    return 0;
    
}