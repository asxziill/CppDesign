#include <bits/stdc++.h>

using ll = long long;

// 观察者接口
class Observer
{
 public:
  virtual void out(const std::string &s) = 0;
};


// 抽象组件接口
class Subject {
 public:
  virtual void addObserver(Observer* observer) = 0;
  virtual void removeObserver(Observer* observer) = 0;
  virtual void notifyObservers(const std::string &s) = 0;
};

//具体观察者
class O : public Observer
{
 public:
  O(const std::string &name) : name(name) {}
  void out(const std::string &s) override {
    std::cout << name << " ME: " << s << std::endl;
  }
  
 private:
  std::string name;
};

// 具体
class S : public Subject {
 public:
  void addObserver(Observer* ob) override {
    obs.push_back(ob);
  }
  void removeObserver(Observer* ob) override {
    //寻找并移除观察者
    auto it = std::find(obs.begin(), obs.end(), ob);
    if (it != obs.end()) {
      obs.erase(it);
    }
  }
  virtual void notifyObservers(const std::string &s) override {
    //通知所有观察者
    for (auto ob : obs) {
      ob->out(s);
    }
  }
 private:
  std::vector<Observer*> obs;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  O o1("O1");
  O o2("O2");

  S s;
  s.addObserver(&o1);
  s.addObserver(&o2);

  s.notifyObservers("HE");
  std::cout << std::endl;

  s.removeObserver(&o1);
  
  s.notifyObservers("RE");
  return 0;
}
