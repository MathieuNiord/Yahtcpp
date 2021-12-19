#include "pch.h"
#include "CppUnitTest.h"

#include "../Yahtzee_COO/score.h"
#include "../Yahtzee_COO/score.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace coo_yahtzee {

	TEST_CLASS(Test_Score) {

	public:

		TEST_METHOD(test_score_init) {

			// Initialization
			const auto* score_ = new score();

			// Assertions
			Assert::IsNotNull(score_);
			Assert::AreEqual(0, score_->score_);
			Assert::AreEqual(max_inferiors + max_superiors, score_->remaining_count_);

			// Destruction
			delete score_;
		}

		TEST_METHOD(test_score_all) {

			// Initialization
			auto* score_ = new score();
			score_->score_all();

			// Assertions

			Assert::AreEqual(0, score_->score_);
			Assert::AreEqual(0, score_->remaining_count_);

			for (const figure* sup : score_->superiors) {
				Assert::IsTrue(sup->scored_);
				Assert::AreEqual(0, sup->score_);
			}

			for (const figure* sup : score_->superiors) {
				Assert::IsTrue(sup->scored_);
				Assert::AreEqual(0, sup->score_);
			}

			// Destruction
			delete score_;
		}

	};
}
