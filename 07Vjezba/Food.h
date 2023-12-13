#ifndef FOOD_H
#define FOOD_H

class Food {
private:
    static int counter;

public:
    Food();
    ~Food();

    static void promijeni_counter(int newValue);
    static void ispisi_counter();
    static int get();
};

int get_counter();

#endif /* FOOD_H */