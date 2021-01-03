#include <array>
#include <bitset>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <queue>
#include <vector>

struct NodeInfo {
  NodeInfo(int next, int cost) : next(next), cost(cost) {}

  int next;
  int cost;
};

struct CompareNode {
  bool operator()(const NodeInfo& lhs, const NodeInfo& rhs) {
    return lhs.cost > rhs.cost;
  }
};

class Kingdom {
 public:
  void Input() {
    int row, col;

    scanf("%d", &num_planets_);
    planets_.assign(num_planets_, std::vector<int>(num_planets_, 0));

    for (row = 0; row < num_planets_; ++row) {
      for (col = 0; col < num_planets_; ++col) {
        scanf("%d", &planets_[row][col]);
      }
    }
  }

  int64_t GetMinFlowCost() {
    std::priority_queue<NodeInfo, std::vector<NodeInfo>, CompareNode> pq;
    std::vector<int> costs_(num_planets_, std::numeric_limits<int>::max());
    std::vector<int> parents_(num_planets_, -1);
    std::bitset<kMaxNodes> visited_;
    int node;
    int next;
    int64_t total = 0;

    pq.emplace(0, 0);
    costs_[0] = 0;

    while (!pq.empty()) {
      node = pq.top().next;
      pq.pop();

      if (visited_[node]) continue;

      visited_[node] = true;

      for (next = 0; next < num_planets_; ++next) {
        if (next == node) continue;
        if (0 == planets_[node][next]) continue;
        if (visited_[next] || costs_[next] <= planets_[node][next]) continue;

        costs_[next] = planets_[node][next];
        parents_[next] = node;
        pq.emplace(next, costs_[next]);
      }
    }

    for (node = 0; node < num_planets_; ++node) {
      total += costs_[node];
    }

    return total;
  }

 private:
  static constexpr int kMaxNodes = 1001;

  int num_planets_;
  std::vector<std::vector<int>> planets_;
};

int main() {
  Kingdom kingdom;

  kingdom.Input();
  printf("%ld\n", kingdom.GetMinFlowCost());
  return EXIT_SUCCESS;
}
