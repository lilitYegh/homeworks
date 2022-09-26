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
    void print()
    {
        std::cout << "head " << head << "/n";
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
    Animal* animal;
public:
    CatBuilder()
    {
        this->animal = new Animal();
    }
    void build_head() override
    {
        this->animal->set_head(1);
    }
    void build_body()  override
    {
        this->animal->set_body(1);
    }
    void build_tail() override
    {
        this->animal->set_tail(1);
    }
    void build_feet() override
    {
        this->animal->set_feet(4);
    }
    void build_hands() override
    {
        this->animal->set_hands(0);   
    }
    void build_wings() override
    {
        this->animal->set_wings(0);
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
        this->animal =  new Animal();
    }
    void build_head() override
    {
        this->animal->set_head(3);
    }
    void build_body()  override
    {
        this->animal->set_body(1);
    }
    void build_tail() override
    {
        this->animal->set_tail(1);
    }
    void build_feet() override
    {
        this->animal->set_feet(2);
    }
    void build_hands() override
    {
        this->animal->set_hands(2);   
    }
    void build_wings() override
    {
        this->animal->set_wings(2);
    }
    Animal* get_animal() override
    {
        return this->animal;
    }
};

class Builder
{
private:
    AnimalBuilder* animalBuilder;
public:
    Builder (AnimalBuilder* animalb)
    {
        animalBuilder = animalb;
    }
    Animal* get_animal() 
    {
        return this->animalBuilder->get_animal();
    }
    void buildAnimal() 
    { 
        animalBuilder->build_head(); 
        animalBuilder->build_body(); 
        animalBuilder->build_tail(); 
        animalBuilder->build_feet(); 
        animalBuilder->build_hands(); 
        animalBuilder->build_wings(); 
    } 
    
};
