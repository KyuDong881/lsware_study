#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, k;
int answer = 0;


void Input()
{
	cin >> N >> k;
}


void Solution()
{
	int start = 1;
	int end = k;
	while (start <= end)
	{
		int count = 0;
		int mid = (start + end) / 2;
		for (int i = 1; i <= N; i++)
		{
			count = count + min(mid / i, N);
		}
		if (count < k)
		{
			start = mid + 1;			
		}
		else
		{
			answer = mid;
			end = mid - 1;
		}
	}
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solution();
	return 0;
}