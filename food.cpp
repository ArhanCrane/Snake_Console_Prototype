#include "food.h"

random_device rd;
uniform_int_distribution<int> rand_x(2, 51);
uniform_int_distribution<int> rand_y(2, 20);

food::food() {

	this->x = rand_x(rd);
	this->y = rand_y(rd);

}

food::~food() {
	//std::cout << "food is deleted...hope so!" << std::endl;
}

void food::changePos() {
	this->x = rand_x(rd);
	this->y = rand_y(rd);
}

bool food::check_if_collect(float x, float y) {

	if (x == this->x && y == this->y)
		return true;
	else
		return false;

}

