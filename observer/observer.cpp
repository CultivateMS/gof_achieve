#include<iostream>
#include "observer.h"
CurDisplay::CurDisplay(Subject* sb) {
    weather_data = sb;
	weather_data->register_observer(this);
}
void CurDisplay::update(float temp, float humidity) {
    this->temp = temp;
	this->humidity = humidity;
	display();
}
void CurDisplay::display() {
	std::cout<<"current temp "<<temp<<"and humidity "<<humidity<<std::endl;
}

StaticDisplay::StaticDisplay(Subject* sb) {
    weather_data = sb;
	weather_data->register_observer(this);
}
void StaticDisplay::update(float temp, float humidity) {
    this->temp = temp;
	this->humidity = humidity;
	display();
}
void StaticDisplay::display() {
	std::cout<<"static temp "<<temp<<"and humidity "<<humidity<<std::endl;
}

void WeatherData::register_observer(Observer* o) {
    _observers->push_back(o);
}

void WeatherData::remove_observer(Observer* o) {
	if (_observers->size() > 0) {
        _observers->remove(o);
	}
}

void WeatherData::notify_observers() {
    std::list<Observer*>::iterator iter =  _observers->begin();
	for (iter; iter!=_observers->end(); iter++) {
	    (*iter)->update(temp, humidity);
	}
}
void WeatherData::measurements_changed() {
    notify_observers();
}
void WeatherData::set_measurements(float temp, float humidity) {
    this->temp = temp;
	this->humidity = humidity;
	std::cout<<temp<<" "<<humidity<<std::endl;
	measurements_changed();
}
