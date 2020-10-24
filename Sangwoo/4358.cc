#include <cassert>
#include <cstdio>
#include <cstring>
#include <memory>
#include <queue>

namespace {

int GetNumeric(char c) { return c - ' '; }

} // namespace

class Trie {
public:
  Trie() {}
  ~Trie() {}

  void Insert(const char *keys);

  void Print(int index) const;

  int GetMatchCount() const { return match_count_; }

private:
  static constexpr int kMaxChildrens = '~' - ' ' + 1;

  static int num_trees_;
  static char tree_[31];

  std::unique_ptr<Trie> children_[kMaxChildrens];
  int match_count_ = 0;
};

int main() {
  char tree[31];
  Trie tree_map;

  while (fgets(tree, sizeof(tree), stdin)) {
    tree[strlen(tree) - 1] = '\0';
    tree_map.Insert(tree);
  }

  tree_map.Print(0);
  return 0;
}

void Trie::Insert(const char *keys) {
  const int c = *keys;
  int index;

  if ('\0' == c) {
    ++match_count_;
    ++num_trees_;
    return;
  }

  index = GetNumeric(c);
  if (!children_[index]) {
    children_[index] = std::make_unique<Trie>();
  }

  children_[index]->Insert(keys + 1);
}

void Trie::Print(int index) const {
  int i;
  if (0 < match_count_) {
    tree_[index] = '\0';
    printf("%s %.4lf\n", tree_, 100.0 / num_trees_ * match_count_);
  }

  for (i = 0; i < kMaxChildrens; ++i) {
    if (!children_[i])
      continue;

    tree_[index] = i + ' ';
    children_[i]->Print(index + 1);
  }
}
