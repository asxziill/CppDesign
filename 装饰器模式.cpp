#include <bits/stdc++.h>

using ll = long long;

// 抽象组件接口
class Component {
 public:
  virtual void out() = 0;
};

//具体组件
class C : public Component {
 public:
  void out() override {
      std::cout << "C" << std::endl;
  }
};

// 抽象装饰器
class Decorator : public Component {
 public:
  Decorator(Component* component) : component_(component) {}

  void out() override {
      component_->out();
  }

 private:
  Component* component_;
};

class DA : public Decorator {
public:
  DA(Component* component) : Decorator(component) {}

  void out() override {
    Decorator::out();
    std::cout << "DA" << std::endl;
  }
};
class DB : public Decorator {
public:
  DB(Component* component) : Decorator(component) {}

  void out() override {
    Decorator::out();
    std::cout << "DB" << std::endl;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Component* c = new C();
  Component* da = new DA(c);
  Component* db = new DB(c);

  c->out();
  std::cout << std::endl;
  da->out();
  std::cout << std::endl;
  db->out();
  return 0;
}
