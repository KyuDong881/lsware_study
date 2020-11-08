#include <array>
#include <cstdio>

class Ad {
 public:
  void Init();

  int GetMinTextSize() const;

 private:
  static constexpr size_t kMaxSize = 1000001;

  std::array<char, kMaxSize> text_;
  int size_;
};

int main() {
  Ad ad;

  ad.Init();
  printf("%d\n", ad.GetMinTextSize());
  return 0;
}

void Ad::Init() { scanf("%d%s", &size_, text_.data()); }

int Ad::GetMinTextSize() const {
  int i = 1, j = 0;
  std::array<int, kMaxSize> pattern_info;

  for (; i < size_; ++i) {
    while (text_[i] != text_[j] && j > 0) {
      j = pattern_info[j - 1];
    }

    if (text_[i] == text_[j]) {
      pattern_info[i] = ++j;
    }
  }

  return size_ - pattern_info[size_ - 1];
}
