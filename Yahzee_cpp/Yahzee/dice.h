/* Authors : Frejoux G. & Niord M. */

#pragma once

namespace coo_yahtzee {

	constexpr int MIN = 1;
	constexpr int MAX = 6;

	class dice {

	public:

		// Getters
		int get_value() const;

	protected:

	private:

		int value;

		dice(const int& value);
		dice(const dice&);
		~dice();

		void roll();

		friend class roll;

	};

}