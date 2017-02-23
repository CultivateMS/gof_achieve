#include <iostream>
//动态的将责任附加到对象上。想要扩展功能，装饰者提供有别于继承的另一种选择
//对扩展开放，对修改关闭
class Beverage {
public:
	virtual void get_description() = 0;
	virtual float cost() = 0;
};

class DarkRoast : public Beverage {
public:
	void get_description();
	float cost();
};

class HouseBlend : public Beverage {
public:
	void get_description();
	float cost();
};

class ConditionDrink : public Beverage {
public:
	virtual void get_description() = 0;
};

class Mocca : public ConditionDrink {
public:
	Beverage* beverage;
	Mocca(Beverage* bev);
	void get_description();
	float cost();
};

class Milk : public ConditionDrink {
public:
	Beverage* beverage;
	Milk(Beverage* bev);
	void get_description();
	float cost();
};


