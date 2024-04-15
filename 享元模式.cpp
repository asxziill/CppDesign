#include <bits/stdc++.h>

using ll = long long;

// 享元接口
class Shared {
 public:
  virtual void out(const std::string &s) = 0;
};

// 具体享元类
class A : public Shared {
 private:
  int a;
 public:
  A (int a) : a(a) {}

  void out(const std::string &s) override {
    std::cout << "A : " << a << std::endl;
    std::cout << s << std::endl;
  }
};


// 享元工厂
class Fac {
 private:
  std::map<int, Shared*> pool;
 public:
  //传入特征，得到共享
  Shared* get(int a) {
    if (pool.find(a) == pool.end()) {
      pool[a] = new A(a);
    }
    return pool[a];
  }
};



int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Fac fac;
  Shared *a = fac.get(1);
  a->out("abc");
  return 0;
}
