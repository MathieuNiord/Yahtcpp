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
		virtual ~player();

	protected:

		// --- Attributes ---
		const std::string c_name_;
		score* player_score_;

		// --- Methods ---
		virtual void play_round(roll&);
		virtual void play_turn(const std::vector<dice*>&);

	private:

		// --- Attributes ---
		bool eliminated_;
		int advertise_count_;

		// --- Methods ---
		int advertise_player(const std::string& input);	// Check the player's input and advertises him/her
		int player_choice(const int&);			// Display the player choices
		void player_roll_choice(roll&);			// Display the player choices for a new roll
		void player_figure_choice(const roll&);	// Display the player choices for a choose of a new figure
		int get_score_result() const;

		// --- Setters ---
		void score_all() const;
		void eliminate();

		// --- Comparison ---
		static bool compare_player_pointers(const player* p01, const player* p02) {
			return (p01->get_score_result() > p02->get_score_result());
		}

		// Friends
		friend std::ostream& operator<<(std::ostream& out, const player&);
		friend class game;

		// Tests

	};

	std::ostream& operator<<(std::ostream& out, const player&);
}