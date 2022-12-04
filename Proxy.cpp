#include <iostream>
class Wifi
{
public:
	virtual void connect(int password) = 0;
	virtual ~Wifi() {}
};
 
class RealWifi : public Wifi
{
public:
	void connect(int password) override
	{ 
		std::cout << "Connected to WiFi\n"; 
	}
};
 
class Proxy : public Wifi
{
private:
	RealWifi* realWifi;
	int m_password = 1111;
	
public:
	Proxy() : realWifi (new RealWifi()) 
	{}
	~Proxy() 
	{ 
		delete realWifi; 
	}
	void connect(int password) override
	{
	    if(password == m_password)
		    realWifi->connect(password); 
		else
		    std::cout << "Wrong password\n";
	}
};
 
int main() 
{
	Proxy p;
	p.connect(1111);
}
