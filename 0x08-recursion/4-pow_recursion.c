#include "main.h"

/**
* _pow_recursion - returns value of x raised to power of y
* @x: integer base
* @y: integer exponent
* Return: integer power
*/

int _pow_recursion(int x, int y)
{
double result;

if (y > 0)
{
result = x * _pow_recursion(x, y - 1);
return (result);
}
else if (y == 0)
{
return (1);
}
else
{
return (-1);
}
}
