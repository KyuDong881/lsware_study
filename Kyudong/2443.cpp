#include <vector>
#include <cmath>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;

#define MAX 1000000
vector < ll > segmentree;

int N;
int arr[MAX+5];

vector<pair<int, pair<int, int>>> cmd;

/*int Make_SegementTree(int node, int start, int end)
{
	if (start == end) return segmentree[node] = arr1[start];
	
	int mid = (start + end) / 2;
	int left_result = Make_SegementTree(node * 2, start, mid);
	int right_result = Make_SegementTree(node * 2 + 1, mid + 1, end);
	segmentree[node] = left_result + right_result;

	return segmentree[node];
}*/
int Sum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segmentree[node];

	int mid = (start + end) / 2;
	int left_result = Sum(node * 2, start, mid, left, right);
	int rignt_result = Sum(node * 2 + 1, mid + 1, end, left, right);
	return left_result + rignt_result;
}

void update_tree(int node, int start, int end, int idx, int depth)
{
	if (idx<start || idx>end) return;
	segmentree[node] = segmentree[node] + depth;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update_tree(node * 2, start, mid, idx, depth);
		update_tree(node * 2 + 1, mid + 1, end, idx, depth);
	}

}

int solution(int node, int start, int end, int cnt)
{
	if (start == end) return start;
	int mid = (start + end) / 2;
	if (segmentree[node * 2] >= cnt) return solution(node * 2, start, mid, cnt);
	return solution(node * 2 + 1, mid + 1, end, cnt-segmentree[node*2]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b;
			cin >> b;
			cmd.push_back(make_pair(a, make_pair(b, -1)));
		}
		else
		{
			int b;
			int c;
			cin >> b >> c;
			cmd.push_back(make_pair(a, make_pair(b, c)));
		}
	}
	int tree_height = (int)ceil(log2(100000));
	int tree_size = (1 << (tree_height + 1));//트리 높이의 제곱
	segmentree.resize(tree_size);
	
	for (int i = 0; i < cmd.size(); i++)
	{
		int command = cmd[i].first;
		if (command == 1)
		{
			int idx = cmd[i].second.first;
			int pos = solution(1, 1, 100000, idx);
			cout << pos << '\n';
			arr[pos]--;
			update_tree(1, 1, 100000, pos, -1);
		}
		else
		{
			int idx = cmd[i].second.first;
			int value = cmd[i].second.second;

			arr[idx] = arr[idx] + value;
			update_tree(1, 1, 100000, idx, value);
		}
	}

	return 0;
}