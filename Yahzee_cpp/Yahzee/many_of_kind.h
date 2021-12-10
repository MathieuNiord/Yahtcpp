/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "figure.h"

namespace coo_yahtzee {

	template <const int Number>
	class many_of_kind : public figure {

	public:

		many_of_kind(const std::string&);

	protected:


	private:

		bool check_figure(const std::vector<dice*>&) const override;
		int get_score_preview(const std::vector<dice*>&) const override;

	};

	template<const int Number>
	many_of_kind<Number>::many_of_kind(const std::string& name)
		: figure(name) {}

	template<const int Number>
	bool many_of_kind<Number>::check_figure(const std::vector<dice*>& game) const {

		// Chance case
		if (Number == 0)
			return true;

		// Other cases (3|4 of a kind)
		std::vector<int> count(max_dice_value, 0);

		for (const dice* d : game) {
			count.at(d->get_value() - 1)++;
			if (count.at(d->get_value() - 1) == Number)
				return true;
		}

		return false;
	}

	template <const int Number>
	int many_of_kind<Number>::get_score_preview(const std::vector<dice*>& game) const {

		int score = 0;

		if (check_figure(game))
			for (const dice* d : game)
				score += d->get_value();

		return score;
	}

}