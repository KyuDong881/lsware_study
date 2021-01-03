#include <array>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

constexpr int kMax = 100001;

std::vector<int> g_path;

static int bfs(int start, int end) {
  std::queue<std::pair<int, int>> jobs;
  std::pair<int, int> data;
  int result = std::numeric_limits<int>::max();
  bool visited[kMax] = {0};
  int index;
  std::array<int, kMax> parent;

  jobs.emplace(start, 0);
  visited[start] = true;

  while (!jobs.empty()) {
    data = jobs.front();
    jobs.pop();

    if (data.first == end) {
      index = data.first;

      while (start != index) {
        g_path.emplace_back(index);
        index = parent[index];
      }

      g_path.emplace_back(start);
      return data.second;
    }

    index = data.first + 1;
    if (kMax > index && !visited[index]) {
      jobs.emplace(index, data.second + 1);
      visited[index] = true;
      parent[index] = data.first;
    }

    index = data.first - 1;
    if (0 <= index && !visited[index]) {
      jobs.emplace(index, data.second + 1);
      visited[index] = true;
      parent[index] = data.first;
    }

    index = data.first * 2;
    if (kMax > index && !visited[index]) {
      jobs.emplace(index, data.second + 1);
      visited[index] = true;
      parent[index] = data.first;
    }
  }

  return result;
}

int main() {
  int start, end;

  scanf("%d", &start);
  scanf("%d", &end);

  printf("%d\n", bfs(start, end));
  for (end = g_path.size() - 1; end >= 0; --end) {
    printf("%d ", g_path[end]);
  }
  return EXIT_SUCCESS;
}
