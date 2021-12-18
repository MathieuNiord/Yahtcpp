#include "ai_player.h"

void coo_yahtzee::ai_player::play_round(roll& p_roll)
{
	int max_score = -1;
	figure* choice;

    for (const auto &item : player_score_->superiors){

        int score = item->get_score(p_roll.dices_);

        if( !item->scored_ && score > max_score) {
            max_score = score;
            choice = item;
        }
    }


    for (const auto &item : player_score_->inferiors){

        int score = item->get_score(p_roll.dices_);

        if( !item->scored_ && score > max_score) {
            max_score = score;
            choice = item;
        }
    }

    choice->set_score(p_roll.dices_);
}
