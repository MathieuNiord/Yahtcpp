/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "utils.h"

namespace coo_yahtzee {

	static void display_home() {
		std::cout
			<< "\n\n\t\t\tdddddddddddddddddddddddddddddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyhhhhhyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdhhhhhhhhhhhdd\n"
			<< "\t\t\tdddddddddddddddddddddddddddddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyhhhhhhyyyyhhhyyyyyyyhhyyyyyyyhhhhyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
			<< "\t\t\tddddhhhhdddddddddddhdhhhhhdddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyhhyyyyyssyyyyyyyyyyyyyyyyhysoosyhhhhhyo:...-/shhhhhhhhhhhhhhhhhhhhhhhhh\n"
			<< "\t\t\thyyyyyyyyyyhhdddddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyso+/yyyyyyyyys.``-dyyyyyssoo+//yys/.````.:yhho.` `-.` `/hhhhhhhhhhhhhhhhhhhhhhhh\n"
			<< "\t\t\tyyyyyyyyyyyyyyhhddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyy.` `hhyyyyyyyo`  .os:-.`````  :d+` `:+/.  .ys`  /ddho` `ohhhhhhhhhhhhhhhhhhhhhhh\n"
			<< "\t\t\tyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyhhysooyyyyyyyyyyy.  `yyoo+osy/.    `s..-://-` -ho` `ohyso`  /:  `---..`  -dhhhhhhhhhhhhhhhhhhhhhh\n"
			<< "\t\t\thyyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyy+-.`.hhyyyyyyyssy.  `..``  `++-   .ydyhhhy/``:hh-  `..``````-.  `--:::///+mhhhhhhhhhhhhhhhhhhhhhh\n"
			<< "\t\t\tyhhyyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhhhhhhyysoohhyyys`  `sdyyso+/:-./h.  `-/+-   -ds`  -dyyyyo.``odhs`  `/+oossyyh-  `yhhhhsssyhhhhhhhhhhhhhhhhhhhhhhh\n"
			<< "\t\t\tyyyhhyyyyyyysyyyyyyyyyyhhhhhhhhhhhhhhhhhhy/-.``+hyyy-   +ms/.````   /d.  `hhho`  -do`  -dyys/` -ydyyy-  `yhyyo/::oo`  -oso-``.ydhhyyyhhhhhhhhhhhhhhhhh\n"
			<< "\t\t\thyyyhhyyysyyyyssyyyyyyyyyhhhhhhhhhhhhhhhhhs.   `+hy/`  :d/` .+sy+   /d.  `hyyo`  -do`  -dys-` :dhsssso.  .//:` `/dho-` `````:hdhyyyyyyhhhhhhhhhhhhhhhh\n"
			<< "\t\t\thhyyyyhhyyssyyyyssyyysyyyyyhhhhhhhhhhhhhhhhs.   `os`  .h:  -hdyy+   /d.  `hyso`  -do`  -ds-  `//--...hs:.````.:sdhyyys+//+shdhhyyyyyyhhhhhhhhhhhhhhhhh\n"
			<< "\t\t\tyhdhyyyyhhyyssyyysssyyysyyyyyhhhhhhyyyyyyyyys-   `-  `s+  `sdyys/   /d.  `hyso`  -do`  -d/   ```..-:/dyyssssyhdhyyyyyyyhhhhhyyyyyyyyyyhhhhhhhhhhhhhhhh\n"
			<< "\t\t\tyyyhdhyyyyhyysssyyysssyyysyyyyyhhhhhyyyyyyyyyy-      +d.  `hhyys/   /d.  `hyso`  -do`..:d/+ossyyhhhhhyyssssyyyysssyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhh\n"
			<< "\t\t\tdhyyhdhyyyyhhyysosyyysosyyysyyyyyyhhyyyyyyyyyyy:    -dy.   oysss.   /d.  `hyso-:/odssyhhyyyyssssssssssssssssssssssyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhh\n"
			<< "\t\t\thddyyyhdhyysyhhyso+syyssosyyysyyyyyyhyyyyyyyyyyy.   ohy:   `//:..  `/h-:+ohsssyhyyssssossssssssssssssssssssssssssssyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhh\n"
			<< "\t\t\thhddhyyyhdyyysyhhys++syysoosyyyyyyyyyyyyyyyyyyyy.   +hss-`   ``/s+syhyyyyyssssssssssssoossssssssssssssssssssssssssssssyyyyssyyyyyyyyyyyyyyyyyyyyhhhhhh\n"
			<< "\t\t\tdhhhddyyyhdhyyssyhyyo/+yhysosyyyyyyyyyyyyyyyyysy.   ohssso++oyhhyyyssssssssssssssossssooosssoossssssssossssssssssssssyyyysssyyyyyyyyyyyyyyyyyyyhhhhhhh\n"
			<< "\t\t\tdmdhhddhyyyhdhyssshhyyo/shyssssyyyhhhyyyyyyyysss.`.:yhsssssyyssssssssoooossooooooossssoooosoooosssssssosssssssssssssyyyssssyyyyyyyyyyyyyyyyyyyhhhhhyhh\n"
			<< "\t\t\tddmdhhhddhyyyddyyssyhhyysssyhddddmmmmmNmdhhyyyysshdhysssssssssssssssssooooooooooooosssoooooooooooosssooosssssssssssssssssssyyyyyyyyyyyyyyyyyyhhhyyyyyh\n"
			<< "\t\t\tmdhdmhhhddhyyyhdhhyyhyyyhhhhhhhhhhdddddmmNmhhyyysssssssssssssssssoosssooooooooooooossoooooooooooossssooossssssssssssssssssssssssyyyyyyyyyyyyyyyyyyyyhh\n"
			<< "\t\t\tmmmddmdhhhddhyyhddhhhhhhhyyyyhhhhhyhhdddddmmhysyssssssssssssssoooooosssooooooooooooosoooooooooooosssoooooooossssssssssssssssssssyyyyyyyyyyyyyyyyyyyhhh\n"
			<< "\t\t\tdmmmdddmhhhdddhhhhhdhyyyyyyyyyyyyyyyyyhhhdhhyssssssssssssssssooooooooosooooooooooooosoooooooooooossoooooooooosssssssssssssssssssyyyyyyyyyyyyyyyyyyyhhh\n"
			<< "\t\t\thdmmmmddmdhhdddddddyyssoosyyyyyyyyyyo/+yshhhyoooosssssssooooooooooooooooooooooooooooooooooooooooosooooooooooosssssoosssssssssssssyyyyyyyyyyyyyyyyyyyyy\n"
			<< "\t\t\thhhmmmmdddmhhddddhyos+//:-/sysssss+:--+h++oyso+++++oosssooooooooooooooooooooooooooooooooooooooooooooooooooooosssso+//:://++ossssyyyyyyyyyyyyyyyyyyyyyy\n"
			<< "\t\t\thhhhdmdmdddmddddhhs+++s+o.//sssso+::.-+s//ss++++++++++++oooooooooooooooooooo++///++oooooo+oooooooooooooooooooo+:-.../oo++:..-:+osyssssyyyyyyyyyyyyyyyy\n"
			<< "\t\t\thhhhhdmmmmdmmddhhhh+////+:-:osoo:.-/ss////yo//////++++++/++++oooooooo++//:--/+s:`-:/+oooo++ooooooooooooo++/--.`````oNMNmm+````..:+ssssyyyyyyyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhdmmmmmddhhhhy/+o//so/ooo/-://+o////+:////////////////////++///-.````.o+:``-:::/ooo+++ooooooo++/:-..`````````.://:-````````.-/ssyyyyyyyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhdmmNmdhhhhyyyoss++oooo++////+y+//////////////://////////--sys-``````..``.:::::/oo++++oooo+:-..::::-```````.-...````````.```.-/osyyyyyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhmNmdhhhhyyyysssoo++++++///+yo///:////////::::::::://:.``..`````./ss+..-/:::::/oo+++ooo/```-dNNdmd.````-yddyhs`````.+yyoo+``.:+syyyyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhmNmdhhhyyyyssooo++++++++////////:::::::::::::::::::.`.-/:`.....//-.--::::::::++++++o:````.+sys+-`````:hmmdy/`````+NNNmms``.-:/syyyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhdmmdhhhyyssssoo++++++++///////:::::::::::::::::::.`-yyo-.......-:::::::::s+::::::::`  ````````````````..`````````-:::.``.--::/syyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhdmddhhyyssssooo++++////////:--oo:....---:::::::.```..---://///////:::::om:::::::.```````````````.:/::-```````````...--:::////yyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhddddhhyyysooo+/////////:.``::.``````.:-----:.`.://////////////////:::+:::::::.:o-..`````````/mMNdmm.``````...--::::--::/::+yyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhhyyyyysssso+++///////-````````````.-//-----..:/ydds///////////////::::::-----/Mm:--.`` ````.oyys+-```...-:::::-----+o+--::syyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhyyyyyyyysssso++++////:````````sy/`.-+s:------.//hmhh////////////////:::::------sNd-o:-.```````````..--:::::-------sNMMM/--:+yyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhyyyyyyyyyssssoo+++//:-:+/:--...---:/y-:-------://+//////////////////:::::---:---+y-mN+--.....``.--:::::----------/MMMMh----/yyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhyyyyyyyyyyssoooo++///:+hh////ss//:s/-:y--------://////////////+yys///--:----:------+mN/+/-...--::///--------------oys/-----:yyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhhhhhyyyyyyssoooo++//:///////ss+/:--o+----------://///////////smmms//:-------:------/y/yNh-..-:////:smNm/----......-..-----:syyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhhyyyyyyyyyyysooooo+///ods////+//:.y:------------//////////////+o+/+/--------:-------:-:dNs-.:///:-mMMMM+.............------oyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhyyyyyyyyyyyyyyyysooooo+///++///ohy//-/--------------:///////////////::----------:-:s/-----:sy--:///.-dNNh+...................-oyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyssooo++++////::::/:-------------------://///:::::--------------::::Nm+-----::--://:..-:--..............:++-..-syyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyssso+++++//:::::----------------------------------------------::::+mm:o/:---:::++-..................-yNMMh../yyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyysso++++++//:::::--------------------------------------------:::::/s:dNo-----:/+:..................sMMMm+.:syyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyssoo++++///::::::-----------------------------------------:::::::--/dN///:-:/+/......--..........:syo:.:oyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyysso+++/////::::::---------------------------------------::::::::::/y+sNy:-/++-...-ohdh-............-+syyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyssoo+///////::::---------------------------------------::::::::::::::dNs-:++:..-dMMMN:.......--:/osyyyyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyssoo+//////:::----------------------------------------::::::::::::-:sy-:++/-.:mNNd/....--:/osssyyyyyyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyysoo+/////:::::--------------------------------------::::::::::::::-:/++++/:-:/:..--:/+osssssyyyyyyyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyysssoo+//::::::::------------------------------------::::::::::::://////++++///::/+oooosssssssyyyyyyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysoo+//::::::::-----------------------------------::::::::::::////////////++++ooooosssssssyyyyyyyyyyyhhhh\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyysso+//:::::::::---------------------------------::::::::://///////+++++++++ooooossssssyyyyyyyyyyyyyyyy\n"
			<< "\t\t\thhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyysso+//::::::::--------------------------------::::::::://////////+++++++oooooossssssyyyyyyyyyyyyyyyy\n\n\n";

		wait_and_clean_screen();
	}

