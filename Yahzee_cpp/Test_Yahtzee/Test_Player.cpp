/* Authors : Frejoux G., Niord M. */

#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace coo_yahtzee {

	TEST_CLASS(test_player) {

	public:
		player* human;
		player* robot;
		TEST_METHOD_INITIALIZE(setup)
		{
			human = new player("human");
			robot = new ai_player("robot");
		}
		TEST_METHOD_CLEANUP(cleanup)
		{
			delete human;
			delete robot;
		}

		TEST_METHOD(test_player_init) 
		{
			//human init
			std::string human_name = "human";
			Assert::AreEqual(0, human->advertise_count_);
			Assert::AreEqual(human_name, human->c_name_);
			Assert::IsFalse(human->eliminated_);
			Assert::AreEqual(0,human->player_score_->score_);

			//robot init
			std::string robot_name = "robot";
			Assert::AreEqual(0, robot->advertise_count_);
			Assert::AreEqual(robot_name, robot->c_name_);
			Assert::IsFalse(robot->eliminated_);
			Assert::AreEqual(0, robot->player_score_->score_);

		}

		TEST_METHOD(test_player_advertise) 
		{
			human->advertise_player("advertise");
			Assert::AreEqual(1, human->advertise_count_);

		}

		TEST_METHOD(test_eliminate) 
		{

		}

		};
}
