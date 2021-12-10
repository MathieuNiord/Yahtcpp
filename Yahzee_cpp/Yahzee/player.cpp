#include "player.h"

coo_yahtzee::player::player(const int& id, const std::string& name)
	: c_id(id), c_name_(name) {

	player_score = new score();
	init_figures();
}

coo_yahtzee::player::player(const player& p)
	: c_id(p.c_id), c_name_(p.c_name_) {

	player_score = p.player_score;

	for (int i = 0; i < p.remaining_figures.size(); i++)
		remaining_figures.at(i) = p.remaining_figures.at(i);
}

coo_yahtzee::player::~player() {
	if (!remaining_figures.empty())
		for (const figure* fig : remaining_figures)
			delete fig;

	remaining_figures.clear();
	delete player_score;
}

void coo_yahtzee::player::init_figures() const {

}

std::ostream& coo_yahtzee::operator<<(std::ostream& out, const player&) {
	// TODO: insérer une instruction return ici
}
