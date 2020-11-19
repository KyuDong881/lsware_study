#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> Node;
vector<pair<int, pair<int, int>>> krus;
int Parent[100002];
vector<int> line;
int ans = 0;
int n;
int node1, node2, weight;
void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> node1 >> node2 >> weight;
		krus.push_back(make_pair(weight, make_pair(node1, node2)));
	}

	for (int i = 1; i <= n; i++)
		Parent[i] = i;

}

bool compare(Node a, Node b)
{
	if (a.first > b.first) return true;
	else return false;
}

int Find_Parent(int x)
{
	if (x == Parent[x]) return x;
	else return Parent[x] = Find_Parent(Parent[x]);
}

void Union(int x, int y, int Cost)
{
	x = Find_Parent(x);
	y = Find_Parent(y);

	if (x == y) return;
	Parent[y] = x;
	n--;
}
bool check_root(int a, int b)
{
	if (Find_Parent(a) == Find_Parent(b))
		return true;
	else return false;
}


void Solve()
{
	sort(krus.begin(), krus.end(), compare);
	for (int i = 0; i < krus.size(); i++)
	{
		if (check_root(krus[i].second.first, krus[i].second.second) == false)
		{
			Union(krus[i].second.first, krus[i].second.second, krus[i].first);
			line.push_back(krus[i].first);
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
	for (int i = 0; i < line.size() - 1; i++)
	{
		ans = ans + line[i];
	}
	
	cout << ans;
	return 0;
}