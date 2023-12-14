#include "Enemy.h"

Enemy::Enemy(const std::string& n, int h, int d) : name(n), health(h), damage(d) {
    if (h < 0 || d < 0) {
        throw std::invalid_argument("Broj nije ispravan (health i damage ne smiju biti negativni)");
    }
}

Boss::Boss(const std::string& n, int h, int d, const std::string& w) : Enemy(n, h, d), weapon(w) {
    if (w.empty()) {
        throw std::invalid_argument("Oruzje ne moze biti prazno");
    }
}

void Boss::attack() {
    std::cout << "Boss napada sa: " << weapon << ". Nanosi: " << damage << " stete." << std::endl;
}

void Boss::displayInfo() {
    std::cout << "Boss Name: " << name << ", Health: " << health << ", Damage: " << damage << ", Weapon: " << weapon << std::endl;
}

Monster::Monster(const std::string& n, int h, int d, const std::string& a) : Enemy(n, h, d), ability(a) {
    if (a.empty()) {
        throw std::invalid_argument("Sposobnost ne moze biti prazna");
    }
}

void Monster::attack() {
    std::cout << "Monster koristi " << ability << ". Nanosi " << damage << " stete." << std::endl;
}

void Monster::displayInfo() {
    std::cout << "Monster Name: " << name << ", Health: " << health << ", Damage: " << damage << ", Ability: " << ability << std::endl;
}
