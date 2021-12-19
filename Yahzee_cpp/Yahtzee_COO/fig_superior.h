/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "figure.h"

namespace coo_yahtzee {

	template <const int Value>
	class fig_superior : public figure {

	public:

		fig_superior();

	private:

		// --- Methods ---
		int get_score_preview(const std::vector<dice*>&) const override;

		// Friends
		friend class score;

		// Tests
	};

	template <const int Value>
	fig_superior<Value>::fig_superior() : figure(std::to_string(Value))
	{}

	template <const int Value>
	int fig_superior<Value>::get_score_preview(const std::vector<dice*>& game) const {

		int count = 0;

		for (const dice* d : game)
			if (d->get_value() == Value)
				count++;

		return count * Value;
	}

}
