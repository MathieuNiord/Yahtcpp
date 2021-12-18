/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "figure.h"

namespace coo_yahtzee {

	class full_house : public figure {

	public:

		full_house();

	private:

		int get_score(const std::vector<dice*>&) const override;
		friend class test_figure;

	};

}


