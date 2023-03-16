#include "mutl.h"

Mutl::Mutl(int a, int b)
{
    this->a = a;
    this->b = b;
}

Mutl::~Mutl()
{

}

int Mutl::ret()
{
    return a * b;
}