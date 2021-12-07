/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "figure.h"

namespace coo_yahtzee {

	namespace inferior_figure {

		constexpr int MAX_YAHTZEE = 2;

		class yahtzee : public figure {

		public:

			yahtzee();
			yahtzee(const yahtzee&);
			~yahtzee();

		protected:

			bool check_figure(const std::vector<dice*>&) const override;
			int get_score(const std::vector<dice*>&) const override;

		private:

			int count;

		};

	}

}