#include "div.h"

Div::Div(int a, int b)
{
    this->a = a;
    this->b = b;
}

Div::~Div()
{

}

int Div::ret()
{
    return a/b;
}