#include "pch.h"
#include "CppUnitTest.h"

#include "../Yahzee//resources.h"
#include "../Yahzee/dice.h"
#include "../Yahzee/roll.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace coo_yahtzee {

	TEST_CLASS(Test_Roll) {

		private:




		public:

			static std::vector<dice*> dices;
			static roll* roll_;

			TEST_CLASS_INITIALIZE(setup) {

				dices.reserve(number_of_dices);

				for (int i = 0; i < number_of_dices; i++)
					dices.push_back(new dice);

				roll_ = new roll(dices);
			}

			TEST_CLASS_CLEANUP(clean) {

				delete roll_;

				for (const dice* d : dices)
					delete d;

				dices.clear();
			}
		
			TEST_METHOD(test_roll_init) {
				Assert::IsNotNull(roll_);
			}
	};
}
