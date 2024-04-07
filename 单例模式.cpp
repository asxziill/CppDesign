#include <bits/stdc++.h>

using ll = long long;

//饿汉式
class A {
private:
    // 私有的默认构造函数
    A() {
        std::cout << "A instance created." << std::endl;
    }

    // 禁止/私有拷贝构造函数和赋值操作
    A(const A&) = delete;
    A& operator=(const A&) = delete;

public:
    // 提供一个访问单例的静态方法
    static A& getInstance() {
        // 静态实例在程序开始时就创建了
        static A instance;
        return instance;
    }
};


//懒汉式
class B {
private:
    // 私有的默认构造函数
    B() {
        std::cout << "B instance created." << std::endl;
    }

    // 禁止拷贝构造函数和赋值操作
    B(const B&) = delete;
    B& operator=(const B&) = delete;

    // 单例实例指针
    static B* instance;
    // 用于控制线程安全初始化的标志
    static std::once_flag onceFlag;

public:
    // 获取单例对象的静态方法
    static B* getInstance() {
        // 使用call_once来确保线程安全的单次初始化
        std::call_once(onceFlag, []() {
            instance = new B();
        });
        return instance;
    }

    // 清理单例实例的方法
    static void destroyInstance() {
        delete instance;
        instance = nullptr;
    }
};

// 初始化静态成员变量
B* B::instance = nullptr;
std::once_flag B::onceFlag;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
    
  return 0;
}
