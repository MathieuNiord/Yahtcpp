﻿/* Authors : Frejoux G. & Niord M. */

#include <iostream>
#include "display.h"
#include "game.h"

using namespace std;
using namespace coo_yahtzee;

int main(int argc, char* argv[]) {

    display_home();

	srand((unsigned)time(0));

    cout << "How many players : ";
    game g(get_input_int());
    g.play();

	return EXIT_SUCCESS;

}
