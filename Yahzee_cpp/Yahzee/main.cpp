/* Authors : Frejoux G. & Niord M. */

#include <iostream>
#include "display.h"
#include "game.h"

using namespace std;
using namespace coo_yahtzee;

int main(int argc, char* argv[]) {
	srand((unsigned)time(0));

    cout << "How many player : ";
    game g(get_input_int());
    g.play();

	return EXIT_SUCCESS;

}
