/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "figure.h"
#include "roll.h"
#include "score.h"
#include "display.h"

namespace coo_yahtzee {

	class player {

	public:

		player(const std::string& name);
		~player();

		void play_turn(std::vector<dice*>&);
		score* player_score_;

		// --- Getter ---
		int get_score() const;

	protected:

		const std::string c_name_;
		

		// --- Methods ---
		
		void play_round(roll&);

	private:

		bool eliminated_;
		int advertise_count_;

		// --- Methods ---
		int advertise_player(const std::string& input);	// Check the player's input and advertises him/her

		// --- Comparison ---
		static bool compare_player_pointers(const player* p01, const player* p02) {
			return (p01->get_score() <= p02->get_score());
		}

		// --- Setters ---
		void score_all() const;
		void eliminate();

		// --- Getters ---
		int player_choice(const int&);			// Display the player choices
		void player_roll_choice(roll&);			// Display the player choices for a new roll
		void player_figure_choice(const roll&);	// Display the player choices for a choose of a new figure

		friend std::ostream& operator<<(std::ostream& out, const player&);
		friend class game;

	};

	std::ostream& operator<<(std::ostream& out, const player&);
}