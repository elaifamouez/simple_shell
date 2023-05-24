#include "shell.h"
/**
 * _atoi - convert a string to an integer.
 *
 * @s: pointer to str origen.
 * Return: int of string or 0.
 */
int _atoi(char *s)
{
int sign = 1;
unsigned int number = 0;

while (!('0' <= *s && *s <= '9') && *s != '\0')
{
if (*s == '-')
sign *= -1;
if (*s == '+')
sign *= +1;
s++;
}
while ('0' <= *s && *s <= '9' && *s != '\0')
{
number = (number * 10) + (*s - '0');
s++;
}
return (number * sign);
}
