#include "player.h"

coo_yahtzee::player::player(const std::string& name)
	: c_name_(name) {
	player_score_ = new score();
	eliminated_ = false;
}

coo_yahtzee::player::~player() {
	delete player_score_;
}

int coo_yahtzee::player::get_score() const {
	return player_score_->score_;
}

void coo_yahtzee::player::score_all() const {
	player_score_->score_all();
}

void coo_yahtzee::player::play_round(std::vector<dice*>& game) {

	roll p_roll(game);
	p_roll.roll_dices();

	std::cout << p_roll;
	std::cout << player_score_;

	/*while (p_roll.round_count_ < max_round) {

	}*/



}

std::ostream& coo_yahtzee::operator<<(std::ostream& out, const player&) {
	return out;
}
