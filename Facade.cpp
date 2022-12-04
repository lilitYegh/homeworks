#include <iostream>
class PhoneModes
{
private:
    int sound = 0; //0-100
    int brightness = 0;//1-100
    bool wifi = 0;
    bool notification = 0;
    
    void soundlevel(int l)
    {
        sound = l;
    }
    void soundOff()
    {
        sound = 0;
    }
    
    void brightnesslevel(int l)
    {
        brightness = l;
    }
    
    void wifiOn()
    {
        wifi = 1;
    }
    void wifiOff()
    {
        wifi = 0;
    }
    void notificationOn()
    {
        notification = 1;
    }
    void notificationOff()
    {
        notification = 0;
    }
public:
    void print()
    {
        std::cout << "Sound " << sound << "\n";
        std::cout << "Brightness " << brightness << "\n";
        std::cout << "WiFi ";
        if(wifi)
        {
            std::cout << "On\n";
        }
        else 
        {
            std::cout << "Off\n";
        }
        std::cout << "Notifications ";
        if(notification)
        {
            std::cout << "On\n";
        }
        else 
        {
            std::cout << "Off\n";
        }
        std::cout << "\n";
    }
    void SleepMode()
    {
        soundOff();
        brightnesslevel(1);
        wifiOff();
        notificationOff();
    }
    void NormalMode()
    {
        soundlevel(70);
        brightnesslevel(70);
        wifiOn();
        notificationOn();
        
    }
    void AirplaneMode()
    {
        soundlevel(30);
        brightnesslevel(30);
        wifiOff();
        notificationOff();
    }
};

int main() 
{
    PhoneModes* phonem = new PhoneModes;
    phonem->NormalMode();
    phonem->print();
    phonem->AirplaneMode();
    phonem->print();
    phonem->SleepMode();
    phonem->print();
    return 0;
}
