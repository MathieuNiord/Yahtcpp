/* Authors : Frejoux G., Niord M. */

#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace coo_yahtzee {
	TEST_CLASS(test_score) {

	public:
		score s;
		TEST_METHOD_INITIALIZE(setup) 
		{
		}
		TEST_METHOD_CLEANUP(cleanup)
		{
		}

		TEST_METHOD(test_score_init) {		
			Assert::AreEqual(0, s.score_);
			Assert::AreEqual(13, (int)(s.inferiors.size() + s.superiors.size()));
			Assert::AreEqual(13, s.remaining_count_);
		}

		TEST_METHOD(test_score_all) {

			s.score_all();

			for (figure* sup : s.superiors)
				Assert::IsTrue(sup->scored_);

			for (figure* inf : s.inferiors)
				Assert::IsTrue(inf->scored_);

		}

		TEST_METHOD(test) {

		}

	};

}

