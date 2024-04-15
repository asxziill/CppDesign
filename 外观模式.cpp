#include <bits/stdc++.h>

using ll = long long;

// 子系统类
class A {
 public:
  void out() {
    std::cout << "A" << std::endl;
  }
};

class B {
 public:
  void out() {
    std::cout << "B" << std::endl;
  }
  void G() {
    std::cout << "GB" << std::endl;
  }
};

class C {
 public:
  void out() {
    std::cout << "C" << std::endl;
  }
};


//外观类
//通过接口代替复杂的操作
class W {
 private: 
  A a;
  B b;
  C c;
 public:
  void out() {
    a.out();
    b.out();
  }
  void G() {
    b.G();
    c.out();
  }
};



int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  W w;
  w.out();
  std::cout << std::endl;
  w.G();

  return 0;
}
