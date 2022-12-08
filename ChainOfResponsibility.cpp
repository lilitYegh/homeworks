#include <iostream>
#include <string>
class Authentication 
{
protected:
    Authentication*     m_next{nullptr};
public:
    virtual bool authenticate() = 0;
    void next_authentication(Authentication *nextAuth) 
    {
        m_next = nextAuth; 
    }
};
class Name : public Authentication 
{
protected:
    std::string      m_name;
    bool is_valid_user_name() 
    {
        return true; 
    }
public:
    Name(std::string name) : m_name(name)
    {}
    bool authenticate() override
    {
        if(!is_valid_user_name()) 
        {
            std::cout << "Invalid user name\n";
            return false;
        }
        else if(m_next) 
        {
            std::cout << "Valid user name\n";
            return m_next->authenticate();
        }
        std::cout << "Valid user name\n";
        return true;
    }
};
class Password : public Authentication 
{
protected:
    std::string      m_password;
    bool is_valid_password() 
    {
        return true; 
    }
public:
    Password(std::string password) : m_password(password)
    {}
    bool authenticate()
    {
        if(!is_valid_password()) 
        {
            std::cout << "Invalid password\n";
            return false;
        }
        else if(m_next) 
        {
            std::cout << "Valid password\n";
            return m_next->authenticate();
        }
        std::cout << "Valid password\n";
        return true;
    }
};
int main() {
    Authentication *login{new Name("Name")};
    login->next_authentication(new Password("password"));
    login->authenticate();
    return 0;
}
