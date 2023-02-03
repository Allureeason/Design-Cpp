/*
 *  策略模式
 * 使用组合的方式解决继承联动性变化问题
 * 使用setter处理if-elseif-else的问题
 *
*/

#include <iostream>
#include <string>
#include <vector>

// 角色基类
class Character {
public:
    Character(const std::string& type)
        :m_type(type) {}

    const std::string& getType() const { return m_type; }
    // 角色战斗行为
    virtual void fight() = 0;
private:
    std::string m_type;
};

class Queen : public Character {
public:
    Queen() : Character("Queen") {}
    virtual void fight() {
        std::cout << getType() << " 使用权杖战斗" << std::endl;
    }
};

class King : public Character {
public:
    King() : Character("King") {}
    virtual void fight() {
        std::cout << getType() << "使用宝剑战斗" << std::endl;
    }
};

class Knight : public Character {
public:
    Knight() : Character("Knight") {}
    virtual void fight() {
        std::cout << getType() << "使用短剑战斗" << std::endl;
    }
};

int main(int argc, char** argv) {
    std::vector<Character*> characters;
    Character *king = new King;
    Character *queen = new Queen;
    Character *knight = new Knight;
    characters.push_back(king);
    characters.push_back(queen);
    characters.push_back(knight);

    for(size_t i = 0; i < characters.size(); i++) {
        characters[i]->fight();
    }

    return 0;
}
