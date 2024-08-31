
#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <conio.h>
#include <iomanip>

#include "snake.h"
#include "food.h"

using namespace std;

class game_loop
{
	
public:
	bool update(vector<snake*>*, vector<food*>*,  float*);

};

#endif