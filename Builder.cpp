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
        std::cout << "body " << body << "\n";
        std::cout << "tail " << tail << "\n";
        std::cout << "feet " << feet << "\n";
        std::cout << "hands " << hands << "\n";
        std::cout << "wings " << wings << "\n";
    }
private:
    int head{0};
    int body{0};
    int tail{0};
    int feet{0};
    int hands{0};
    int wings{0};
};

class Cat : public Animal
{
public:
    Cat() = default;
};
class Dragon : public Animal
{
public:
    Dragon() = default;
};

class AnimalBuilder
{
public:
    virtual void build_head() = 0;
    virtual void build_body() = 0;
    virtual void build_tail() = 0;
    virtual void build_feet() = 0;
    virtual void build_hands() = 0;
    virtual void build_wings() = 0;
};

class CatBuilder: public AnimalBuilder
{
private:
     Cat* animal;
     int m_head = 1;
     int m_body = 1;
     int m_tail = 1;
     int m_feet = 4;
     int m_hands = 0;
     int m_wings = 0;
public:
    CatBuilder()
    {
        animal = new Cat();
    }
    void build_head()
    {
        this->animal->set_head(m_head);
    }
    void build_body()
    {
        this->animal->set_body(m_body);
    }
    void build_tail()
    {
        this->animal->set_tail(m_tail);
    }
    void build_feet()
    {
        this->animal->set_feet(m_feet);
    }
    void build_hands()
    {
        this->animal->set_hands(m_hands);   
    }
    void build_wings()
    {
        this->animal->set_wings(m_wings);
    }
    Cat* get_animal()
    {
        return animal;
    }

};

class DragonBuilder: public AnimalBuilder
{
private:
    Dragon* animal;    
    int m_head = 3;
    int m_body = 1;
    int m_tail = 1;
    int m_feet = 2;
    int m_hands = 2;
    int m_wings = 2;
public:
    DragonBuilder()
    {
        animal = new Dragon();
    }
    void build_head()
    {
        this->animal->set_head(m_head);
    }
    void build_body()
    {
        this->animal->set_body(m_body);
    }
    void build_tail()
    {
        this->animal->set_tail(m_tail);
    }
    void build_feet()
    {
        this->animal->set_feet(m_feet);
    }
    void build_hands()
    {
        this->animal->set_hands(m_hands);   
    }
    void build_wings()
    {
        this->animal->set_wings(m_wings);
    }
    Dragon* get_animal()
    {
        return animal;
    }
};

class Director
{
private:
    AnimalBuilder* animalBuilder;
public:

    Cat* create_cat(CatBuilder* animalb)
    {
        animalb->build_head(); 
        animalb->build_body(); 
        animalb->build_tail(); 
        animalb->build_feet(); 
        animalb->build_hands(); 
        animalb->build_wings();
        return animalb->get_animal(); 
    }
    Dragon* create_dragon(DragonBuilder* animalb) 
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
    Cat *catp = dir.create_cat(&cat);
    Dragon *dbp = dir.create_dragon(&db);
    std::cout << "Cat\n";
    catp->print();
    std::cout << "\nDragon\n";
    dbp->print();
    return 0;
}
