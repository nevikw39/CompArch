#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int n, *arr;

inline int abs(int x) { return (x ^ (x >> 31)) - (x >> 31); }
inline int min(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int afrog1()
{
	int *a0 = arr;
	int64_t a1 = n,
			s0, // dp[i-2]
	    	s1 = 0, // dp[i-1]
	    	s2,		// dp[i]
    		s3,		// arr[i-2]
	    	s4,		// arr[i-1]
	    	s5,		// arr[i]
	    	t0, t1, t2, t3, t4, t5, t6;

	a0 = a0 + 2;
	a1 = a1 - 2;

	// s2 = abs(a0[-1] - a0[-2]);
	s4 = (-2)[a0];
	s5 = (-1)[a0];
	s2 = s4 - s5;
	t0 = s2 >> 63;
	t1 = s2 ^ t0;
	s2 = t1 - t0;

	if (!n)
		goto loop_tail;

loop:
	s0 = s1;
	s1 = s2;

	s3 = s4;
	s4 = s5;
	s5 = *a0;

	// t0 = dp[i - 1] + abs(arr[i] - arr[i - 1]);
	t0 = s5 - s4;
	t2 = t0 >> 63;
	t3 = t0 ^ t2;
	t0 = t3 - t2;
	t0 = s1 + t0;

	// t1 = dp[i - 2] + abs(arr[i] - arr[i - 2]);
	t1 = s5 - s3;
	t2 = t1 >> 63;
	t3 = t1 ^ t2;
	t1 = t3 - t2;
	t1 = s0 + t1;

	// s2 = min(t0, t1);
	t2 = t0 ^ t1;
	t3 = t0 < t1;
	t3 = -t3;
	t2 = t2 & t3;
	s2 = t1 ^ t2;

	a0 = a0 + 1;
	a1 = a1 - 1;

	if (a1)
		goto loop;
loop_tail:

	return s2;
}

int main()
{
	scanf("%d", &n);
	arr = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	printf("%d\n", afrog1());
	free(arr);
	return 0;
}