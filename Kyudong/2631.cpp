#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int part = 0;
int arr_length;

int arr[202] = { 0, };
int dp[202] = { 0, };

void Input()
{
	int num;
	cin >> arr_length;
	for (int i = 1; i <= arr_length; i++)
	{
		cin >> num;
		arr[i] = num;
	}
}

void Solve()
{
	for (int i = 1; i <= arr_length; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		part = max(part, dp[i]);
	}
	int ans = arr_length - part;
	cout << ans;

}

int main()
{
	Input();
	Solve();

	return 0;
}