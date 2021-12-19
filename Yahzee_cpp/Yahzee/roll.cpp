/* Authors : Frejoux G. & Niord M. */

#include "roll.h"

coo_yahtzee::roll::roll(const std::vector<dice*>& dices) {

	dices_.reserve(number_of_dices);

	for (const dice* d : dices)
		dices_.push_back(new dice(*d));

	round_count_ = 0;
}

coo_yahtzee::roll::~roll() {

	for (const dice* d : dices_)
		delete d;

	dices_.clear();
}

void coo_yahtzee::roll::roll_dices() {

	for (dice* d : dices_)
		d->roll();

	sort_dices();

	round_count_++;
}

void coo_yahtzee::roll::roll_dice(const	std::vector<int>& positions) {

	for (const int& pos : positions)
		if (pos >= 1 && pos <= number_of_dices)
			dices_.at(pos - 1)->roll();

	sort_dices();

	round_count_++;
}

int coo_yahtzee::roll::get_number_of(const int& value) const {

	int counter = 0;

	for (const dice* d : dices_)
		if (d->value_ == value)
			counter++;

	return counter;
}

std::ostream& coo_yahtzee::operator<<(std::ostream& out, const roll& r) {

	std::string dices;

	out << "\n\n\t ============= LANCER =============\n"
		<< "\t|                                   |\n"
		<< "\t|   Jeu :";

	for (int pos = 0; pos < number_of_dices; pos++)
		dices.append(" " + r.dices_.at(pos)->to_string());

	out << std::left << std::setw(27) << dices << "|\n"
		<< "\t|                                   |\n"
		<< "\t ===================================\n";

	return out;
}
