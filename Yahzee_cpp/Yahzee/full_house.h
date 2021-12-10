/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "figure.h"

namespace coo_yahtzee {

	class full_house : public figure {

	public:

		full_house();

	private:

		bool check_figure(const std::vector<dice*>&) const override;
		int get_score_preview(const std::vector<dice*>&) const override;

	};

}


