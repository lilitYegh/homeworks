#include <iostream>

class Animal
{
public:   
    void set_head(int head)
    {
        this->head = head;
    }
    void set_body(int body)
    {
        this->body = body;
    }
    void set_tail(int tail)
    {
        this->tail = tail;
    }
    void set_feet(int feet)
    {
        this->feet = feet;
    }
    void set_hands(int hands)
    {
        this->hands = hands;
    }
    void set_wings(int wings)
    {
        this->wings = wings;
    }
private:
    int head{0};
    int body{0};
    int tail{0};
    int feet{0};
    int hands{0};
    int wings{0};
};
class AnimalBuilder
{
public:
    virtual void build_head();
    virtual void build_body();
    virtual void build_tail();
    virtual void build_feet();
    virtual void build_hands();
    virtual void build_wings();
    virtual Animal* get_animal();
   
};
class CatBuilder: public AnimalBuilder
{
private:
    Animal animal;
public:
    CatBuilder()
    {
        this->animal =* new Animal();
    }
    void build_head() override
    {
        this->animal.set_head(1);
    }
    void build_body()  override
    {
        this->animal.body = 1;
    }
    void build_tail() override
    {
        this->animal.tail = 1;
    }
    void build_feet() override
    {
        this->animal.feet = 4;
    }
    void build_hands() override
    {
        this->animal.hands = 0;   
    }
    void build_wings() override
    {
        this->animal.wings = 0;
    }
    Animal* get_animal() override
    {
        return this->animal;
    }
};

class DragonBuilder: public AnimalBuilder
{
private:
    Animal* animal;
public:
    DragonBuilder()
    {
        this->animal = * new Animal();
    }
    void build_head() override
    {
        this->animal.head = 3;
    }
    void build_body()  override
    {
        this->animal.body = 1;
    }
    void build_tail() override
    {
        this->animal.tail = 1;
    }
    void build_feet() override
    {
        this->animal.feet = 2;
    }
    void build_hands() override
    {
        this->animal.hands = 2;   
    }
    void build_wings() override
    {
        this->animal.wings = 2;
    }
    Animal* get_animal() override
    {
        return this->animal;
    }
};

int main() {


    return 0;
}
