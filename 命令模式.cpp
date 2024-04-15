#include <bits/stdc++.h>

using ll = long long;

//命令
class Command {
 public:
  virtual void work() = 0;
};

class A {
 public:
  void out() {
    std::cout << "A" << std::endl;
  }
  void big() {
    std::cout << "AaA" << std::endl;
  }
};

//对A的操作封装
class outCommand : public Command {
 private:
  A &a;
 public:
  outCommand(A &a) : a(a) {}
  void work() override {
    a.out();
  }
};
class bigCommand : public Command {
 private:
  A &a;
 public:
  bigCommand(A &a) : a(a) {}
  void work() override {
    a.big();
  }
};

//命令调用
class Worker {
 private:
  Command *out;
  Command *big;
 public:
  Worker(Command *out, Command *big) : out(out), big(big) {}
  void workout() {
    out->work();
  }
  void workbig() {
    big->work();
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  A a;
  outCommand out(a);
  bigCommand big(a);

  Worker w(&out, &big);
  w.workout();
  w.workbig();

  return 0;
}
