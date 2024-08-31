#include "snake.h"

snake::snake(bool type, bool isSecond, snake* last_snake, snake* before_last_snake) { //true - main, false - minor
	if (type && !isSecond) {
		this->x = 2;
		this->y = 2;
	}
	else if (isSecond) {
		this->x = 1 + before_last_snake->get_pos_x();
		this->y = before_last_snake->get_pos_y();
	}
	else {
		this->x = last_snake->get_pos_x() + (last_snake->get_pos_x() - before_last_snake->get_pos_x());
		this->y = last_snake->get_pos_y() + (last_snake->get_pos_y() - before_last_snake->get_pos_y());
	}
	

}

snake::~snake() {
	//std::cout << "snake is deleted...hope so!" << std::endl;
}

void snake::pos_change(char key) {

	switch (key) {

	case 'w':
		y -= 1;
		break;
	case 's':
		y += 1;
		break;
	case 'a':
		x -= 1;
		break;
	case 'd':
		x += 1;
		break;

	default:
		break;

	}

}

void snake::second_pos_change(snake* current_snake, snake* next_to_snake) {
	current_snake->x = next_to_snake->x;
	current_snake->y = next_to_snake->y;
}

int snake::get_pos_x() {
	//std::cout << "x : " << x << " y : " << y << std::endl;
	return x;
}

int snake::get_pos_y() {
	//std::cout << "x : " << x << " y : " << y << std::endl;
	return y;
}
