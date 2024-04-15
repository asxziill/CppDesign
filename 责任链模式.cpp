#include <bits/stdc++.h>

using ll = long long;

class H {
 protected:
  std::shared_ptr<H> su;
 public:
  void set(std::shared_ptr<H> s) {
    this->su = s;
  }

  virtual void out(int x) = 0;
};

class Neg : public H {
 public:
  void out(int x) override {
    if (x < 0) {
      std::cout << "-" << std::endl;
    } else if (su != nullptr) {
      su->out(x);
    }
  }
};
class Z : public H {
 public:
  void out(int x) override {
    if (x == 0) {
      std::cout << "0" << std::endl;
    } else if (su != nullptr) {
      su->out(x);
    }
  }
};
class B : public H {
 public:
  void out(int x) override {
    if (x > 0) {
      std::cout << "+" << std::endl;
    } else if (su != nullptr) {
      su->out(x);
    }
  }
};


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::shared_ptr<H> neg = std::make_shared<Neg>();
  std::shared_ptr<H> z = std::make_shared<Z>();
  std::shared_ptr<H> b = std::make_shared<B>();

  neg->set(z);
  z->set(b);

  neg->out(-10);
  neg->out(20);
  neg->out(0);

  return 0;
}
