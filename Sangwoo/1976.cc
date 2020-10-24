#include <algorithm>
#include <cstdio>

class Route {
public:
  static constexpr int kMaxCities = 201;

  Route() {}
  ~Route() {}

  void Init(int cities, int num_travel_cities, const int *travel_cities) {
    cities_ = cities;
    num_travel_cities_ = num_travel_cities;
    travel_cities_ = travel_cities;
    std::fill_n(parent_, cities, -1);
  }

  int GetRoot(int node);

  void MergeNode(int node_a, int node_b);

private:
  int cities_ = 0;
  int num_travel_cities_ = 0;
  const int *travel_cities_ = nullptr;
  int parent_[kMaxCities];
};

int main() {
  int cities = 0;
  int num_travel_cities = 0;
  int i, j, tmp;
  Route route;
  int travel_cities[1001] = {0};

  scanf("%d%d", &cities, &num_travel_cities);
  route.Init(cities, num_travel_cities, travel_cities);
  for (i = 0; i < cities; ++i) {
    for (j = 0; j < cities; ++j) {
      scanf("%d", &tmp);
      if (0 == tmp)
        continue;

      route.MergeNode(i, j);
    }
  }

  scanf("%d", &tmp);
  tmp = route.GetRoot(tmp - 1);

  for (i = 1; i < num_travel_cities; ++i) {
    scanf("%d", &travel_cities[i]);
    if (tmp != route.GetRoot(travel_cities[i] - 1)) {
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");
  return 0;
}

int Route::GetRoot(int node) {
  if (0 > parent_[node]) {
    return node;
  }

  return parent_[node] = GetRoot(parent_[node]);
}

void Route::MergeNode(int node_a, int node_b) {
  node_a = GetRoot(node_a);
  node_b = GetRoot(node_b);

  if (node_a == node_b) {
    return;
  }

  if (node_a < node_b) {
    parent_[node_a] += parent_[node_b];
    parent_[node_b] = node_a;
  } else {
    parent_[node_b] += parent_[node_a];
    parent_[node_a] = node_b;
  }
}
