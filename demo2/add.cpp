#include "add.h"

Add::Add(int a, int b)
{
    this->a = a;
    this->b = b;
}

Add::~Add()
{

}

int Add::ret()
{
    return a + b;
}