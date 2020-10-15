#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int paper_num[] = { 0,5,5,5,5,5 };
int board[10][10];

int ans = INT_MAX;
int one_num = 0; //1�� ����

int checkboard(int y, int x, int size)
{
	if (x + size > 10 || y + size > 10 || paper_num[size] == 0) return 0; //���� üũ

	for (int i = y; i < y+size; i++)
		for (int j = x; j < x+size; j++)
			if (board[i][j] == 0) return 0; //1�� ��� üũ

	return 1;//������ ����
}

void putpaper(int y, int x, int size)
{
	paper_num[size]--;
	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			board[i][j] = 0; 
	
	one_num = one_num - (size * size); //���� 1
	return;
	//size�� �����̷� (y,x)���� ����
}

void resetpaper(int y, int x, int size)
{
	paper_num[size]++;

	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			board[i][j] = 1;

	one_num = one_num + (size*size);
	return;
	//size�� �����̷� (y,x)���� ���� ������ ����
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
						solution(use + 1, i, j+k);//���⸦ �������� dfs������ j+k(k�� size)�ؾ� �Ǵµ� �ܼ��� j+1�� �ؼ� ��� ������ dfs�� depth
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