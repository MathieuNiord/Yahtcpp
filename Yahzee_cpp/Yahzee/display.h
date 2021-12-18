/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "utils.h"

namespace coo_yahtzee {

	//"\n\n\t\t\tdddddddddddddddddddddddddddddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyhhhhhyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdhhhhhhhhhhhdd\n"
	//"\t\t\tdddddddddddddddddddddddddddddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyhhhhhhyyyyhhhyyyyyyyhhyyyyyyyhhhhyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
	//"\t\t\tddddhhhhdddddddddddhdhhhhhdddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyhhyyyyyssyyyyyyyyyyyyyyyyhysoosyhhhhhyo:...-/shhhhhhhhhhhhhhhhhhhhhhhhh\n"
	//"\t\t\thyyyyyyyyyyhhdddddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyso+/yyyyyyyyys.``-dyyyyyssoo+//yys/.````.:yhho.` `-.` `/hhhhhhhhhhhhhhhhhhhhhhhh\n"
	//"\t\t\tyyyyyyyyyyyyyyhhddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyy.` `hhyyyyyyyo`  .os:-.`````  :d+` `:+/.  .ys`  /ddho` `ohhhhhhhhhhhhhhhhhhhhhhh\n"
	//"\t\t\tyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyhhysooyyyyyyyyyyy.  `yyoo+osy/.    `s..-://-` -ho` `ohyso`  /:  `---..`  -dhhhhhhhhhhhhhhhhhhhhhh\n"
	//"\t\t\thyyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyy+-.`.hhyyyyyyyssy.  `..``  `++-   .ydyhhhy/``:hh-  `..``````-.  `--:::///+mhhhhhhhhhhhhhhhhhhhhhh\n"
	//"\t\t\tyhhyyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhhhhhhyysoohhyyys`  `sdyyso+/:-./h.  `-/+-   -ds`  -dyyyyo.``odhs`  `/+oossyyh-  `yhhhhsssyhhhhhhhhhhhhhhhhhhhhhhh\n"
	//"\t\t\tyyyhhyyyyyyysyyyyyyyyyyhhhhhhhhhhhhhhhhhhy/-.``+hyyy-   +ms/.````   /d.  `hhho`  -do`  -dyys/` -ydyyy-  `yhyyo/::oo`  -oso-``.ydhhyyyhhhhhhhhhhhhhhhhh\n"
	//"\t\t\thyyyhhyyysyyyyssyyyyyyyyyhhhhhhhhhhhhhhhhhs.   `+hy/`  :d/` .+sy+   /d.  `hyyo`  -do`  -dys-` :dhsssso.  .//:` `/dho-` `````:hdhyyyyyyhhhhhhhhhhhhhhhh\n"
	//"\t\t\thhyyyyhhyyssyyyyssyyysyyyyyhhhhhhhhhhhhhhhhs.   `os`  .h:  -hdyy+   /d.  `hyso`  -do`  -ds-  `//--...hs:.````.:sdhyyys+//+shdhhyyyyyyhhhhhhhhhhhhhhhhh\n"
	//"\t\t\tyhdhyyyyhhyyssyyysssyyysyyyyyhhhhhhyyyyyyyyys-   `-  `s+  `sdyys/   /d.  `hyso`  -do`  -d/   ```..-:/dyyssssyhdhyyyyyyyhhhhhyyyyyyyyyyhhhhhhhhhhhhhhhh\n"
	//"\t\t\tyyyhdhyyyyhyysssyyysssyyysyyyyyhhhhhyyyyyyyyyy-      +d.  `hhyys/   /d.  `hyso`  -do`..:d/+ossyyhhhhhyyssssyyyysssyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhh\n"
	//"\t\t\tdhyyhdhyyyyhhyysosyyysosyyysyyyyyyhhyyyyyyyyyyy:    -dy.   oysss.   /d.  `hyso-:/odssyhhyyyyssssssssssssssssssssssyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhh\n"
	//"\t\t\thddyyyhdhyysyhhyso+syyssosyyysyyyyyyhyyyyyyyyyyy.   ohy:   `//:..  `/h-:+ohsssyhyyssssossssssssssssssssssssssssssssyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhh\n"
	//"\t\t\thhddhyyyhdyyysyhhys++syysoosyyyyyyyyyyyyyyyyyyyy.   +hss-`   ``/s+syhyyyyyssssssssssssoossssssssssssssssssssssssssssssyyyyssyyyyyyyyyyyyyyyyyyyyhhhhhh\n"
	//"\t\t\tdhhhddyyyhdhyyssyhyyo/+yhysosyyyyyyyyyyyyyyyyysy.   ohssso++oyhhyyyssssssssssssssossssooosssoossssssssossssssssssssssyyyysssyyyyyyyyyyyyyyyyyyyhhhhhhh\n"
	//"\t\t\tdmdhhddhyyyhdhyssshhyyo/shyssssyyyhhhyyyyyyyysss.`.:yhsssssyyssssssssoooossooooooossssoooosoooosssssssosssssssssssssyyyssssyyyyyyyyyyyyyyyyyyyhhhhhyhh\n"
	//"\t\t\tddmdhhhddhyyyddyyssyhhyysssyhddddmmmmmNmdhhyyyysshdhysssssssssssssssssooooooooooooosssoooooooooooosssooosssssssssssssssssssyyyyyyyyyyyyyyyyyyhhhyyyyyh\n"
	//"\t\t\tmdhdmhhhddhyyyhdhhyyhyyyhhhhhhhhhhdddddmmNmhhyyysssssssssssssssssoosssooooooooooooossoooooooooooossssooossssssssssssssssssssssssyyyyyyyyyyyyyyyyyyyyhh\n"
	//"\t\t\tmmmddmdhhhddhyyhddhhhhhhhyyyyhhhhhyhhdddddmmhysyssssssssssssssoooooosssooooooooooooosoooooooooooosssoooooooossssssssssssssssssssyyyyyyyyyyyyyyyyyyyhhh\n"
	//"\t\t\tdmmmdddmhhhdddhhhhhdhyyyyyyyyyyyyyyyyyhhhdhhyssssssssssssssssooooooooosooooooooooooosoooooooooooossoooooooooosssssssssssssssssssyyyyyyyyyyyyyyyyyyyhhh\n"
	//"\t\t\thdmmmmddmdhhdddddddyyssoosyyyyyyyyyyo/+yshhhyoooosssssssooooooooooooooooooooooooooooooooooooooooosooooooooooosssssoosssssssssssssyyyyyyyyyyyyyyyyyyyyy\n"
	//"\t\t\thhhmmmmdddmhhddddhyos+//:-/sysssss+:--+h++oyso+++++oosssooooooooooooooooooooooooooooooooooooooooooooooooooooosssso+//:://++ossssyyyyyyyyyyyyyyyyyyyyyy\n"
	//"\t\t\thhhhdmdmdddmddddhhs+++s+o.//sssso+::.-+s//ss++++++++++++oooooooooooooooooooo++///++oooooo+oooooooooooooooooooo+:-.../oo++:..-:+osyssssyyyyyyyyyyyyyyyy\n"
	//"\t\t\thhhhhdmmmmdmmddhhhh+////+:-:osoo:.-/ss////yo//////++++++/++++oooooooo++//:--/+s:`-:/+oooo++ooooooooooooo++/--.`````oNMNmm+````..:+ssssyyyyyyyyyyyyyyyy\n"
	//"\t\t\thhhhhhhdmmmmmddhhhhy/+o//so/ooo/-://+o////+:////////////////////++///-.````.o+:``-:::/ooo+++ooooooo++/:-..`````````.://:-````````.-/ssyyyyyyyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhdmmNmdhhhhyyyoss++oooo++////+y+//////////////://////////--sys-``````..``.:::::/oo++++oooo+:-..::::-```````.-...````````.```.-/osyyyyyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhmNmdhhhhyyyysssoo++++++///+yo///:////////::::::::://:.``..`````./ss+..-/:::::/oo+++ooo/```-dNNdmd.````-yddyhs`````.+yyoo+``.:+syyyyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhmNmdhhhyyyyssooo++++++++////////:::::::::::::::::::.`.-/:`.....//-.--::::::::++++++o:````.+sys+-`````:hmmdy/`````+NNNmms``.-:/syyyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhdmmdhhhyyssssoo++++++++///////:::::::::::::::::::.`-yyo-.......-:::::::::s+::::::::`  ````````````````..`````````-:::.``.--::/syyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhdmddhhyyssssooo++++////////:--oo:....---:::::::.```..---://///////:::::om:::::::.```````````````.:/::-```````````...--:::////yyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhddddhhyyysooo+/////////:.``::.``````.:-----:.`.://////////////////:::+:::::::.:o-..`````````/mMNdmm.``````...--::::--::/::+yyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhhyyyyysssso+++///////-````````````.-//-----..:/ydds///////////////::::::-----/Mm:--.`` ````.oyys+-```...-:::::-----+o+--::syyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhyyyyyyyysssso++++////:````````sy/`.-+s:------.//hmhh////////////////:::::------sNd-o:-.```````````..--:::::-------sNMMM/--:+yyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhyyyyyyyyyssssoo+++//:-:+/:--...---:/y-:-------://+//////////////////:::::---:---+y-mN+--.....``.--:::::----------/MMMMh----/yyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhyyyyyyyyyyssoooo++///:+hh////ss//:s/-:y--------://////////////+yys///--:----:------+mN/+/-...--::///--------------oys/-----:yyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhhhhhyyyyyyssoooo++//:///////ss+/:--o+----------://///////////smmms//:-------:------/y/yNh-..-:////:smNm/----......-..-----:syyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhhyyyyyyyyyyysooooo+///ods////+//:.y:------------//////////////+o+/+/--------:-------:-:dNs-.:///:-mMMMM+.............------oyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhyyyyyyyyyyyyyyyysooooo+///++///ohy//-/--------------:///////////////::----------:-:s/-----:sy--:///.-dNNh+...................-oyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyssooo++++////::::/:-------------------://///:::::--------------::::Nm+-----::--://:..-:--..............:++-..-syyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyssso+++++//:::::----------------------------------------------::::+mm:o/:---:::++-..................-yNMMh../yyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyysso++++++//:::::--------------------------------------------:::::/s:dNo-----:/+:..................sMMMm+.:syyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyssoo++++///::::::-----------------------------------------:::::::--/dN///:-:/+/......--..........:syo:.:oyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyysso+++/////::::::---------------------------------------::::::::::/y+sNy:-/++-...-ohdh-............-+syyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyssoo+///////::::---------------------------------------::::::::::::::dNs-:++:..-dMMMN:.......--:/osyyyyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyssoo+//////:::----------------------------------------::::::::::::-:sy-:++/-.:mNNd/....--:/osssyyyyyyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyysoo+/////:::::--------------------------------------::::::::::::::-:/++++/:-:/:..--:/+osssssyyyyyyyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyysssoo+//::::::::------------------------------------::::::::::::://////++++///::/+oooosssssssyyyyyyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysoo+//::::::::-----------------------------------::::::::::::////////////++++ooooosssssssyyyyyyyyyyyhhhh\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyysso+//:::::::::---------------------------------::::::::://///////+++++++++ooooossssssyyyyyyyyyyyyyyyy\n"
	//"\t\t\thhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyysso+//::::::::--------------------------------::::::::://////////+++++++oooooossssssyyyyyyyyyyyyyyyy\n\n\n");

	static int speedrun() {

		std::string player_name;

		std::cout << "\n\nQuel est votre nom ?\n\nMon nom est ";
		std::getline(std::cin, player_name);

		std::cout << "\n\n\tEXCELLENT TRAVAIL " << player_name << " !\n\n\tVous venez de speedrun un jeu qui a pris plusieurs heures a etre developpe !\n\n";
		std::cout << "\tAvec l'ensemble de nos remerciements,\n\n\tMessieurs Frejoux & Niord.\n\n";
		std::cout << "\t( PS : Une plainte vient d'etre emise a votre nom pour manque de respect de ouf. )\n\n";

		return EXIT_SUCCESS;
	}

}
