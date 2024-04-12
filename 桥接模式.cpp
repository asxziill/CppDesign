#include <bits/stdc++.h>

using ll = long long;

//抽象W
class W {
 public:
  virtual void out() = 0;
};

class WA : public W {
 public:
  void out() {
    std::cout << "WA" << std::endl;
  }
};

class WB : public W {
 public:
  void out() {
    std::cout << "WB" << std::endl;
  }
};

//桥接W
class Win {
 protected:
  W* w;
 public:
  Win(W* w) : w(w) {}
  virtual void out() {
    w->out();
  }
};

//进一步实现Win
class TW : public Win {
 public:
  TW(W* w) : Win(w) {}
  void out() override {
    std::cout << "TTT: ";
    w->out(); 
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Win* wa = new Win(new WA());
  Win* wb = new TW(new WB());

  wa->out();
  wb->out();
  return 0;
}
