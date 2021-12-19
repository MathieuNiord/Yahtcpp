/* Authors : Frejoux G. & Niord M. */

#include <iostream>
#include "display.h"
#include "game.h"

using namespace std;
using namespace coo_yahtzee;

int main(int argc, char* argv[]) {

    display_home();
    int mod;
    int number_player;

    std::cout
        << "Veuillez choisir un mode de jeu :\n"
        << "1. Sans Intelligence Artificielle\n"
        << "2. Avec Intelligence Artificielle\n"
        << "Choix : ";
    mod = get_input_int(1, 2);

    cout << "How many players : ";
    number_player = get_input_int(1, 10);
    
	srand((unsigned)time(0));
    
    game g(number_player,mod);
    g.play();

	return EXIT_SUCCESS;

}
