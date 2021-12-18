/* Authors : Frejoux G., Niord M. */

#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace coo_yahtzee {

	TEST_CLASS(test_figure) {

public:
	figure* superior;
	figure* full;
	figure* brelan;
	figure* little;
	figure* yaht;
	std::vector<dice*> dices;

	TEST_METHOD_INITIALIZE(setup) {
		superior = new fig_superior<3>();
		full = new full_house;
		brelan = new many_of_kind<3>("brelan");
		little = new straight<4>("petite");
		yaht = new yahtzee;

		for (int i = 0; i < number_of_dices; i++) {
			dices.push_back(new dice);
			dices.at(i)->value_ = i + 1;
		}
	}
	TEST_METHOD_CLEANUP(cleanup)
	{
		delete superior;
		delete full;
		delete brelan;
		delete little;
		delete yaht;
		for (int i = 0; i < number_of_dices; i++) {
			delete dices.at(i);
		}
	}
	TEST_METHOD(test_figures_init) {

		//superior init
		std::string expected_superior("3");
		
		Assert::AreEqual(expected_superior, superior->c_name_);
		Assert::AreEqual(0, superior->score_);
		Assert::AreEqual(false, superior->scored_);

		//full_house init
		full_house full;
		std::string expected_full("3");

		Assert::AreEqual(expected_full, full.c_name_);
		Assert::AreEqual(0, full.score_);
		Assert::AreEqual(false, full.scored_);

		//many_of_kind init
		many_of_kind<3> brelan("Brelan");
		std::string expected_brelan("Brelan");

		Assert::AreEqual(expected_brelan, brelan.c_name_);
		Assert::AreEqual(0, brelan.score_);
		Assert::AreEqual(false, brelan.scored_);

		//straight init
		straight<4> little("petite");
		std::string expected_little("petite");

		Assert::AreEqual(expected_little, little.c_name_);
		Assert::AreEqual(0, little.score_);
		Assert::AreEqual(false, little.scored_);

		//yahtzee init
		yahtzee yaht;
		std::string expected_yaht("Yahtzee");

		Assert::AreEqual(expected_superior, yaht.c_name_);
		Assert::AreEqual(0, yaht.score_);
		Assert::AreEqual(false, yaht.scored_);
		
	}

	TEST_METHOD(test_figure_scored) {
		superior->set_score(dices);
		full->set_score(dices);
		brelan->set_score(dices);
		little->set_score(dices);
		yaht->set_score(dices);

		Assert::IsTrue(superior->scored_);
		Assert::IsTrue(full->scored_);
		Assert::IsTrue(brelan->scored_);
		Assert::IsTrue(little->scored_);
		Assert::IsTrue(yaht->scored_);
	}

	TEST_METHOD(test_figure_score) {
		Assert::AreEqual(3, superior->get_score(dices));
		Assert::AreEqual(0, full->get_score(dices));
		Assert::AreEqual(0, brelan->get_score(dices));
		Assert::AreEqual(30, little->get_score(dices));
		Assert::AreEqual(0, yaht->get_score(dices));

		for (int i = 0; i < number_of_dices; i++) {
			dices.at(i)->value_ = 3;
		}

		Assert::AreEqual(15, superior->get_score(dices));
		Assert::AreEqual(25, full->get_score(dices));
		Assert::AreEqual(15, brelan->get_score(dices));
		Assert::AreEqual(0, little->get_score(dices));
		Assert::AreEqual(50, yaht->get_score(dices));
	}

	};
}
