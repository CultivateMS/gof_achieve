#include<iostream>
#include"strategy.h"

//抽象鸭子
Duck::Duck() {

}
void Duck::perform_fly() {
    fly_behavior->fly();
}
void Duck::perform_quack() {
    quack_behavior->quack();
}
void Duck::swim() {
    std::cout<<"swim uniform"<<std::endl;
}
//set函数可以动态的改变鸭子的飞行和叫动作，改变写死在鸭子构造函数中的问题
void Duck::set_fly_behavior(FlyBehavior* fb) {
    fly_behavior = fb;
}
void Duck::set_quack_behavior(QuackBehavior* qb) {
    quack_behavior = qb;
}

void FlyWithWings::fly() {
	std::cout<<"I'm flying!"<<std::endl;
}

void FlyNoWing::fly() {
    std::cout<<"I can't fly"<<std::endl;
}

void Quack::quack() {
    std::cout<<"quack"<<std::endl;
}

void MuteQuack::quack() {
    std::cout<<"silence"<<std::endl;
}

MallardDuck::MallardDuck() {
    quack_behavior = NULL;
	fly_behavior = NULL;
}
void MallardDuck::display() {
    std::cout<<"I'm a real MallardDuck"<<std::endl;
}

/*int main() {
Duck* mallard = new MallardDuck();
mallard->perform_fly();
mallard->perform_quack();
mallard->set_fly_behavior(new FlyNoWing());
mallard->perform_fly();
mallard->perform_quack();
return 0;
}*/
