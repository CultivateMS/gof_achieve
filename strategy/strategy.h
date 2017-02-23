#include<iostream>
//定义算法簇，分别封装起来，让它们之间互相替换，此模式让算法的变化独立于使用算法的用户
//oo原则
//封装变化
//多用组合，少用继承
//针对接口编程，不针对实现编程

//封装飞行策略，使得飞行策略的改变不会影响原有的使用者
class FlyBehavior {
public:
    virtual void fly()=0;
};

//封装叫策略，使得叫策略的改变不会影响原有的使用者
class QuackBehavior {
public:
    virtual void quack()=0;
};
//抽象鸭子
class Duck {
public:
    FlyBehavior* fly_behavior ;
    QuackBehavior* quack_behavior;
public:
    Duck();
    void perform_fly();
    void perform_quack();
    void swim();
    //set函数可以动态的改变鸭子的飞行和叫动作，改变写死在鸭子构造函数中的问题
    void set_fly_behavior(FlyBehavior* fb);
    void set_quack_behavior(QuackBehavior* qb);
    virtual void display()=0;
};
class FlyWithWings : public FlyBehavior {
public:
    void fly();
};

class FlyNoWing : public FlyBehavior {
public:
    void fly();
};

class Quack : public QuackBehavior {
public:
    void quack();
};

class MuteQuack : public QuackBehavior {
public:
    void quack();
};
class MallardDuck : public Duck {
public:
    MallardDuck();
    void display();
	virtual ~MallardDuck(){}
};
