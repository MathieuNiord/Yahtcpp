#include "ai_player.h"

coo_yahtzee::ai_player::ai_player(const std::string& name) : player(name)
{

}

void coo_yahtzee::ai_player::play_round(roll& p_roll)
{
	int max_score = -1;
	figure* choice = new fig_superior<1>();

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

    std::cout << "Tour de " << c_name_ << ", choix : " 
        << choice->c_name_ << " : " << choice->score_ << std::endl;
}
