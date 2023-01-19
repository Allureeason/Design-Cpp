/*
 * ----创建型设计模式----
 * - 简单工厂模式
 * 设计模式初衷是解决类对象和何用者之间的耦合关系
 * 问题：如果使用这需要使用某一个类的具体对象，那么使用者需要知道类名，在进行实例化
 * 前提：这些需要实例化的类都可以抽象出共同属性，即抽象出一个父类（抽象类），具体子类是该抽象类的泛化
 * 如何实现：创建一个简单工厂，使用者不需要关心创建细节，只关心需要什么类型的对象，传递一个辨识，让工厂提供对象
*/

#include <iostream>
#include <string>

// “车”抽象类
class Car {
public:
    virtual ~Car() {}
    virtual void func() = 0;
};

// 小车实现类
class SmallCar : public Car {
public:
    virtual void func() {
        std::cout << "SmallCar" << std::endl;
    }
};

// 大车实现类
class BigCar : public Car {
public:
    virtual void func() {
        std::cout << "BigCar" << std::endl;
    }
};

// 简单工厂类
class SimpleFactory {
public:
    Car* createCar(const std::string& name) {
        if(name == "Big") {
            return new BigCar;
        } else if(name == "Small") {
            return new SmallCar;
        }
    }
};

int main(int argc, char** argv) {
    SimpleFactory factory; // 创建一个工厂

    Car* car1 = factory.createCar("Small");
    Car* car2 = factory.createCar("Big");

    car1->func();
    car2->func();

    delete car1;
    delete car2;

    return 0;
}
