#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string str;
int N;
int ans = INT_MIN;

int Calculate(int a, int b, char expr)
{
	if (expr == '+') return a + b;
	else if (expr == '-') return a - b;
	else return a * b;
}

void solution(int index, int value)
{
	if (index >= N)
	{
		ans = max(ans, value);
		return;
	}
	char op;
	if (index == 0)	op = '+';
	else op = str[index - 1];

	if (index + 2 < N)//°ýÈ£¹­±â
	{
		int temp = Calculate(str[index] - '0', str[index + 2] - '0', str[index + 1]);
		solution(index + 4, Calculate(value, temp, op));
	}
	
	solution(index + 2, Calculate(value, str[index] - '0', op));

}

int main()
{
	cin >> N >> str;
	solution(0, 0);
	cout << ans;

	return 0;

}