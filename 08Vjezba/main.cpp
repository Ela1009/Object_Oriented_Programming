#include "Enemy.h"

int main() {
    std::vector<Enemy*> enemies;

    try {
        enemies.push_back(new Boss("Boss1", 150, 30, "Mac"));
        enemies.push_back(new Monster("Monster1", 100, 40, "Brzina"));
        enemies.push_back(new Boss("Boss2", -50, 30, "Sjekira")); 
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    for (Enemy* enemy : enemies) {
        try {
            enemy->attack();
            enemy->displayInfo();
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    for (Enemy* enemy : enemies) {
        delete enemy;
    }
    enemies.clear();

    return 0;
}
