#include <iostream>
class Device
{
private:
    class State *current;
public:
    Device();
    void setCurrent(State *s)
    {
        current = s;
    }
    void on();
    void off();
};

class State
{
public:
    virtual void on(Device *d)
    {
        std::cout << "already ON\n";
    }
    virtual void off(Device *d)
    {
        std::cout << "already OFF\n";
    }
};

void Device::on()
{
    current->on(this);
}

void Device::off()
{
    current->off(this);
}

class ON: public State
{
public:
    ON(){}
    ~ON(){}
    void off(Device *d);
};

class OFF: public State
{
public:
    OFF(){}
    ~OFF(){}
    void on(Device *d)
    {
        std::cout << "going from OFF to ON\n";
        d->setCurrent(new ON());
        delete this;
    }
};

void ON::off(Device *d)
{
    std::cout << "going from ON to OFF\n";
    d->setCurrent(new OFF());
    delete this;
}

Device::Device()
{
    current = new OFF();
    std::cout << '\n';
}

int main()
{
    Device d;
    d.off();
    d.on();
    d.on();
    d.off();
}
