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

void coo_yahtzee::player::play_round(const std::vector<dice*>&)
{
}

std::ostream& coo_yahtzee::operator<<(std::ostream& out, const player&) {
	// TODO: insérer une instruction return ici
}
