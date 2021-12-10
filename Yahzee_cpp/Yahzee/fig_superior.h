/* Authors : Frejoux G. & Niord M. */

#pragma once

#include <string>
#include "figure.h"

namespace coo_yahtzee {

	template <const int Value>
	class fig_superior : public figure {

	public:

		fig_superior();

	protected:

	private:

		bool check_figure(const std::vector<dice*>&) const override;
		int get_score_preview(const std::vector<dice*>&) const override;

		friend class score;

	};

	template <const int Value>
	fig_superior<Value>::fig_superior() : figure(std::to_string(Value))
	{}

	template <const int Value>
	bool fig_superior<Value>::check_figure(const std::vector<dice*>& game) const {

		for (const dice* d : game)
			if (d->get_value() == Value)
				return true;

		return false;
	}

	template <const int Value>
	int fig_superior<Value>::get_score_preview(const std::vector<dice*>& game) const {

		int count = 0;

		for (const dice* d : game)
			if (d->get_value() == Value)
				count++;

		return count * Value;
	}

}
