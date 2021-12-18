/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "dice.h"

namespace coo_yahtzee {

	class figure {

	public:

	protected:

		// ATTRIBUTES
		const std::string c_name_;
		int score_;
		bool scored_;

		figure(const std::string& name);
		virtual ~figure() = default;

	private:

		// --- Methods ---

		// Gets the score based on the current roll
		virtual int get_score(const std::vector<dice*>&) const = 0;

		// --- Setters ---
		virtual void set_score(const std::vector<dice*>&);	// Sets scored_ at 'true' and put the computed score into the score_ attribute
		void eliminate();

		// --- Display ---
		virtual std::ostream& to_string(std::ostream& out) const;
		virtual std::ostream& preview(std::ostream& out) const;

		// Friends
		friend std::ostream& operator<<(std::ostream& out, const figure&);
		friend class player;
		friend class score;
		friend class test_figure;

	};

	std::ostream& operator<<(std::ostream& out, const figure&);

}
