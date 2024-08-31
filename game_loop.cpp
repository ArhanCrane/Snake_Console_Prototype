#include "game_loop.h"



bool game_loop::update(vector<snake*>* snake_vector, vector<food*>* food_vector, float* timer) {
	
	std::this_thread::sleep_for(0.033s); //0.333s
	system("cls");

	*timer += 0.033f;

	//9x26
	char map[22][55] = { 
		{" ____________________________________________________ "},
		{"|                                                    |"}, //54x22 52x20
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|                                                    |"},
		{"|____________________________________________________|"}
	};

	for (short i{}; i < snake_vector->size(); i++) {
		map[(*snake_vector)[i]->get_pos_y()][(*snake_vector)[i]->get_pos_x()] = '*';		
	}
	for (short i{}; i < food_vector->size(); i++) {
		
		map[(*food_vector)[i]->y][(*food_vector)[i]->x] = '+';
		
			
	}	


	
	//cout << "PRESS Q OR YOU'LL CLOG UP YOUR MEMORY!!!" << endl;
	cout << setw(35) << " ";
	for (short i{}; i < 22; i++) {
		for (short j{}; j < 55; j++) {
			cout << map[i][j];
		}
		cout << endl;
		cout << setw(35) << " ";
	}

	return false;
	 
	//cout << "=)" << endl;
}


