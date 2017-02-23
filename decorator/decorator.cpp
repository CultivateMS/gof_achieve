#include <iostream>
#include "decorator.h"

void DarkRoast::get_description() {
    std::cout<<"darkroast";
}

float DarkRoast::cost() {
   return 0.5;
}

void HouseBlend::get_description() {
    std::cout<<"houseblend";
}

float HouseBlend::cost() {
    return 0.8;
}
Mocca::Mocca(Beverage* bev) {
    this->beverage = bev;
}
void Mocca::get_description() {
   std::cout<<"mocca";
   beverage->get_description();
}

float Mocca::cost() {
    return 0.2 + beverage->cost();
}

Milk::Milk(Beverage* bev) {
    this->beverage = bev;
}
void Milk::get_description() {
   std::cout<<"milk";
   beverage->get_description();
}

float Milk::cost() {
	return 0.3 + beverage->cost();
}