	static int display_menu() {
		std::cout
			<< "\n\t\t =======================================\n"
			<< "\t\t|                                       |\n"
			<< "\t\t|   BIENVENUE !                         |\n"
			<< "\t\t|                                       |\n"
			<< "\t\t|   Nous avons le plaisir de vous       |\n"
			<< "\t\t|   accueillir au sein de ce yahtzee.   |\n"
			<< "\t\t|                                       |\n"
			<< "\t\t|   Deux modes de jeu s'offrent a       |\n"
			<< "\t\t|   vous. Un mode solo et un mode       |\n"
			<< "\t\t|   multijoueur.                        |\n"
			<< "\t\t|                                       |\n"
			<< "\t\t|   1. J'ai des amis mais ce n'est      |\n"
			<< "\t\t|      pas reciproque                   |\n"
			<< "\t\t|                                       |\n"
			<< "\t\t|   2. On est pas tout seul !           |\n"
			<< "\t\t|                                       |\n"
			<< "\t\t|   3. Doucement ! Je ne suis meme      | \n"
			<< "\t\t|      pas initie                       |\n"
			<< "\t\t|                                       |\n"
			<< "\t\t =======================================\n\n"
			<< "Choix : ";

		int choice = get_input_int(1, 3);
		return choice;
	}

