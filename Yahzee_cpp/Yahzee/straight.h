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
		int get_score(const std::vector<dice*>&) const override;

	};

	template<const int Number>
	straight<Number>::straight(const std::string& name)
		: figure(name) {}

	template <const int Number>
	bool straight<Number>::check_figure(const std::vector<dice*>& game) const {

        //since dices are sorted by value we can iterate dices and count if there is v next values

        int cpt = 1;
        int size = game.size();

        for(int i = 0 ; i < size-1 ; i++){

            if(game.at(i)->get_value() + 1 == game.at(i+1)->get_value()){
                cpt++;
                if (cpt >= Number) return true;
            }
            else cpt = 1;

        }
        return false;

	}

	template <const int Number>
	int straight<Number>::get_score(const std::vector<dice*>& game) const {

		if (check_figure(game))
			return (Number - 1) * 10;

		return 0;
	}

}



