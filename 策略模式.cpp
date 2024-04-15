#include <bits/stdc++.h>

using ll = long long;

// 策略接口
class strategy {
 public:
  virtual void out() = 0;
};

// 具体策略
class A : public strategy {
 public:
  void out() override {
    std::cout << "A" << std::endl;
  }
};
class B : public strategy {
 public:
  void out() override {
    std::cout << "B" << std::endl;
  }
};

// 上下文
class Context {
 private:
  strategy *s;
 public:
  Context(strategy *s) : s(s) {}
  void set(strategy *s) {
    this->s = s;
  }
  void out() {
    s->out();
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  A a;
  B b;
  Context con(&a);
  con.out();

  con.set(&b);
  con.out();

  return 0;
}
