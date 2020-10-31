#include <cmath>
#include <cstdio>
#include <limits>
#include <queue>
#include <vector>

struct Pos {
  Pos(int x, int y) : x(x), y(y) {}

  int x;
  int y;
};

struct Store {
  Store(int x, int y) : pos(x, y) {}

  Pos pos;
  bool closed = true;
};

class City {
 public:
  enum CellType { kNone, kHouse, kStore };

  City() {}
  ~City() {}

  void Init();

  void CalcMinStoreDistance(int store_id, int open_count);

  int GetMinDistance() const { return min_distance_; }

 private:
  struct Job {
    Job(int store_id, int open_count)
        : store_id(store_id), open_count(open_count) {}

    int store_id;
    int open_count;
  };

  int GetMinStoreDistanceFromHouses();

  std::vector<Pos> houses_;
  std::vector<Store> stores_;

  int max_stores_;
  int min_distance_ = std::numeric_limits<int>::max();
};

namespace {

int GetDistanceBetweenPos(const Pos& lhs, const Pos& rhs) {
  return abs(lhs.x - rhs.x) + abs(lhs.y - rhs.y);
}

}  // namespace

int main() {
  City city;
  city.Init();
  city.CalcMinStoreDistance(0, 0);
  printf("%d\n", city.GetMinDistance());
  return 0;
}

void City::Init() {
  int size;
  int row, col;
  int tmp;

  scanf("%d%d", &size, &max_stores_);

  for (row = 0; row < size; ++row) {
    for (col = 0; col < size; ++col) {
      scanf("%d", &tmp);
      if (City::kHouse == tmp)
        houses_.emplace_back(row, col);
      else if (City::kStore == tmp)
        stores_.emplace_back(row, col);
    }
  }
}

void City::CalcMinStoreDistance(int store_id, int open_count) {
  static const int kStoreSize = stores_.size();

  if (kStoreSize < store_id) return;

  if (open_count == max_stores_) {
    min_distance_ = std::min(min_distance_, GetMinStoreDistanceFromHouses());
    return;
  }

  stores_[store_id].closed = false;
  CalcMinStoreDistance(store_id + 1, open_count + 1);

  stores_[store_id].closed = true;
  CalcMinStoreDistance(store_id + 1, open_count);
}

int City::GetMinStoreDistanceFromHouses() {
  int total = 0;
  int current;

  for (const auto& house : houses_) {
    current = std::numeric_limits<int>::max();
    for (const auto& store : stores_) {
      if (store.closed) continue;
      current = std::min(current, GetDistanceBetweenPos(house, store.pos));
    }

    total += current;
  }

  return total;
}
