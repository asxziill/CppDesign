#include <bits/stdc++.h>

using ll = long long;

//抽象基类
class G {
 public:
  virtual void draw() const = 0;
  virtual void add(std::shared_ptr<G> g) {}
  virtual void remove(std::shared_ptr<G> g) {}
  virtual ~G() {}
};

//叶子对象
class C : public G {
 public:
  void draw() const override {
    std::cout << "C" << std::endl;
  }
};

class R : public G {
 public:
  void draw() const override {
    std::cout << "R" << std::endl;
  }
};

// 组合对象(将基类的对象组合)
class Com : public G {
 private:
  std::vector<std::shared_ptr<G>> children;
 public:
  void draw() const override {
    for (const auto & child : children) {
      child->draw();
    }
  }

  void add(std::shared_ptr<G> g) override {
    children.push_back(g);
  }

  void remove(std::shared_ptr<G> g) override {
    children.erase(std::remove(children.begin(), children.end(), g), children.end());
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::shared_ptr<G> c1 = std::make_shared<C>();
  std::shared_ptr<G> r = std::make_shared<R>();
  std::shared_ptr<G> c2 = std::make_shared<C>();

  Com com;
  com.add(c1);
  com.add(r);
  com.add(c2);

  com.draw();

  return 0;
}
