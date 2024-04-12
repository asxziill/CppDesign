#include <bits/stdc++.h>

using ll = long long;

//个人信息
class Person {
 public:
  std::string name;
  Person(const std::string &s) : name(s) {}
};

//标准（Criteria）
class Criteria {
  virtual std::vector<Person> mec(const std::vector<Person> &Persons) = 0;
};

//具体实现（如名字
class Cname : public Criteria {
  std::string nameSub;
 public:
  Cname(const std::string &s) : nameSub(s) {}
  std::vector<Person> mec(const std::vector<Person> &Persons) {
    std::vector<Person> res;
    for (const auto &p : Persons) {
      if (p.name.find(nameSub) != std::string::npos) {
        res.push_back(p);
      }
    }
    return res;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::vector<Person> persons;
  persons.emplace_back("John Doe");
  persons.emplace_back("Jane Smith");
  persons.emplace_back("Alice Johnson");
  persons.emplace_back("Bob Brown");

  Cname ca("John");
  auto res = ca.mec(persons);
  for (auto &p : res) {
    std::cout << p.name << std::endl;
  }
  return 0;
}
