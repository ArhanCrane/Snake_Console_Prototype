#ifndef SNAKE_H
#define SNAKE_H

#include <conio.h>
#include <iostream>
#include <vector>

//using namespace std;


class snake
{
	//Variables
	int x{}, y{};

	

public:
	//Constructor
	snake(bool, bool, snake*, snake*);
	~snake();

	//Functions
	void pos_change(char);
	void second_pos_change(snake*, snake*);
	int get_pos_x();
	int get_pos_y();

};

#endif