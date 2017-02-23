#include <iostream>
#include "observer.h"

int main() {
    WeatherData* weather_data = new WeatherData();
	CurDisplay* cur = new CurDisplay(weather_data);
	StaticDisplay* stc = new StaticDisplay(weather_data);
	weather_data->set_measurements(3, 6);
	return 0;
}
