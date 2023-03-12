#include <stdio.h>

int iter(int n)
{
	int sum = 1;
	for (int i = 1; i <= n; i++){
		sum *= i;
	}
	return sum;
}

int main(void)
{
	int sum = iter(10);
	printf("%d\n", sum);
	return 0;
}
