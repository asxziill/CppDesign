#include <bits/stdc++.h>

using ll = long long;

//对象适配器
// 目标接口
class interface
{
 public:
  virtual void interout() = 0;
};

// 被适配类
class A {
public:
    void out() {
        std::cout << "A" << std::endl;
    }
};

// 对象适配器
class AwithI : public interface {
public:
    AwithI(A* a) : a(a) {}

    void interout() override {
        a->out();
    }

private:
    A* a;
};

//类适配器
class Target {
 public:
  virtual void Tout() = 0;
};

// 被适配类
class B {
 public:
  void out() {
      std::cout << "B" << std::endl;
  }
};

// 类适配器，继承自 Adaptee 和实现 Target 接口
class BAdapter : public B, public Target {
public:
    void Tout() override {
        out(); // 调用 Adaptee 的方法
    }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  A a;
  interface* ia = new AwithI(&a);

  a.out();
  ia->interout();

  Target* b = new BAdapter();
  b->Tout();
  return 0;
}
