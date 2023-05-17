#include <iostream>
#include <cmath>
using namespace std;
// Refernce : https://atcoder.jp/contests/dp/tasks/dp_a

//==============testcase1==============
int arr[] = { 10, 30, 40, 20 };
int n = 4;
//output: 30
//=====================================

//==============testcase2==============
//int arr[] = { 30, 10, 60, 10, 60, 50 };
//int n = 6;
//output: 40
//=====================================

int afrog1(int arr[], int n) {
	//base case
	int dp[n];
	dp[0] = 0;
	dp[1] = abs(arr[1] - arr[0]);
	for (int i = 2; i < n; i++) {
		dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));
	}

	return dp[n - 1];
}

int main() {
	int temp = afrog1(arr, n);
	cout << "output: " << temp;
	return 0;
}