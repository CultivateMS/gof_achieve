#include<iostream>
#include<list>
//在对象之间建立一对多的依赖关系，这样一来，当一个对象改变状态，依赖它的对象都会收到通知，并自动更新
//为对象之间的松耦合设计而努力
class Observer {
public:
	virtual void update(float temp, float humidity) = 0;
};

class Subject {
public:
	virtual void register_observer(Observer* o) = 0;
	virtual void remove_observer(Observer* o) = 0;
	virtual void notify_observers() = 0;
};

class WeatherData : public Subject {
private:
	std::list<Observer*>* _observers;
	float temp;
	float humidity;
	float pressure;
public:
	WeatherData() {
	    _observers = new std::list<Observer*>();
	}
	virtual void register_observer(Observer* o);
	virtual void remove_observer(Observer* o);
	virtual void notify_observers();
	void measurements_changed(); 
	void set_measurements(float temp, float humidity);
};

class CurDisplay : public Observer {
private:
	float temp;
	float humidity;
	Subject* weather_data;
public:
	CurDisplay(Subject* sb);
	void update(float temp, float humidity);
	void display();
};

class StaticDisplay : public Observer {
private:
	float temp;
	float humidity;
	Subject* weather_data;
public:
	StaticDisplay(Subject* sb);
	void update(float temp, float humidity);
	void display();
};
