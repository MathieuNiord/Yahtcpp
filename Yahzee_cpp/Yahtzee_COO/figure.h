/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "dice.h"

namespace coo_yahtzee {

	class figure {

	protected:

		// --- Atrributes ---
		const std::string c_name_;
		int score_;
		bool scored_;

		figure(const std::string& name);
		virtual ~figure() = default;

		// --- Methods ---
		virtual void set_score(const std::vector<dice*>&);	// Sets scored_ at 'true' and put the computed score into the score_ attribute
		virtual int get_score_preview(const std::vector<dice*>&) const = 0;	// Gets the score based on the current roll

	private:

		// --- Setters ---
		void eliminate();

		// --- Display ---
		std::ostream& to_string(std::ostream& out) const;

		// Friends
		friend std::ostream& operator<<(std::ostream& out, const figure&);
		friend class player;
        friend class ai_player;
		friend class score;

		// Tests
		friend class Test_Figure;
		friend class Test_Score;

	};

	std::ostream& operator<<(std::ostream& out, const figure&);

}
