/* Authors : Frejoux G. & Niord M. */

#include <iostream>
#include "display.h"
#include "game.h"

using namespace std;
using namespace coo_yahtzee;

int main(int argc, char* argv[]) {

	srand((unsigned)time(0));

    display_home();

    while (true) {

        const int choice = display_menu();

        // Launch solo game
        if (choice == 1) {

            std::string name;

            std::cout << "\nQuel sera votre pseudo ?\n\nJe m'appelle ";
            std::getline(std::cin, name);

            clear_screen();

            const int nb_bots = display_solo_config();

            if (nb_bots > 0) {
                game game(name, nb_bots);
                wait_and_clean_screen("\nAppuyez sur Entree pour lancer le jeu...");
                game.play();
                wait_and_exit("\nAppuez sur Entree pour quitter...");
            }

            else
                speedrun(name);

            break;
        }

        // Launch multiplayers game
    	if (choice == 2) {

            clear_screen();

            const int nb_players = display_multi_config();

            if (nb_players > 1) {
                game game(nb_players);
                wait_and_clean_screen("\nAppuyez sur Entree pour lancer le jeu...");
                game.play();
                wait_and_exit("\nAppuez sur Entree pour quitter...");
            }

            else
                speedrun();

            break;
        }

        // Display rules and return to the menu
    	if (choice == 3) {
            clear_screen();
            display_rules();
            wait_and_clean_screen("Appuyez sur Entree pour revenir au menu...");
        }

    	else
    		std::cout << get_error();

    }

	return EXIT_SUCCESS;

}
