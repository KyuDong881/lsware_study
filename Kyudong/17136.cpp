#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int paper_num[] = { 0,5,5,5,5,5 };
int board[10][10];

int ans = INT_MAX;
int one_num = 0; //1의 갯수

int checkboard(int y, int x, int size)
{
	if (x + size > 10 || y + size > 10 || paper_num[size] == 0) return 0; //범위 체크

	for (int i = y; i < y+size; i++)
		for (int j = x; j < x+size; j++)
			if (board[i][j] == 0) return 0; //1의 모양 체크

	return 1;//놓을수 있음
}

void putpaper(int y, int x, int size)
{
	paper_num[size]--;
	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			board[i][j] = 0; 
	
	one_num = one_num - (size * size); //남은 1
	return;
	//size의 색종이로 (y,x)부터 덮음
}

void resetpaper(int y, int x, int size)
{
	paper_num[size]++;

	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			board[i][j] = 1;

	one_num = one_num + (size*size);
	return;
	//size의 색종이로 (y,x)부터 덮은 색종이 리셋
}

void solution(int use, int y,int x)
{
	if (one_num == 0)
	{
		ans = min(ans, use);
		return;
	}
	
	for (int i = y; i < 10; i++)
	{
		for (int j = x; j < 10; j++)
		{
			if (board[i][j] == 1)
			{
				for (int k = 5; k > 0; k--)
				{
					if (checkboard(i, j, k) == 1)
					{
						putpaper(i, j, k);
						solution(use + 1, i, j+k);//여기를 다음꺼로 dfs들어가려면 j+k(k는 size)해야 되는데 단순히 j+1로 해서 계속 에러남 dfs이 depth
						resetpaper(i, j, k);
					}
				}
				return;
			}
		}
		x = 0;
	}

}

int main()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) one_num++;
		}
	solution(0,0,0);
	if (ans==INT_MAX) cout << -1;
	else cout << ans;
	return 0;

}