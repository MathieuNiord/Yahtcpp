/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "figure.h"

namespace coo_yahtzee {

	template <const char* Name, const int Value>
	class fig_superior : public figure {

	public:

	protected:

		fig_superior();
		fig_superior(const fig_superior&);
		~fig_superior();

	private:



	};

	template <const char* Name, const int Value>
	fig_superior<Name, Value>::fig_superior() : figure() {
		
	}

	template <const char* Name, const int Value>
	fig_superior<Name, Value>::fig_superior(const fig_superior&) {
		
	}

	template <const char* Name, const int Value>
	fig_superior<Name, Value>::~fig_superior() {

	}


}
