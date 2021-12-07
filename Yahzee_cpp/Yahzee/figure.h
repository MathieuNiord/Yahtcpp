/* Authors : Frejoux G. & Niord M. */

#pragma once

#include <iostream>
#include <vector>
#include "dice.h"

namespace coo_yahtzee {

	class figure {

	protected:

		// ATTRIBUTES
		const std::string c_name;
		int score_;
		bool scored_;

		figure(const std::string& name) = delete;
		figure(const figure&);
		virtual ~figure() = default;

	private:

		// --- Getters ---
		virtual bool check_figure(const std::vector<dice*>&) const = 0; // Check if the figure exists
		virtual int get_score(const std::vector<dice*>&) const = 0; // Gets the score based on the current roll

		// --- Setters ---
		void scored(const std::vector<dice*>&);	// Sets scored_ at 'true' and put the computed score into the score_ attribute

		// --- Display ---
		virtual std::ostream& to_string(std::ostream& out) const;
		virtual std::ostream& preview(std::ostream& out) const;

		// Friends
		friend std::ostream& operator<<(std::ostream& out, const figure&);
		friend class player;
		friend class score;

	};

	std::ostream& operator<<(std::ostream& out, const figure&);
}
