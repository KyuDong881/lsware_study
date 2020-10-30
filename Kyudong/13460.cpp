#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int n, m;
char board[11][11];

const int dx[4] = { 0,1,-1,0 };
const int dy[4] = { 1,0,0,-1 };

int ans;

struct INFO {
	int rx, ry, bx, by, count;
};

INFO start;

int bfs()
{
	int ret = -1;
	int vis[10][10][10][10] = { 0, };
	queue<INFO> q;
	q.push(start);
	vis[start.ry][start.rx][start.by][start.by] = 1;
	while (!q.empty())
	{
		INFO cur = q.front();
		q.pop();
		if (cur.count > 10) break;
		if (board[cur.ry][cur.rx] == 'O'&&board[cur.by][cur.bx] != 'O')
		{
			ret = cur.count;
			break;
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int next_rx = cur.rx;
			int next_ry = cur.ry;
			int next_bx = cur.bx;
			int next_by = cur.by;

			while (1)
			{
				if (board[next_ry][next_rx] != '#' && board[next_ry][next_rx] != 'O')
				{
					next_ry += dy[dir];
					next_rx += dx[dir];
				}
				else
				{
					if (board[next_ry][next_rx] == '#')
					{
						next_ry -= dy[dir];
						next_rx -= dx[dir];
						break;
					}
				}
			}
			while (1)
			{

				if (board[next_by][next_bx] != '#'&&board[next_by][next_bx] != 'O')
				{
					next_by += dy[dir];
					next_bx += dx[dir];
				}
				else
				{
					if (board[next_by][next_bx] == '#')
					{
						next_by -= dy[dir];
						next_bx -= dx[dir];
						break;
					}
				}
			}

			if (next_ry == next_by && next_rx == next_bx)
			{
				if (board[next_ry][next_rx] != 'O')
				{
					int r_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
					int b_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);

					if (r_dist > b_dist)
					{
						next_ry -= dy[dir];
						next_rx -= dx[dir];
					}
					else
					{
						next_by -= dy[dir];
						next_bx -= dx[dir];
					}
				}
			}

			if (vis[next_ry][next_rx][next_by][next_bx] == 0)
			{
				vis[next_ry][next_rx][next_by][next_bx] = 1;
				INFO next_q;
				next_q.rx = next_rx;
				next_q.ry = next_ry;
				next_q.bx = next_bx;
				next_q.by = next_by;
				next_q.count = cur.count + 1;
				q.push(next_q);
			}

		}
	}

	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", board[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'R')
			{
				start.rx = j;
				start.ry = i;
			}
			if (board[i][j] == 'B')
			{
				start.bx = j;
				start.by = i;
			}
		}
	}
	start.count = 0;

	ans = bfs();
	printf("%d", ans);

}