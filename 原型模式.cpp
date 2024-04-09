#include <bits/stdc++.h>

using ll = long long;

//原型通过实现clone避免了初始化的开销(如IO/读取等操作)
// 原型类
class Prototype {
 public:
  virtual Prototype* clone() = 0;
  virtual void out() = 0;
};

// 具体原型类 A
class PA : public Prototype {
 public:
  Prototype* clone() override {
      return new PA(*this); // 深拷贝
  }

  void out() override {
      std::cout << "PA" << std::endl;
  }
};
class PB : public Prototype {
 public:
  Prototype* clone() override {
      return new PB(*this); // 深拷贝
  }

  void out() override {
      std::cout << "PB" << std::endl;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Prototype* oa = new PA();
  Prototype* ob = new PB();

  oa->out();
  Prototype* tmp = oa->clone();
  tmp->out();
  ob->out();
  return 0;
}
