/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "figure.h"

namespace coo_yahtzee {

	class yahtzee : public figure {

	public:

		yahtzee();

	private:

		int count_;

		// --- Methods ---

		bool check_figure(const std::vector<dice*>&) const override;

		// --- Getter ---
		int get_score(const std::vector<dice*>&) const override;

		// --- Setter ---
		void set_score(const std::vector<dice*>&) override;

	};

}