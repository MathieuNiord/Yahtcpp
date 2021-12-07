/* Authors : Frejoux G. & Niord M. */

#pragma once

#include <string>
#include "figure.h"

namespace coo_yahtzee {

	template <int value>
	class fig_superior : public figure {

	public:

	protected:

		fig_superior();
		//fig_superior(const fig_superior&);
		~fig_superior() override = default;

	private:

		virtual bool check_figure(const std::vector<dice*>&) const override;
		virtual int get_score(const std::vector<dice*>&) const override;

		friend class score;
		
	};

	template <int value>
	fig_superior<value>::fig_superior() : figure(std::to_string(value))
	{}

	template <int value>
	bool fig_superior<value>::check_figure(const std::vector<dice*>& game) const {

		for (const dice* d : game)
			if (d->get_value() == value)
				return true;

		return false;
	}

	template <int value>
	int fig_superior<value>::get_score(const std::vector<dice*>& game) const {

		int count = NULL;

		for (const dice* d : game)
			if (d->get_value() == value)
				count++;

		return count;
	}
}
