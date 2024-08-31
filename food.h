#ifndef FOOD_H
#define FOOD_H

#include <random>
#include <iostream>

using namespace std;

class food
{
public:
	//Variables
	int x, y;


public:
	void changePos();
	bool check_if_collect(float, float);

	food();
	~food();
};

#endif FOOD_H

