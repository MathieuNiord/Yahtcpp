#include "pch.h"
#include "CppUnitTest.h"

#include "../Yahtzee_COO/resources.h"
#include "../Yahtzee_COO/score.h"
#include "../Yahtzee_COO/player.h"
#include "../Yahtzee_COO/ai_player.h"
#include "../Yahtzee_COO/score.cpp"
#include "../Yahtzee_COO/player.cpp"
#include "../Yahtzee_COO/ai_player.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace coo_yahtzee {

	TEST_CLASS(Test_Player) {

public:

	const std::string& player_name = "Player";
	const std::string& bot_name = "Bot";

	TEST_METHOD(test_player_init) {

		// Initialization
		const player* player_ = new player(player_name);

		// Assertions
		Assert::IsNotNull(player_);
		Assert::AreEqual(0, player_->advertise_count_);
		Assert::IsFalse(player_->eliminated_);
		Assert::AreEqual(player_name, player_->c_name_);

		// Destruction
		delete player_;
	}

	TEST_METHOD(test_bot_init) {

		// Initialization
		const ai_player* bot_ = new ai_player(bot_name);

		// Assertions
		Assert::IsNotNull(bot_);
		Assert::AreEqual(bot_name, bot_->c_name_);

		// Destruction
		delete bot_;
	}

	TEST_METHOD(test_advertise_player) {
	}

	};
}
