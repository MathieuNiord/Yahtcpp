#include "player.h"

coo_yahtzee::player::player(const std::string& name)
	: c_name_(name) {
	player_score = new score();
}

coo_yahtzee::player::player(const player& p)
	: c_name_(p.c_name_) {
	player_score = p.player_score;
}

coo_yahtzee::player::~player() {
	delete player_score;
}

void coo_yahtzee::player::play_round(const std::vector<dice*>& game) {

	roll p_roll = roll(game);
	p_roll.roll_dices();

	std::cout << p_roll;
	std::cout << player_score;

	while (p_roll.round_count_ < max_round) {

	}



}

std::ostream& coo_yahtzee::operator<<(std::ostream& out, const player&) {
	// TODO: insérer une instruction return ici
}
