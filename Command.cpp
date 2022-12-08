#include <iostream>
class Command
{
public:
  virtual void execute() = 0;
};

class Light 
{
public:
	void on() 
	{
		std::cout << "The light is on\n";
	}
	void off() 
	{
		std::cout << "The light is off\n";
	}
}; 

class LightOn : public Command 
{
private:
	Light *m_light;
public:
    LightOn(Light *light) : m_light(light) {}
	void execute()
	{
		m_light->on();
	}
};

class LightOff : public Command 
{
public:
    LightOff(Light *light) : m_light(light) {}
	void execute()
	{
		m_light->off();
	}
private:
	Light *m_light;
};

class Control 
{
public:
	void setCommand(Command *cmd) 
	{
		m_cmd = cmd;
	}

	void buttonPressed() 
	{
		m_cmd->execute();
	} 
private:
	Command *m_cmd;
};

int main() 
{
	Light *light = new Light;
	LightOff *lightOff = new LightOff(light);
	LightOn *lightOn = new LightOn(light);


	Control *control = new Control;
	control->setCommand(lightOff);
	control->buttonPressed();
	control->setCommand(lightOn);
	control->buttonPressed();

	delete light;
	delete lightOn;
	delete lightOff;
	delete control;
	return 0;
}
