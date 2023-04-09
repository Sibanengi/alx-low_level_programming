#include <stdio.h>
#include "main.h"


/**
* flip_bits - returns the number of bits you would need
* to flip to get from one number to another
* @n: the first number
* @m: the second number
*
* Return: the number of bits that need to be flipped
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int xor_result = n ^ m;
unsigned int count = 0;

while (xor_result)
{
count += xor_result & 1;
xor_result >>= 1;
}

return (count);
}
