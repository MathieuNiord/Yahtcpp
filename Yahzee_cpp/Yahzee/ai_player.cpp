#include "ai_player.h"

coo_yahtzee::ai_player::ai_player(const std::string& name)
	: player(name) {}

void coo_yahtzee::ai_player::play_turn(const std::vector<dice*>& dices) {
    std::cout << "Tour de " << c_name_ << std::endl;
    roll p_roll(dices);
    p_roll.roll_dices();
    play_round(p_roll);
}

void coo_yahtzee::ai_player::play_round(roll& p_roll) {
    choose_figure(p_roll);
}

void coo_yahtzee::ai_player::choose_figure(roll& p_roll) const {

    int max_score = 0;
    int position = -1;
    int final_position = 0;
    std::string choice_name;

    std::cout << p_roll;

    // First the program searchs into superior's figures
    for (const figure* sup : player_score_->superiors) {

        const int score = sup->get_score_preview(p_roll.dices_);
        position++;

        if (!sup->scored_ && score > max_score) {
            max_score = score;
            choice_name = sup->c_name_;
            final_position = position;
        }
    }

    // Second the program searchs into inferior's figures
    for (const figure* inf : player_score_->inferiors) {

        const int score = inf->get_score_preview(p_roll.dices_);
        position++;

        if (!inf->scored_ && score > max_score) {
            max_score = score;
            choice_name = inf->c_name_;
            final_position = position;
        }
    }

    // If the score isn't upper than the minimum fixed in resources.h,
    // the bot re-roll its dices (based on the round count)
    if (max_score < min_score_ai && p_roll.round_count_ < 3) {
        std::cout << "\n\n" << c_name_ << " n'aime pas les propositions et relance ses des.\n\n";
        p_roll.roll_dices();
        choose_figure(p_roll);
    }

    // Else, the bot scored the figure
    else {

        if (final_position > max_superiors - 1)
            player_score_->inferiors.at(final_position - (max_inferiors - 1))->set_score(p_roll.dices_);

        else
            player_score_->superiors.at(final_position)->set_score(p_roll.dices_);

        std::cout << "\nLe bot " << c_name_ << " a inscrit " << choice_name << " : " << max_score << " points.\n\n";
        std::cout << *player_score_;
    }
}
