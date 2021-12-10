/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "figure.h"

namespace coo_yahtzee {

	template <const int Number>
	class straight : public figure {

	public:

		straight(const std::string&);

	protected:


	private:

		bool check_figure(const std::vector<dice*>&) const override;
		int get_score_preview(const std::vector<dice*>&) const override;

	};

	template<const int Number>
	straight<Number>::straight(const std::string& name)
		: figure(name) {}

	template <const int Number>
	bool straight<Number>::check_figure(const std::vector<dice*>& game) const {

		std::sort(game.begin(), game.end());
		int count = -1;
		int last_value = game.at(0)->get_value();

		for (const dice* d : game) {

			if (d->get_value() == last_value)
				count++;

			if ((count > max_dice_value - Number) || (d->get_value() > last_value + 1))
				return false;

			last_value = d->get_value();
		}

		return true;

	}

	template <const int Number>
	int straight<Number>::get_score_preview(const std::vector<dice*>& game) const {

		if (check_figure(game))
			return (Number - 1) * 10;

		return 0;
	}

}



