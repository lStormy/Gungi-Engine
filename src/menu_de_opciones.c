#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void credits() {
    printf(
        "================= CREDITS =================\n"
        "   GUNGI — Project in C (terminal version)\n"
        "   Developed by: Lucio Storni && Christian Scornaienchi\n"
        "   Inspired by the fictional game Hunter x Hunter\n"
        "   Year: 2025\n"
        "===========================================\n\n"
    );
}

void pause() {
    printf("\nPress Enter to continue...");
    getchar(); 
    getchar(); 
    system("clear");
}

int get_opt_menu_ia() {
    int ret_opt;
    printf(
        "Choose difficult level\n"
        "1. Easy.\n"
        "2. Medium.\n"
        "3. Hard.\n"
    );
    scanf("your imput: ", "%d", &ret_opt);
    return ret_opt;
}

void rules() {
    printf(
        "==================== GUNGI ====================\n"
        "Reglas basicas:\n"
        "  • El tablero es de 9x9.\n"
        "  • Cada casilla puede contener una torre de hasta 3 piezas.\n"
        "  • Las piezas se apilan: la pieza superior define los movimientos.\n"
        "  • El objetivo es inmovilizar al Rey del oponente.\n"
        "  • El primer jugador en dejar al Rey rival sin movimientos gana.\n"
        "================================================\n\n"
    );
}

int get_option_menu() {
    int ret_opt;
    printf(
        "=======================\n"
        "0. Exit.\n"
        "1. Rules.\n"
        "2. 2 Players\n"
        "3. Play vs IA\n"
        "4. Credits.\n"
        "=======================\n"
       "\n\nPlease, selec an option "
    );
    scanf("%d", &ret_opt);
    return ret_opt;
}

void menu() {
	int opt;
	int level;
	while (opt != 0) {
	    printf(
	        "\n=======================\n"
		    "Welcome Gungi v1.1.1\n"
		    "=======================\n"
		);
		opt = get_option_menu();
		system("clear");
		switch ( opt ) {
    		case 1:
        		rules();
    		    break;
    		case 2:
    		    printf("Play game");
    		    // TODO: llamar a comenzar el juego. 
    		    // Asignacion de turnos
    		    break;
    		case 3:
    		    printf("Play vs IA");
    		    level = get_opt_menu_ia();
    		    // TODO: Implementar combate vs IA --> backGame(..., level, ...);
    		    break;
    		case 4: 
    		     credits();
    		     break;
    		default:
    		    printf("We're sorry, option wrong");
		}
		pause();
	}
}

int main() {
    menu();
	return 0;
}