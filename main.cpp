

#include "game_loop.h"
#include "snake.h"
#include "food.h"

//https://youtu.be/HcESuwmlHEY?si=LAH8M43zFzTtsyLj
// This one should help to optimize std::vector


int main() {
	char key_{'s'};
	char pre_key_{};

	float timer{};

	game_loop gameLoop;

	vector <snake*> snake_vec;
	vector <food*> food_vec;

	snake_vec.push_back(new snake(true, false, nullptr, nullptr));
	snake_vec.push_back(new snake(true, true, nullptr, snake_vec[0]));

	food_vec.push_back(new food());
	

	while (true) {		

		if (key_ == 'q') {
			system("cls");
			for (short i{}; i < snake_vec.size(); i++) {
				delete(snake_vec[i]);
				cout << "deleted : " << i << endl;
			}
			for (short i{}; i < food_vec.size(); i++) {
				delete(food_vec[i]);
				cout << "deleted : " << i << endl;
			}
			break;
		}

		if (_kbhit()) {
			key_ = _getch();
			
			if (key_ == 'a' || key_ == 'd' || key_ == 's' || key_ == 'w') {			
				pre_key_ = key_;
			}
			if (key_ == 'n') {
				snake_vec.push_back(new snake(false, false, snake_vec[snake_vec.size() - 1], snake_vec[snake_vec.size() - 2]));
			}
			if (key_ == 'b') {
				food_vec.push_back(new food());
			}
			

			else if (key_ == 'q') { //Exit button
				system("cls");
				for (short i{}; i < snake_vec.size(); i++) {
					delete(snake_vec[i]);
					cout << "deleted : " << i << endl;
				}
				for (short i{}; i < food_vec.size(); i++) {
					delete(food_vec[i]);
					cout << "deleted : " << i << endl;
				}
				break;
			}

			key_ = pre_key_;
			
			
		}
		for (size_t i{}; i < food_vec.size(); i++) {
			if (food_vec[i]->check_if_collect(snake_vec[0]->get_pos_x(), snake_vec[0]->get_pos_y())) {
				snake_vec.push_back(new snake(false, false, snake_vec[snake_vec.size() - 1], snake_vec[snake_vec.size() - 2]));
				food_vec[i]->changePos();
			}
		}
		for (unsigned i{}; i < snake_vec.size(); i++) {
			if (i > 0)
				if ((snake_vec[0]->get_pos_x() == snake_vec[i]->get_pos_x() &&
					snake_vec[0]->get_pos_y() == snake_vec[i]->get_pos_y()) || (1 >= snake_vec[0]->get_pos_x() || 52 < snake_vec[0]->get_pos_x()) 
					|| (1 >= snake_vec[0]->get_pos_y() || 21 <= snake_vec[0]->get_pos_y())) {
					key_ = 'q';
				}
		}
		for (size_t i{ snake_vec.size() - 1 }; i > 0; --i) {
			snake_vec[i]->second_pos_change(snake_vec[i], snake_vec[i - 1]);
		}
		snake_vec[0]->pos_change(key_);
		gameLoop.update(&snake_vec, &food_vec, &timer);
			
		
		
	}



	cout << "done!" << endl;

	return 0;
}