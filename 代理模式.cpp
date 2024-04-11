#include <bits/stdc++.h>

using ll = long long;

// 抽象组件接口
class Subject {
 public:
  virtual void out() = 0;
};

//具体组件
class S : public Subject {
 public:
  void out() override {
    std::cout << "S" << std::endl;
  }
};

// 代理
//通过该类访问Subject
class P : public Subject {
 public:
  P(Subject* s) : s(s) {}

  void out() override {
    if (check()) {
      s->out();
      log();
    } else {
      std::cout << "NO" << std::endl;
    }
  }
 private:
  bool check() {
    // 检查访问权限的逻辑
    return true;
  }

  void log() {
    // 记录访问日志的逻辑
    std::cout << "LOG" << std::endl;
  }

  Subject *s;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  S s;
  P p(&s);

  p.out();
  return 0;
}
