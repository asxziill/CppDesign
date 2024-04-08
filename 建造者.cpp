#include <bits/stdc++.h>

using ll = long long;

/*
通过指挥调用 建造者 然后返回生成后的产品
*/

//复杂的产品
class P {
public:
    void setX(const std::string& X) {
        this->x = X;
    }
    void setY(const std::string& Y) {
        this->y = Y;
    }
    void setZ(const std::string& Z) {
        this->z = Z;
    }
    void show() {
      std::cout << x << " " << y << " " << z << std::endl;
    }
private:
    std::string x;
    std::string y;
    std::string z;
};

// 建造者接口
class Builder {
public:
    virtual ~Builder() {}
    virtual void buildX() = 0;
    virtual void buildY() = 0;
    virtual void buildZ() = 0;
    virtual P getP() = 0;
};

//子类建造者（对产品特化
class ABuilder : public Builder {
 public:
  ABuilder() { this->p = new P(); }
  ~ABuilder() { delete p; }
  void buildX() override { p->setX("AX"); }
  void buildY() override { p->setY("AY"); }
  void buildZ() override { p->setZ("AZ"); }
  P getP() override { return *p; }
 private:
  P* p;
};
class BBuilder : public Builder {
public:
  BBuilder() { this->p = new P(); }
  void buildX() override { p->setX("BX"); }
  void buildY() override { p->setY("BY"); }
  void buildZ() override { p->setZ("BZ"); }
  P getP() override { return *p; }
private:
  P* p;
};

// 指挥者
class Director {
public:
  Director(Builder* builder) : builder(builder) {}
  P construct() {
      builder->buildX();
      builder->buildY();
      builder->buildZ();
      return builder->getP();
  }
 private:
  Builder* builder;
};

int main() {
  ABuilder ab;
  BBuilder bb;
  Director ad(&ab);
  Director bd(&bb);
  ad.construct().show();
  bd.construct().show();
  return 0;
}
