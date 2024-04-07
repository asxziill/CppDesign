#include <bits/stdc++.h>

using ll = long long;

/*
通过指挥调用 建造者 然后返回生成后的产品
*/

//复杂的产品
class P {
public:
    void setX(const std::string& x) {
        this->x = x;
    }
    void setY(const std::string& Y) {
        this->y = y;
    }
    void setZ(const std::string& Z) {
        this->z = z;
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
    virtual P* getP() = 0;
};

//子类建造者（对产品特化
class ABuilder : public Builder {
private:
    P* p;
public:
    ABuilder() { this->p = new P(); }
    ~ABuilder() { delete p; }
    void buildX() override { p->setX("AX"); }
    void buildY() override { p->setY("AY"); }
    void buildZ() override { p->setZ("AZ"); }
    P* getP() override { return p; }
};
class BBuilder : public Builder {
private:
    P* p;
public:
    BBuilder() { this->p = new P(); }
    ~BBuilder() { delete p; }
    void buildX() override { p->setX("BX"); }
    void buildY() override { p->setY("BY"); }
    void buildZ() override { p->setZ("BZ"); }
    P* getP() override { return p; }
};

// 指挥者
class Director {
public:
    void constructP(Builder* builder) {
        builder->buildX();
        builder->buildY();
        builder->buildZ();
    }
};

int main() {
  
  return 0;
}
