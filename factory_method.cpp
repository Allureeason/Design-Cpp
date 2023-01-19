/*
 * ----创建型设计模式----
 * - 工厂方法模式
 * 设计模式初衷是解决简单工厂模式的扩展型问题，具备简单工厂模式的优点，解决简单工厂模式中不断扩展时需要改变工厂代码的问题
 * 问题：简单工厂模式的工厂在不断增加新的类时，需要在工厂类中不断添加判断条件，进行新类对象的创建，改变了工厂的稳定性
 * 具体实现：把工厂类抽象出来，多态出多个工厂，每个工厂对应创建一种类型对象，使用者只需要创建对应的工厂，在使用工厂通用接口创建类即可
 *
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

class Factory {
public:
    virtual ~Factory() {}
    virtual Car* createCar() = 0;
};

class SmallCarFactory : public Factory {
public:
    virtual Car* createCar() {
        return new SmallCar;
    }
};

class BigCarFactory : public Factory {
public:
    virtual Car* createCar() {
        return new BigCar;
    }
};

int main(int argc, char** argv) {

    // 创建对应工厂
    Factory* smallcarFactory = new SmallCarFactory;
    Factory* bigcarFactory = new BigCarFactory;

    // 使用对应工厂实例化类对象
    Car* car1 = smallcarFactory->createCar();
    Car* car2 = bigcarFactory->createCar();

    car1->func();
    car2->func();

    delete smallcarFactory;
    delete bigcarFactory;
    delete car1;
    delete car2;

    return 0;
}
