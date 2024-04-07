#include <bits/stdc++.h>

using ll = long long;

//工厂模式

//物品
class P {
 public:
  virtual void out() = 0;
};

//子类继承物品
class AP : public P {
 public:
  virtual void out() override {
    std::cout << "AP" << std::endl;
  }
};
class BP : public P {
 public:
  virtual void out() override {
    std::cout << "BP" << std::endl;
  }
};
//另一个产品Z
class Z {
 public:
  virtual void out() = 0;
};

//子类继承物品
class AZ : public Z {
 public:
  virtual void out() override {
    std::cout << "AZ" << std::endl;
  }
};
class BZ : public Z {
 public:
  virtual void out() override {
    std::cout << "BZ" << std::endl;
  }
};

//工厂
class Factory {
 public:
  //只提供创建父类的接口
  virtual P* createP() = 0;
};

//子类实现 生产子类的工厂
class AFactory : public Factory {
 public:
  AP* createP() override {
    return new AP();
  }
};
class BFactory : public Factory {
 public:
  BP* createP() override {
    return new BP();
  }
};

//抽象工厂模式
//定义相关的接口
//子类是实现所有相关的产品
class AbsFactory {
 public:
  virtual P* createP() = 0;
  virtual Z* createZ() = 0;
};

class AbFactory : public AbsFactory {
 public:
  AP* createP() override {
    return new AP();
  }
  AZ* createZ() override {
    return new AZ();
  }
};
class BbFactory : public AbsFactory {
 public:
  BP* createP() override {
    return new BP();
  }
  BZ* createZ() override {
    return new BZ();
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
    
  return 0;
}
