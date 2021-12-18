/* Authors : Frejoux G. & Niord M. */

#include "full_house.h"

coo_yahtzee::full_house::full_house()
	: figure("Full")
{}

bool coo_yahtzee::full_house::check_figure(const std::vector<dice*>& dices) const {

	int max = 0;
	int second_max = 0;
	
	std::vector<int> count_values = { 0, 0, 0, 0, 0, 0 };
	
	for (const dice* d : dices)
		count_values.at(d->get_value() - 1)++;
		
	for (int i = 0; i < max_dice_value; i++) {
		
		if (max < count_values.at(i)) {
			second_max = max;
			max = count_values.at(i);
		}
		
		else if (second_max < count_values.at(i))
			second_max = count_values.at(i);
	}
	
	return max >= number_of_dices || (max >= three_of_kind && second_max >= pair);

}

int coo_yahtzee::full_house::get_score(const std::vector<dice*>& game) const {
	if (check_figure(game))
		return full_result;
	return 0;
}
