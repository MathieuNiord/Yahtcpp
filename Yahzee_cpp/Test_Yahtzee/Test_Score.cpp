#include "pch.h"
#include "CppUnitTest.h"

#include "../Yahtzee_COO/resources.h"
#include "../Yahtzee_COO/figure.h"
#include "../Yahtzee_COO/score.h"
#include "../Yahtzee_COO/figure.cpp"
#include "../Yahtzee_COO/score.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace coo_yahtzee {

	TEST_CLASS(Test_Score) {

public:

	TEST_METHOD(test_roll_init) {

		// Initialization
		score* score_ = new score();

		// Assertions
		Assert::IsNotNull(score_);
		Assert::AreEqual(0, score_->score_);

		// Destruction
		delete score_;
	}

	TEST_METHOD(test_roll_dices) {
	}

	TEST_METHOD(test_sort_dices) {

	}

	};
}
