#include <iostream>
#include "add.h"
#include "sub.h"
#include "div.h"
#include "mutl.h"

int main (int argc , char *argv[])
{

    Add add(1, 2);
    int ret = add.ret();
    std:: cout << ret << std::endl;
    Sub sub(5, 1);
    ret = sub.ret();
    std:: cout << ret << std::endl;
    Div div(15, 3);
    ret = div.ret();
    std:: cout << ret << std::endl; 
    Mutl mutl(15, 3);
    ret = mutl.ret();
    std:: cout << ret << std::endl; 
    return 0;
    
}