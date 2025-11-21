#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <time.h> 
#define TOTAL_PIECES 14
#define MAX_NAME 13


typedef struct {
	char  name[MAX_NAME]; 
	int amount; 
} piece; 



static char *names[TOTAL_PIECES] = {
	"Marshall\0", "General\0", "Liutenant\0", "Major general\0", "Samurai\0",  "Spear\0", "Knight\0", 
	"Spy\0", "Fortress\0", "Pawn\0", "Cannon\0", "Archer\0", "Musketeer\0", "Captain\0"	
};

static int amount [TOTAL_PIECES] = { 
	1, 1, 1, 2, 2, 3, 2, 2, 2, 4, 1, 2, 1, 1
	
};

static piece create_piece(char * name, int amount) {
	piece aux; 
	strcpy(aux.name, name);
	aux.amount = amount;
       	return aux;	
}



 void show_table (piece table[]) { 
	for (int i = 0; i < TOTAL_PIECES; i++ ) {
		printf ("\nName: %s, Amount: %d", table[i].name, table[i].amount);
	} 
}

 piece search (piece table[], char name[MAX_NAME]) { 
	for (int i = 0; i < TOTAL_PIECES; i++) { 
		if (strcmp(name, table[i].name) == 0) { 
			return table[i];
		}
	}
	return create_piece(" ", 0); 
}

void create_bag(piece table[]) { 
	piece aux;
	for (int i = 0; i<TOTAL_PIECES; i++) { 
		aux = create_piece (names[i], amount[i]);  	
		table[i] = aux; 
	}
}

/*
int main () {
	piece table[TOTAL_PIECES];
	piece aux;
	clock_t t; 
	for (int i = 0; i<TOTAL_PIECES; i++) { 
		aux = create_piece (names[i], amount[i]);
	       	printf ("%s", aux.name);	
		table[i] = aux; 
	}
	show_table(table);
	t = clock();
	int cantidad = search(table, "Major general").amount;
	t = clock() - t; 
	printf ("Cantidad de Generales restantes: %d \nCiclos tardados %ld ", cantidad,t); 

	return 0; 
}
*/
