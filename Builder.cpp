#include <iostream>
class Animal
{
public:   
    Animal() = default;
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
        std::cout << "head " << head << "\n";
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
protected:
    Animal* animal;
public:
    virtual void build_head() = 0;
    virtual void build_body() = 0;
    virtual void build_tail() = 0;
    virtual void build_feet() = 0;
    virtual void build_hands() = 0;
    virtual void build_wings() = 0;
    Animal* get_animal()
    {
        return animal;
    }
   
};
class CatBuilder: public AnimalBuilder
{
public:
    void build_head()
    {
        animal = new Animal();
        this->animal->set_head(1);
    }
    void build_body()
    {
        this->animal->set_body(1);
    }
    void build_tail()
    {
        this->animal->set_tail(1);
    }
    void build_feet()
    {
        this->animal->set_feet(4);
    }
    void build_hands()
    {
        this->animal->set_hands(0);   
    }
    void build_wings()
    {
        this->animal->set_wings(0);
    }

};

class DragonBuilder: public AnimalBuilder
{
public:
    void build_head()
    {
        animal = new Animal();
        this->animal->set_head(3);
    }
    void build_body() 
    {
        this->animal->set_body(1);
    }
    void build_tail()
    {
        this->animal->set_tail(1);
    }
    void build_feet()
    {
        this->animal->set_feet(2);
    }
    void build_hands()
    {
        this->animal->set_hands(2);   
    }
    void build_wings() 
    {
        this->animal->set_wings(2);
    }
  
};

class Director
{
private:
    AnimalBuilder* animalBuilder;
public:

    Animal* create_animal(AnimalBuilder* animalb) 
    {
        animalb->build_head(); 
        animalb->build_body(); 
        animalb->build_tail(); 
        animalb->build_feet(); 
        animalb->build_hands(); 
        animalb->build_wings();
        return animalb->get_animal();
    }

    
};
int main()
{
    Director dir;
    CatBuilder cat;
    DragonBuilder db;
    Animal *catp = dir.create_animal(&cat);
    Animal *dbp = dir.create_animal(&db);
    catp->print();
    dbp->print();
    return 0;
}
