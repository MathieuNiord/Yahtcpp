#include "pch.h"
#include "CppUnitTest.h"

#include "../Yahtzee_COO/fig_superior.h"
#include "../Yahtzee_COO/many_of_kind.h"
#include "../Yahtzee_COO/full_house.h"
#include "../Yahtzee_COO/straight.h"
#include "../Yahtzee_COO/yahtzee.h"
#include "../Yahtzee_COO/figure.cpp"
#include "../Yahtzee_COO/full_house.cpp"
#include "../Yahtzee_COO/yahtzee.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace coo_yahtzee {

	TEST_CLASS(Test_Figure) {

		public:

		TEST_METHOD(test_figures_init) {

			std::vector<dice*> dices;


			figure* superior = new fig_superior<3>();
			figure* full = new full_house;
			figure* brelan = new many_of_kind<3>("brelan");
			figure* little = new straight<4>("petite");
			figure* yaht = new yahtzee;

			for (int i = 0; i < number_of_dices; i++) {
				dices.push_back(new dice);
				dices.at(i)->value_ = i + 1;
			}

			//superior init
			const std::string expected_superior("3");
			Assert::IsNotNull(superior);
			Assert::AreEqual(expected_superior, superior->c_name_);
			Assert::AreEqual(0, superior->score_);
			Assert::AreEqual(false, superior->scored_);

			//full_house init
			const std::string expected_full("Full");
			Assert::IsNotNull(full);
			Assert::AreEqual(expected_full, full->c_name_);
			Assert::AreEqual(0, full->score_);
			Assert::AreEqual(false, full->scored_);

			//many_of_kind init
			const std::string expected_brelan("brelan");
			Assert::IsNotNull(brelan);
			Assert::AreEqual(expected_brelan, brelan->c_name_);
			Assert::AreEqual(0, brelan->score_);
			Assert::AreEqual(false, brelan->scored_);

			//straight init
			const std::string expected_little("petite");
			Assert::IsNotNull(little);
			Assert::AreEqual(expected_little, little->c_name_);
			Assert::AreEqual(0, little->score_);
			Assert::AreEqual(false, little->scored_);

			//yahtzee init
			const std::string expected_yaht("Yahtzee");
			Assert::IsNotNull(yaht);
			Assert::AreEqual(expected_yaht, yaht->c_name_);
			Assert::AreEqual(0, yaht->score_);
			Assert::AreEqual(false, yaht->scored_);
		
			delete superior;
			delete full;
			delete brelan;
			delete little;
			delete yaht;
			for (int i = 0; i < number_of_dices; i++) {
				delete dices.at(i);
			}
		}

		TEST_METHOD(test_figure_scored) {

			std::vector<dice*> dices;
			for (int i = 0; i < number_of_dices; i++) {
				dices.push_back(new dice);
				dices.at(i)->value_ = i + 1;
			}

			figure* superior = new fig_superior<3>();
			figure* full = new full_house;
			figure* brelan = new many_of_kind<3>("brelan");
			figure* little = new straight<4>("petite");
			yahtzee* yaht = new yahtzee;

			superior->set_score(dices);
			full->set_score(dices);
			brelan->set_score(dices);
			little->set_score(dices);
			yaht->set_score(dices);

			Assert::IsTrue(superior->scored_);
			Assert::IsTrue(full->scored_);
			Assert::IsTrue(brelan->scored_);
			Assert::IsTrue(little->scored_);
			Assert::AreEqual(1, yaht->count_);

			delete superior;
			delete full;
			delete brelan;
			delete little;
			delete yaht;
			for (int i = 0; i < number_of_dices; i++) {
				delete dices.at(i);
			}
		}

		TEST_METHOD(test_figure_score) {

			std::vector<dice*> dices;
			dices.reserve(number_of_dices);

			for (int i = 0; i < number_of_dices; i++) {
				dices.push_back(new dice);
				dices.at(i)->value_ = i + 1;
			}


			figure* superior = new fig_superior<3>();
			figure* full = new full_house;
			figure* brelan = new many_of_kind<3>("brelan");
			figure* little = new straight<4>("petite");
			figure* yaht = new yahtzee;


			Assert::AreEqual(3, superior->get_score_preview(dices));
			Assert::AreEqual(0, full->get_score_preview(dices));
			Assert::AreEqual(0, brelan->get_score_preview(dices));
			Assert::AreEqual(30, little->get_score_preview(dices));
			Assert::AreEqual(0, yaht->get_score_preview(dices));

			for (int i = 0; i < number_of_dices; i++) {
				dices.at(i)->value_ = 5;
			}

			Assert::AreEqual(50, yaht->get_score_preview(dices));

			delete superior;
			delete full;
			delete brelan;
			delete little;
			delete yaht;

			for (int i = 0; i < number_of_dices; i++) {
				delete dices.at(i);
			}
		}
	};
}
