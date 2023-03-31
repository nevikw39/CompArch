#include <stdio.h>
#include <stdlib.h>

int result;

int gcd(int a, int b)
{
    int remainder = a % b;

    if (remainder == 0)
        return b;

    return gcd(b, remainder);
}

int main()
{
	result = gcd(756, 996);
	printf("%d\n", result);
    return 0;
}
