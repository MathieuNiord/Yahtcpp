/* Authors : Frejoux G. & Niord M. */

#pragma once

#include <iostream>

namespace coo_yahtzee {

	template <const char* Name>
	class figure {

	public:

	protected:

		const std::string c_name;
		int score_;
		bool scored_;

		figure();
		figure(const figure&);
		~figure();

	private:

		friend class player;
		friend class score;

	};

	template <const char* Name>
	figure<Name>::figure() : c_name(Name) {
		score_ = 0;
		scored_ = false;
	}


}
