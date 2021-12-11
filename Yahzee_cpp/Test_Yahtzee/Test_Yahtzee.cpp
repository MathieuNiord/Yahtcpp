/* Authors : Frejoux G., Niord M. */

#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <vector>

#include "../Yahzee/dice.h"
#include "../Yahzee/roll.h"

namespace coo_yahtzee {
	class dice;
	class roll;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace coo_yahtzee;

namespace test_yahtzee {

	TEST_CLASS(test_roll) {

	public:

		std::vector<dice*> game;

		TEST_METHOD(test_dice_init) {
			Assert::IsNotNull(new dice);
		}

		TEST_METHOD(test_dice_roll) {

			dice dice_01;
			const int first_value = dice_01.get_value();

			dice_01.roll();

			if (dice_01.get_value() == first_value)
				dice_01.roll();
			
			Assert::AreNotEqual(first_value, dice_01.get_value());
		}


		TEST_METHOD(test_roll_init) {

			for (int i = 0; i < 6; i++)
				game.push_back(new dice);

			Assert::IsNotNull(new roll(game));
		}

		TEST_METHOD(test_roll_dices) {

			roll r(game);

		}

		TEST_METHOD(TestMethod5) {}
		TEST_METHOD(TestMethod6) {}

	};
}
