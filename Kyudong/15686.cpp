#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <climits>
#pragma warning(disable:4996)

using namespace std;
int n, m;
int board[51][51];
int ans = 10000;
vector<pair<int, int>> home,chicken,v;

int chicken_num;
bool check[14];


int cal_distance()
{
	int ans_tmp = 0;
	for (int i = 0; i < home.size(); i++)
	{
		int h_y = home[i].first;
		int h_x = home[i].second;
		int tmp_dist = 1000;
		for (int j = 0; j < v.size(); j++)
		{
			int c_y = v[j].first;
			int c_x = v[j].second;
			tmp_dist = min(tmp_dist, (abs(h_x - c_x) + abs(h_y - c_y)));
		}
		ans_tmp += tmp_dist;
	}
	return ans_tmp;
}

void select_chicken(int start,int cnt)
{
	if (cnt == m)
	{
		ans = min(ans, cal_distance());
		return;
	}
	/*for (int i = 0; i < chicken_num; i++)
	{
		if (check[i] == true) continue;
		check[i] = true;
		v.push_back(chicken[i]);
		select_chicken(i, cnt + 1);
		v.pop_back();
		check[i] = false;
	}*/ //순열로 푸니까 시간초과 뜸 
	for (int i = start; i < chicken_num; i++)
	{
		if (check[i] == true) continue;
		check[i] = true;
		v.push_back(chicken[i]);
		select_chicken(i,cnt + 1);
		v.pop_back();
		check[i] = false;
	}

}


int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &board[i][j]);
			if (board[i][j] == 2)
				chicken.push_back(make_pair(i, j));
			if (board[i][j] == 1)
				home.push_back(make_pair(i, j));
		}
	}

	chicken_num = chicken.size();
	select_chicken(0,0);

	printf("%d", ans);
	return 0;

}
