#include <iostream>
#include "decorator.h"

int main() {
    Beverage* bev = new DarkRoast();
	bev->get_description();
	std::cout<<" price:"<<bev->cost();
	std::cout<<std::endl;
	Beverage* bev2 = new DarkRoast();
	bev2 = new Mocca(bev2);
	bev2 = new Mocca(bev2);
	bev2 = new Milk(bev2);
	bev2->get_description();
	std::cout<<" price:"<<bev2->cost();
	std::cout<<std::endl;
	return 0;
}
