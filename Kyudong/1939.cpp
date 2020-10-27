#include<cstdio>
#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int max_cost, a, b, c, n, m, start_node, end_node = 0;

int ans = 1;

struct node {
	int cur;
	int cost;
};
vector<node> v[10001];

bool vis[10001];

void bfs(int mid)
{
	queue<int> q;
	vis[start_node] = true;
	q.push(start_node);
	while (!q.empty())
	{
		int cur_node = q.front();
		q.pop();
		for (int i = 0; i < v[cur_node].size(); i++)
		{
			node next = v[cur_node][i];
			int next_node = next.cur;
			int next_cost = next.cost;

			if (vis[next_node] != true && next_cost >= mid)
			{
				vis[next_node] = true;
				q.push(next_node);
			}

		}
	}
}




void binary_search()
{
	int st = 1;
	int ed = max_cost;
	int mid = 0;
	while (st <= ed)
	{
		mid = (st + ed) / 2;

		for (int i = 1; i <= n; i++) vis[i] = false;
		
		bfs(mid);

		if (vis[end_node]==true)
		{
			ans = max(ans, mid);
			st = mid + 1;
		}
		else
		{
			ed = mid - 1;
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		max_cost = max(max_cost, c);
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	scanf("%d %d", &start_node, &end_node);

	binary_search();
	printf("%d", ans);

	return 0;

}