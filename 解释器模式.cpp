#include <bits/stdc++.h>

using ll = long long;

//基类
class Exp {
 public:
  virtual int get() = 0;
};

//对基类的解释
class Num : public Exp {
 private:
  int x;
 public:
  Num(int x) : x(x) {}
  int get() override {
    return x;
  }
};

class Plus : public Exp {
 private:
  std::shared_ptr<Exp> l;
  std::shared_ptr<Exp> r;
 public:
  Plus(std::shared_ptr<Exp> l, std::shared_ptr<Exp> r) : l(l), r(r) {}
  int get() override {
    return l->get() + r->get();
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::shared_ptr<Exp> exp = std::make_shared<Plus>(std::make_shared<Num>(2), std::make_shared<Num>(4));
  std::cout << exp->get() << std::endl;

  return 0;
}
