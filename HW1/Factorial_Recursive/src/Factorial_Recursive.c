#include <stdio.h>

int recur(int n)
{
   if (n == 1)
		return 1;
   else
		return n * recur(n - 1);
}

int main(void)
{
	int sum = recur(10);
	printf("%d\n", sum);
	return 0;
}
