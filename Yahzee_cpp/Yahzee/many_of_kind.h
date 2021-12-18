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

		int get_score(const std::vector<dice*>&) const override;

	};

	template<const int Number>
	many_of_kind<Number>::many_of_kind(const std::string& name)
		: figure(name) {}


	template <const int Number>
	int many_of_kind<Number>::get_score(const std::vector<dice*>& game) const {

		std::vector<int> count(max_dice_value, 0);

		int score = 0;

		for (const dice* d : game) {
			count.at(d->get_value() - 1)++;
			score += d->get_value();
		}

        for (const auto &item : count){
            if(item >= Number ) return score;
        }

		return 0;
	}

}