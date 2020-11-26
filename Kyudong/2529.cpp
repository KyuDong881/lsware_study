#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int k;
char expr[10];
bool check[10];
vector<string> str;
string init;

void Input()
{
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> expr[i];
}

void recul(int idx, string cur, int Inow)
{
	if (idx == k)
	{
		str.push_back(cur);
		return;
	}

	if (Inow == -1)
	{
		for (int i = 0; i < 10; i++)
		{
			check[i] = true;
			char tmp = i + '0';
			recul(idx, cur + tmp, i);
			check[i] = false;
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (check[i]) continue;
			else
			{
				if (expr[idx] == '<')
				{
					if (i > Inow)
					{
						check[i] = true;
						char tmp = i + '0';
						recul(idx + 1, cur + tmp, i);
						check[i] = false;
					}
				
				}
				else
				{
					if (i < Inow)
					{
						check[i] = true;
						char tmp = i + '0';
						recul(idx + 1, cur + tmp, i);
						check[i] = false;
					}
				
				}
			}
		}
		return;
	}
}

void Solution()
{
	recul(0, init, -1);
//	sort(str.begin(), str.end());
	cout << str[0] << '\n' << str[str.size()-1];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solution();

}