#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <vector>
#include <stdexcept>

class Enemy {
protected:
    std::string name;
    int health;
    int damage;

public:
    Enemy(const std::string& n, int h, int d);
    virtual void attack() = 0;
    virtual void displayInfo() = 0;
};

class Boss : public Enemy {
private:
    std::string weapon;

public:
    Boss(const std::string& n, int h, int d, const std::string& w);
    void attack() override;
    void displayInfo() override;
};

class Monster : public Enemy {
private:
    std::string ability;

public:
    Monster(const std::string& n, int h, int d, const std::string& a);
    void attack() override;
    void displayInfo() override;
};

#endif // ENEMY_H
