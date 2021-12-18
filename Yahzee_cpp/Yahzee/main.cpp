/* Authors : Frejoux G. & Niord M. */

#include <iostream>
#include "display.h"
#include "game.h"

using namespace std;
using namespace coo_yahtzee;

int main(int argc, char* argv[]) {

	srand((unsigned)time(0));

    game g(1);
    g.play();

	return EXIT_SUCCESS;

}
