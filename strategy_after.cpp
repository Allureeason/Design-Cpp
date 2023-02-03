/*
 *  策略模式
 * 使用组合的方式解决继承联动性变化问题
 * 使用setter处理if-elseif-else的问题
 *
*/

#include <iostream>
#include <string>
#include <vector>

// 武器抽象基类
class WeaponBehavior {
public:
    virtual std::string useWeapon() = 0;
};

class ScepterBehavior : public WeaponBehavior {
public:
    virtual std::string useWeapon() {
        return "权杖攻击";
    }
};

class SwordBehavior : public WeaponBehavior {
public:
    virtual std::string useWeapon() {
        return "宝剑攻击";
    }
};

class DaggerBehavior : public WeaponBehavior {
public:
    virtual std::string useWeapon() {
        return "短剑攻击";
    }
};

// 角色基类
class Character {
public:
    Character(const std::string& type)
        :m_type(type) {}


    virtual ~Character() {
        if(m_weaponBehavior) {
            delete m_weaponBehavior;
        }
    }
    const std::string& getType() const { return m_type; }
    // 角色战斗行为
    virtual void fight() {
        std::string weapon;
        if(m_weaponBehavior) weapon = m_weaponBehavior->useWeapon();
        else weapon = "赤手空拳";
        std::cout << m_type << " 使用 " << weapon << std::endl;
    }

    void setWeaponBehavior(WeaponBehavior* weaponBehavior) { m_weaponBehavior = weaponBehavior; }
private:
    WeaponBehavior* m_weaponBehavior;
    std::string m_type;
};

class Queen : public Character {
public:
    Queen() : Character("Queen") {}
};

class King : public Character {
public:
    King() : Character("King") {}
};

class Knight : public Character {
public:
    Knight() : Character("Knight") {}
};

int main(int argc, char** argv) {
    std::vector<Character*> characters;
    Character *king = new King;
    king->setWeaponBehavior(new SwordBehavior);
    Character *queen = new Queen;
    queen->setWeaponBehavior(new ScepterBehavior);
    Character *knight = new Knight;
    knight->setWeaponBehavior(new DaggerBehavior);
    characters.push_back(king);
    characters.push_back(queen);
    characters.push_back(knight);

    for(size_t i = 0; i < characters.size(); i++) {
        characters[i]->fight();
    }

    return 0;
}
