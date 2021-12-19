/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "figure.h"

namespace coo_yahtzee {

	template <const int Number>
	class straight : public figure {

	public:

		straight(const std::string&);

	private:

		int get_score_preview(const std::vector<dice*>&) const override;

		// Tests
		friend class Test_Figure;

	};

	template<const int Number>
	straight<Number>::straight(const std::string& name)
		: figure(name) {}

	template <const int Number>
	int straight<Number>::get_score_preview(const std::vector<dice*>& game) const {

        //since dices are sorted by value we can iterate dices and count if there is v next values

        int cpt = 1;
        int size = game.size();

        for(int i = 0 ; i < size-1 ; i++){
            if(game.at(i)->get_value() + 1 == game.at(i+1)->get_value()){
                cpt++;
                if (cpt >= Number) return (Number-1) * 10;
            }
            else cpt = 1;

        }
        return 0;
	}

}



