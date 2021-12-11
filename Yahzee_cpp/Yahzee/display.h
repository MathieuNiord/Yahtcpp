#pragma once

#include "resources.h"

namespace coo_yahtzee {

	// === ERRORS ===

	const std::string error_01("Votre choix est malheureusement indisponible pour le moment. SVP retentez.");
	const std::string error_02("On va fermer les yeux pour cette fois...On reprend depuis le depart.");
	const std::string error_03("Franchement, ca arrive a tout le monde de se tromper. On reprend.");
	const std::string error_04("Bah alors ? C'est pas une reponse ca...");
	const std::string error_05("Mince mais vous etes bigleux ??? C'est quoi cette reponse tecla ?");

	inline std::string get_error() {

		srand((unsigned) time(0));
		const int which_one = rand() % 1000;

		switch (which_one % 5) {
			case 1: return "\n\n" + error_01 + "\n\n";
			case 2: return "\n\n" + error_02 + "\n\n";
			case 3: return "\n\n" + error_03 + "\n\n";
			case 4: return "\n\n" + error_04 + "\n\n";
			case 0: return "\n\n" + error_05 + "\n\n";
			default: return "\n\nCe choix n'existe pas.\n\n";
		}
	}

	static int speedrun() {

		std::string player_name;

		std::cout << "\n\nQuel est votre nom ?\n\nMon nom est ";
		std::cin >> player_name;

		std::cout << "\n\n\tEXCELLENT TRAVAIL " << player_name << " !\n\n\tVous venez de speedrun un jeu qui a pris plusieurs heures a etre developpe !\n\n";
		std::cout << "\tAvec l'ensemble de nos remerciements,\n\n\tMessieurs Frejoux & Niord.\n\n";
		std::cout << "\t( PS : Une plainte vient d'etre emise a votre nom pour manque de respect de ouf. )\n\n";

		return EXIT_SUCCESS;
	}

	static int player_choices(int count) {

		int choice;

		std::cout
			<< " ============= CHOIX ===============\n"
			<< "|                                   |\n"
			<< "|    Que souhaitez - vous faire ?   |\n"
			<< "|                                   |\n"
			<< "| 1. Relancer (" << count << " coups restants)    |\n"
			<< "| 2. Inscrire votre score           |\n"
			<< "| 3. jui foutu j'rage quit          |\n"
			<< "|                                   |\n"
			<< " ===================================\n\n"
			<< "Je choisis ";

		std::cin >> choice;

		if (choice < 1 || choice > 3) {
			std::cout << get_error();
			return player_choices(count);
		}

		return choice;
	}

	static int player_roll() {

		int choice;

		std::cout
			<< " ============= RELANCE =============\n"
			<< "|                                   |\n"
			<< "| 1. Relancer tous les des          |\n"
			<< "| 2. Choisir mes des                |\n"
			<< "|                                   |\n"
			<< " ===================================\n\n"
			<< "Je choisis ";

		std::cin >> choice;

		if (choice < 1 || choice > 2) {
			std::cout << get_error();
			return player_roll();
		}

		return choice;
	}

}