	static int display_solo_config() {

		std::cout
			<< "\n\t\t ============== CARRIERE SOLO ==============\n"
			<< "\t\t|                                           |\n"
			<< "\t\t|       Ez Peasy, ce programme est          |\n"
			<< "\t\t|       capable de generer des bots         |\n"
			<< "\t\t|                                           |\n"
			<< "\t\t|       Combien d'adversaires ?             |\n"
			<< "\t\t|                                           |\n"
			<< "\t\t ===========================================\n\n"
			<< "Nombre d'adversaire : ";

		int nb_bots = get_input_int();
		return nb_bots;
	}

	static int display_multi_config() {

		std::cout
			<< "\n\t\t ============== MULTIJOUEUR ===============\n"
			<< "\t\t|                                          |\n"
			<< "\t\t|      Avant de pouvoir lancer le          |\n"
			<< "\t\t|      mode multijoueur, merci             |\n"
			<< "\t\t|      d'indiquer le nombre de joueurs     |\n"
			<< "\t\t|      au programme.                       |\n"
			<< "\t\t|                                          |\n"
			<< "\t\t ==========================================\n\n"
			<< "Nombre de joueurs : ";

		int nb_players = get_input_int();
		return nb_players;
	}

	static void display_rules() {

		std::cout
			<< "\n\n\t\t  ===============================================================================\n"
			<< "\t\t  ===============================================================================\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  +++++++++++++++++                                                            ||\n"
			<< "\t\t||  + REGLES DU JEU +                                                            ||\n"
			<< "\t\t||  +++++++++++++++++                                                            ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  Ce jeu peut etre joue a partir de deux joueurs en multijoueur, ou seul       ||\n"
			<< "\t\t||  en mode carriere.                                                            ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  Le Yahtzee se decompose en 13 tours.Le but est d'inscrire le maximum         ||\n"
			<< "\t\t||  de points parmis les combinaisons proposees.                                 ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  Lorsque vient son tour, un joueur lance les 5 des.                           ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  Il doit alors realiser une combinaison.                                      ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  Pour la realiser, il a droit à 3 jets par tour.Pour chaque jet,              ||\n"
			<< "\t\t||  le joueur choisit les des qu’il conserve et qu’il relance.                   ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  A la fin de son tour, le joueur inscrit la combinaison dans son              ||\n"
			<< "\t\t||  score.                                                                       ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  OU, s'il le souhaite, le joueur peut se faire eliminer et attendre           ||\n"
			<< "\t\t||  la fin du jeu.                                                               ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  Le jeu sera stoppe s'il ne reste plus qu'un seul joueur                      ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  Pour plus d'informations sur comment jouer, tapez cette url dans             ||\n"
			<< "\t\t||  navigateur prefere :                                                         ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t||  https ://reglesdejeux.github.io/regles-du-jeu-yahtzee/index.html             ||\n"
			<< "\t\t||                                                                               ||\n"
			<< "\t\t  ===============================================================================\n"
			<< "\t\t  ===============================================================================\n\n";

		wait_and_clean_screen("Appuyez sur entree pour retourner au menu...");
		display_menu();
	}

	static int speedrun(std::string name ="") {

		if (name.empty()) {
			std::cout << "\n\nQuel est votre nom ?\n\nMon nom est ";
			std::getline(std::cin, name);
		}

		std::cout << "\n\n\tEXCELLENT TRAVAIL " << name << " !\n\n\tVous venez de speedrun un jeu qui a pris plusieurs heures a etre developpe !\n\n";
		std::cout << "\tAvec l'ensemble de nos remerciements,\n\n\tMessieurs Frejoux & Niord.\n\n";
		std::cout << "\t( PS : Une plainte vient d'etre emise a votre nom pour manque de respect de ouf. )\n\n";

		return EXIT_SUCCESS;
	}

}
