#include <stdlib.h> 
#include "ficha.c"
#define LIMITS 9

typedef struct Node {
	struct Node * next; 
	char * name; 
} Node;


void create_bag(piece []); 
void show_table(piece []);



void create_turn(Node * turn) { 

	Node * nextTurn = malloc (sizeof(struct Node));	
	turn->name = "White"; 
       	nextTurn->name = "Black"; 
	nextTurn->next = turn; 
	turn->next = nextTurn;

}

int main() {
	
	Node * turn = malloc (sizeof(struct Node));
	create_turn(turn); 		
	for (int i = 0; i < 129; i++) {
		printf("Name: %s\n", turn->name); 
		turn = turn->next; 
	}
	piece bag [TOTAL_PIECES]; 
	create_bag(bag); 
	show_table(bag);


	return 0; 
}
