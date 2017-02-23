#include <iostream>
#include <string>
#include "strategy.h"
using namespace std;

int main() {
	std::cout<<"is it ok"<<std::endl;
    Duck* mallard = new MallardDuck();
    mallard->set_fly_behavior(new FlyWithWings());
	mallard->set_quack_behavior(new Quack());
    mallard->perform_fly();
    mallard->perform_quack();
    mallard->set_fly_behavior(new FlyNoWing());
    mallard->perform_fly();
    mallard->perform_quack();
	return 0;
}
