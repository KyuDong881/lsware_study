#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int board[101][101] = { 0, };
int visit[101][101] = { 0, };
int melt_c[101][101] = { 0, };
int N, M;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ans = 0;
queue<pair<int, int>> q;
void melt();
int remain = 0;
vector<pair<int, int>> cCheese;
void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}
}

void bfs(int y, int x)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visit[i][j] = 0;

	remain = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 1)
			{
				remain = 1;
				break;
			}
		}
		if (remain == 1) break;
	}

	if (remain == 1)
	{
		visit[y][x] = 1;
		q.push(make_pair(y, x));
		while (!q.empty())
		{
			int yy = q.front().first;
			int xx = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = yy + dy[dir];
				int nx = xx + dx[dir];

				if (nx < 0 || ny < 0 || nx >= M || ny >= M) continue;
				if (board[ny][nx] == 1)
				{
					cCheese.push_back(make_pair(ny, nx));
					continue;
				}
				if (visit[ny][nx] == 1) continue;

				visit[ny][nx] = 1;
				q.push(make_pair(ny, nx));
			}
		}
		melt();
	}
	else return;

}

void melt()
{
	if (cCheese.size() == 0) return;
	else
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				melt_c[i][j] = 0;

		for (int i = 0; i < cCheese.size(); i++)
		{
			int cy = cCheese[i].first;
			int cx = cCheese[i].second;
			melt_c[cy][cx]++;
		}
		for (int i = 0; i < cCheese.size(); i++)
			cCheese.pop_back();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (melt_c[i][j] > 1)
				{
					board[i][j] = 0;
				}
			}
		}
		ans++;
		bfs(0, 0);
	}

}


int main()
{
	Input();
	bfs(0, 0);
	cout << ans;

	return 0;
}
