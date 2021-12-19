#include "pch.h"
#include "CppUnitTest.h"

#include "../Yahtzee_COO/resources.h"
#include "../Yahtzee_COO/dice.h"
#include "../Yahtzee_COO/roll.h"
#include "../Yahtzee_COO/dice.cpp"
#include "../Yahtzee_COO/roll.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace coo_yahtzee {

	TEST_CLASS(Test_Roll) {

		public:

			TEST_METHOD(test_dice_init) {
				dice* dice_01 = new dice;
				Assert::IsNotNull(dice_01);
				delete dice_01;
			}

			TEST_METHOD(test_dice_roll) {

				srand((unsigned)time(0));

				dice dice_01;
				const int first_value = dice_01.get_value();

				dice_01.roll();

				if (dice_01.get_value() == first_value)
					dice_01.roll();

				Assert::AreNotEqual(first_value, dice_01.get_value());
			}

			TEST_METHOD(test_roll_init) {

				// Initialization
				std::vector<dice*> dices;
				dices.reserve(number_of_dices);

				for (int i = 0; i < 6; i++)
					dices.push_back(new dice);

				const auto* roll_ = new roll(dices);

				// Assertions
				Assert::IsNotNull(roll_);
				Assert::AreEqual(dices.at(0)->get_value(), roll_->dices_.at(0)->get_value());
				Assert::AreEqual(0, roll_->round_count_);

				// Destruction
				delete roll_;

				for (const dice* d : dices)
					delete d;

				dices.clear();
			}

			TEST_METHOD(test_roll_dices) {

				srand((unsigned)time(0));

				// Initialization
				std::vector<dice*> dices;
				dices.reserve(number_of_dices);

				for (int i = 0; i < 6; i++)
					dices.push_back(new dice);

				auto* roll_ = new roll(dices);

				// Assertions
				Assert::AreEqual(0, roll_->round_count_);
				roll_->roll_dices();
				Assert::AreEqual(1, roll_->round_count_);

				// Destruction
				delete roll_;

				for (const dice* d : dices)
					delete d;

				dices.clear();
			}

			TEST_METHOD(test_sort_dices) {

				srand((unsigned)time(0));

				// Initialization
				std::vector<dice*> dices;
				dices.reserve(number_of_dices);

				for (int i = 0; i < 6; i++)
					dices.push_back(new dice);

				auto* roll_ = new roll(dices);

				// Assertions

				roll_->roll_dices();
				roll_->sort_dices();
				int prev_value = roll_->dices_.at(0)->get_value();

				for (const dice* d : roll_->dices_) {
					Assert::IsTrue(prev_value <= d->get_value());
					prev_value = d->get_value();
				}

				// Destruction
				delete roll_;

				for (const dice* d : dices)
					delete d;

				dices.clear();
			}

	};
}
