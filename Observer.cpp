
#include <iostream>
#include <list>
#include <string>

class IObserver 
{
public:
    virtual ~IObserver(){};
    virtual void Refresh(const std::string &message_from_subject) = 0;
};

class ISubject 
{
protected:
    std::list<IObserver *> list_followers;
    std::string notification;
public:
    virtual ~ISubject(){};
    virtual void SubscribeToMe(IObserver *follower) = 0;
    virtual void UnsubscribeFromMe(IObserver *follower) = 0;
    virtual void Notify() = 0;
};

class Blogger : public ISubject 
{
private:
    void HowManyFollowers() 
    {
        std::cout << "You have " << list_followers.size() << " followers.\n";
    }
 public:
    virtual ~Blogger() {}

    void SubscribeToMe(IObserver *follower) override 
    {
          list_followers.push_back(follower);
    }
    void UnsubscribeFromMe(IObserver *follower) override 
    {
          list_followers.remove(follower);
    }
    void Notify() override 
    {
        std::list<IObserver *>::iterator iterator = list_followers.begin();
        HowManyFollowers();
        while (iterator != list_followers.end()) 
        {
            (*iterator)->Refresh(notification);
            ++iterator;
        }
    }

    void CreateNotification(std::string notif = "Empty") 
    {
        notification = notif;
        Notify();
    }


};

class Follower : public IObserver 
{
private:
    std::string update;
    Blogger &m_blogger;
    static int static_number;
    int number;
public:
    Follower(Blogger &blogger) : m_blogger(blogger) 
    {
        m_blogger.SubscribeToMe(this);
        ++Follower::static_number;
        number = Follower::static_number;
    }
    virtual ~Follower() {}

    void Refresh(const std::string &notif) override 
    {
        update = notif;
        PrintInfo();
    }
    void Unsubscribe() 
    {
        m_blogger.UnsubscribeFromMe(this);
    }

    void PrintInfo() 
    {
        std::cout << "Follower " << number << " " << update << "\n";
    }
};

int Follower::static_number = 0;


int main() 
{
    Blogger *blogger = new Blogger;
    Follower *follower1 = new Follower(*blogger);
    Follower *follower2;

    blogger->CreateNotification("HI :D");
    follower2 = new Follower(*blogger);
    blogger->CreateNotification("New image");
    follower1->Unsubscribe();
    
    return 0;
}
