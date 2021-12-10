/* Authors : Frejoux G. & Niord M. */

#include <iomanip>
#include <iostream>
#include "game.h"

using namespace std;
//using namespace coo_yahtzee;

int main(int argc, char* argv[]) {

	/*int nb_player;

	std::cout << "==Yahtzee==" << std:: endl;
	std::cout << "Please, how many players : ";
	std::cin >> nb_player;*/

	int score1 = 100;
	int score2 = 0;
	int score3 = 50;

	cout << "\n\t=============================================\n"
		 << "\t============== SCORE Joueur 1 ===============\n\n"
		 
		 << "\t --------------------------------------------\n"
		 << "\t| Partie superieure    | Score               |\n"
		 << "\t|---------------------------------------------\n"
		 << "\t| 1" << setw(23) << " | 0" << setw(21) << "|\n"
		 << "\t| 2" << setw(23) << " | 0" << setw(21) << "|\n"
		 << "\t| 3" << setw(23) << " | 0" << setw(21) << "|\n"
		 << "\t| 4" << setw(23) << " | 0" << setw(21) << "|\n"
		 << "\t| 5" << setw(23) << " | 0" << setw(21) << "|\n"
		 << "\t| 6" << setw(23) << " | 0" << setw(21) << "|\n"
		 << "\t --------------------------------------------\n\n"
		 
		 << "\t --------------------------------------------\n"
		 << "\t| Partie inferieure    | Score               |\n"
		 << "\t|---------------------------------------------\n"
		 << "\t| Brelan" << setw(23 - 8) << "|" << " " << score1 << setw(22 - (to_string(score1).length() - 1)) << "|\n"
		 << "\t| Carre" << setw(23 - 7) << "|" << " " << score2 << setw(22 - (to_string(score2).length() - 1)) << "|\n"
		 << "\t| Full" << setw(23 - 4) << " | 0" << setw(22) << "|\n"
		 << "\t| Petite suite" << setw(23 - 14) << "|" << " " << score3 << setw(22 - (to_string(score3).length() - 1)) << "|\n"
		 << "\t| Grande suite" << setw(23 - 12) << " | 0" << setw(22) << "|\n"
		 << "\t| Yahtzee" << setw(23 - 7) << " | 0" << setw(22) << "|\n"
		 << "\t| Chance" << setw(23 - 6) << " | 0" << setw(22) << "|\n"
		 << "\t --------------------------------------------\n\n"
		 
		 << "\t=============================================\n"
		 << "\t=============================================\n";

	//TODO call game constructor with nb_player

	return EXIT_SUCCESS;

}
