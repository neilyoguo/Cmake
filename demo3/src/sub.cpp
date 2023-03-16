#include "sub.h"

Sub::Sub(int a, int b)
{
    this->a = a;
    this->b = b;
}

Sub::~Sub()
{

}

int Sub::ret()
{
    return a - b;
}