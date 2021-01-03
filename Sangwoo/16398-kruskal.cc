#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

struct Edge {
  Edge(int left, int right, int cost) : left(left), right(right), cost(cost) {}
  bool operator<(const Edge& rhs) const { return (cost < rhs.cost); }

  int left;
  int right;
  int cost;
};

class Kingdom {
 public:
  void Input() {
    int row, col;
    int cost;

    scanf("%d", &planets_);
    for (row = 0; row < planets_; ++row) {
      for (col = 0; col < planets_; ++col) {
        scanf("%d", &cost);
        edges_.emplace_back(row, col, cost);
      }

      parents_[row] = row;
    }

    std::sort(edges_.begin(), edges_.end());
  }

  int64_t GetMinFlowCost() {
    int64_t flow_cost = 0;

    for (const auto& edge : edges_) {
      if (MergeNodes(edge.left, edge.right)) {
        flow_cost += edge.cost;
      }
    }

    return flow_cost;
  }

 private:
  static constexpr int kMaxNodes = 1000 + 1;

  int FindParent(int node) {
    if (node == parents_[node]) {
      return node;
    }

    return (parents_[node] = FindParent(parents_[node]));
  }

  bool MergeNodes(int lhs, int rhs) {
    lhs = FindParent(lhs);
    rhs = FindParent(rhs);

    if (lhs == rhs) {
      return false;
    }

    parents_[rhs] = lhs;
    return true;
  }

  int planets_;
  std::vector<Edge> edges_;
  int parents_[kMaxNodes];
};

int main() {
  Kingdom kingdom;

  kingdom.Input();
  printf("%ld\n", kingdom.GetMinFlowCost());
  return EXIT_SUCCESS;
}
