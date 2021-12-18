/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "figure.h"

namespace coo_yahtzee {

	template <const int Value>
	class fig_superior : public figure {

	public:

		fig_superior();

	private:

		int get_score(const std::vector<dice*>&) const override;

		friend class score;
		friend class test_figure;
	};

	template <const int Value>
	fig_superior<Value>::fig_superior() : figure(std::to_string(Value))
	{}


	template <const int Value>
	int fig_superior<Value>::get_score(const std::vector<dice*>& game) const {

		int count = 0;

		for (const dice* d : game)
			if (d->get_value() == Value)
				count++;

		return count * Value;
	}

}
