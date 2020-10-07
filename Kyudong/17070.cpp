#include <iostream>
#include <cstdio>
using namespace std;
int N;
int board[17][17];
int ans = 0;

void solution(int yy,int xx,int state)
{
	if (xx == N && yy == N)
	{
		ans++;
		return;
	}

	if (state == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				int ny = yy + 0;
				int nx = xx + 1;
				if (board[ny][nx] == 1 || nx > N) continue;
				int nstate = 0;
				solution(ny, nx, nstate);
			}
			else
			{
				int ny = yy + 1;
				int nx = xx + 1;
				if (board[ny - 1][nx] == 1 || board[ny][nx - 1] == 1 || board[ny][nx] == 1 || ny > N || nx > N) continue;
				int nstate = 2;
				solution(ny, nx, nstate);
			}
		}
	}

	if (state == 1)
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				int ny = yy + 1;
				int nx = xx + 0;
				if (board[ny][nx] == 1 || ny > N) continue;
				int nstate = 1;
				solution(ny, nx, nstate);
			}
			else
			{
				int ny = yy + 1;
				int nx = xx + 1;
				if (board[ny - 1][nx] == 1 || board[ny][nx - 1] == 1 || board[ny][nx] == 1 || ny > N || nx > N) continue;
				int nstate = 2;
				solution(ny, nx, nstate);
			}
		}
	}
	if (state == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				int ny = yy + 0;
				int nx = xx + 1;
				if (board[ny][nx] == 1 || nx > N) continue;
				int nstate = 0;
				solution(ny, nx, nstate);
			}
			else if(i==1)
			{
				int ny = yy + 1;
				int nx = xx + 0;
				if (board[ny][nx] == 1 || ny > N) continue;
				int nstate = 1;
				solution(ny, nx, nstate);
			}
			else
			{
				int ny = yy + 1;
				int nx = xx + 1;
				if (board[ny - 1][nx] == 1 || board[ny][nx - 1] == 1 || board[ny][nx] == 1 || ny > N || nx > N) continue;
				int nstate = 2;
				solution(ny, nx, nstate);
			}
		}
	}
	return;
}

int main()
{
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
			cin >> board[i][j];
	}

	solution(1, 2, 0);
	
	cout << ans;

}