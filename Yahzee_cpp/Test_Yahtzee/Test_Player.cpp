#include "pch.h"
#include "CppUnitTest.h"

#include "../Yahtzee_COO/player.h"
#include "../Yahtzee_COO/ai_player.h"
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

			// Initialization
			player* player_ = new player(player_name);

			// Assertions
			Assert::AreEqual(0, player_->advertise_count_);

			player_->advertise_player("0");
			Assert::AreEqual(0, player_->advertise_count_);

			player_->advertise_player("advertise");
			Assert::AreEqual(1, player_->advertise_count_);

			player_->advertise_player("advertise");
			player_->advertise_player("advertise");
			Assert::AreEqual(3, player_->advertise_count_);

			// Destruction
			delete player_;
		}

		TEST_METHOD(test_eliminate_player) {

			// Initialization
			player* player_ = new player(player_name);

			// Assertions
			Assert::IsFalse(player_->eliminated_);

			player_->eliminate();

			Assert::IsTrue(player_->eliminated_);

			// Destruction
			delete player_;
		}


		TEST_METHOD(test_score_result) {

			// Initialization
			player* player_ = new player(player_name);
			player_->score_all();

			// Assertions
			Assert::AreEqual(0, player_->get_score_result());

			
			// Destruction
			delete player_;
		}

		TEST_METHOD(test_bot_round) {

			// Initialization
			std::vector<dice*> dices;

			dices.reserve(number_of_dices);

			for (int i = 0; i < number_of_dices; i++)
				dices.push_back(new dice);

			roll roll_(dices);
			roll_.roll_dices();

			auto* bot_ = new ai_player(bot_name);
			bot_->play_round(roll_);
			bot_->score_all();

			// Assertions
			Assert::AreNotEqual(0, bot_->get_score_result());

			// Destruction
			delete bot_;
		}
	};
}
