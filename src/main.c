#include "ficha.c"
void create_bag(piece []); 
void show_table(piece []);

int main() {
	
	piece bag [TOTAL_PIECES]; 
	create_bag(bag); 
	show_table(bag);
	return 0; 
}
