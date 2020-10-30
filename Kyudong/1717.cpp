/*#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)


int n, m;
int arr[100001];

int find_root(int a)
{
	if (arr[a] == a)
		return a;
	else
		return arr[a] = find_root(arr[a]);
}

void union_func(int a,int b)
{
	int aParent = find_root(a);
	int bParent = find_root(b);
	if (aParent != bParent) arr[aParent] = bParent;
}



int main()
{
	int expr, a, b;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
	}

	while (m--)
	{
		cin >> expr >> a >> b;
		
		if (expr == 0)
		{
			if (a == b) continue;
			union_func(a, b);
		}
		else
		{
			int aParent = find_root(a);
			int bParent = find_root(b);
			if (aParent != bParent) printf("NO\n");
			else printf("YES\n");
		}

	}

	return 0;
}*/

#include <cstdio>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

vector<int>root;

int find(int node) {
	if (root[node] == node)
		return node;
	else
		return root[node] = find(root[node]);
}

void uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	root[pb] = pa;
}

int main() {
	int num, calc;
	scanf("%d %d", &num, &calc);


	for (int i = 0; i <= num; i++)
		root.push_back(i);

	int cmd, a, b;
	for (int i = 0; i < calc; i++) {
		scanf("%d %d %d", &cmd, &a, &b);

		if (cmd == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}
