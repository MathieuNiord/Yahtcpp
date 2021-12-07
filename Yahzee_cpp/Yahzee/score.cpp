#include "score.h"

coo_yahtzee::score::score() {

	score_ = 0;

	init_superiors();
	init_inferiors();
}

void coo_yahtzee::score::init_inferiors() {
	scored_inferiors.reserve(MAX_INFERIORS);
}

void coo_yahtzee::score::init_superiors() {

	scored_superiors.reserve(MAX_SUPERIORS);

	add_sup(new fig_superior<1>());
	add_sup(new fig_superior<2>());
	add_sup(new fig_superior<3>());
	add_sup(new fig_superior<4>());
	add_sup(new fig_superior<5>());
	add_sup(new fig_superior<6>());

}

void coo_yahtzee::score::compute_score() {

	score_ = 0;

	for (const figure* sup : scored_superiors)
		if (sup->scored_)
			score_ += sup->score_;

	if (score_ >= BONUS_START)
		score_ += BONUS;

	for (const figure* inf : scored_inferiors)
		if (inf->scored_)
			score_ += inf->score_;
}

void coo_yahtzee::score::add_inf(figure* inf) {
	scored_superiors.push_back(inf);
}

void coo_yahtzee::score::add_sup(figure* sup) {
	scored_superiors.push_back(sup);
}
