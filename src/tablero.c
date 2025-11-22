#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9

int get_cell_width(int rows, int cols, char **matrix) {
    // Value width (character itself) = 1
    // Padding width (1 space on left, 1 on right) = 2
    // Total cell width = 1 + 2 = 3
    return 3; 
}

void print_separator_line(int cols, int cell_width) {
    printf("+");
    for (int j = 0; j < cols; j++) {
        // Print the hyphens for the width of the cell
        for (int k = 0; k < cell_width; k++) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");
}

void print_boxed_matrix(int rows, int cols, char **matrix) {
    // 1. Calculate the necessary cell width (fixed at 3 for characters)
    int cell_width = get_cell_width(rows, cols, matrix);
    int value_width = cell_width - 2; 
    
    // The width reserved for the row number column (e.g., " 1 ", " 9 ")
    // We use a fixed width of 3 characters: 2 for the number, 1 for the space.
    const int ROW_NUM_WIDTH = 3; 

    printf("\nCharacter Matrix (%d x %d) with Chess-board Delimiters and Coordinates:\n", rows, cols);

    // --- 2. Print Column Headers (Above Matrix) ---
    // Print spaces as an offset for the row number column
    for (int k = 0; k < ROW_NUM_WIDTH + 1; k++) {
        printf(" ");
    }
    
    // Print column indices (1 to COLS), centered in the cell width
    for (int j = 0; j < cols; j++) {
        // The format " %d " uses 3 characters (space, digit, space) for single digits
        printf(" %d  ", j + 1);
    }
    printf("\n");
    // ----------------------------------------------


    for (int i = 0; i < rows; i++) {
        // Print row number (i+1), right-aligned in 2 spaces, followed by a space.
        printf("   "); 
        // Print the horizontal border line
        print_separator_line(cols, cell_width);

        // Print row number again (for the next line, offset from the matrix row)
        printf("%*d ", 2, i + 1); 

        // Print the row content
        printf("|"); // Start with the left vertical border
        for (int j = 0; j < cols; j++) {
            
            // Determine the padding character based on the row and column index sum (i + j)
            // Even (i+j) will use ' ' (space), Odd (i+j) will use '#' (hash)

            // Print: [padding_char] [value (right-aligned)] [padding_char] |
            char padding_char = ' ';

            // 1. Print the left padding character
            printf("%c", padding_char); 
 
            // 2. Print the value, using the calculated width for right-alignment.
            printf("%*c", value_width, matrix[i][j]);

            // 3. Print the right padding character
            printf("%c", padding_char);

            // 4. Print the vertical border for the next cell
            printf("|");
        }
        printf("\n");
    }

    // Print the final bottom border
    printf("   "); // Offset for row number column
    print_separator_line(cols, cell_width);

    // --- 3. Print Column Footers (Below Matrix, as requested) ---
    // Print spaces as an offset for the row number column
    
    // Print column indices (1 to COLS), centered in the cell width
    printf("\n");
    // ----------------------------------------------
}

// Main function to demonstrate the boxed character matrix printer
int main() {
    // ROWS and COLS are defined above as macros (9x9).
    
    // Initial data for the 9x9 matrix (filled with sequential characters)
    char initial_data[ROWS][COLS] = {
        { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' },
        { 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R' },
        { 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a' },
        { 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' },
        { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' },
        { 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r' },
        { 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a' },
        { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
        { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' }
    };
    
    // --- Dynamic Memory Allocation for C Compatibility (now using char) ---
    char **matrix = (char **)malloc(ROWS * sizeof(char *));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed for row pointers.\n");
        return 1;
    }
    
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (char *)malloc(COLS * sizeof(char)); 
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for row %d.\n", i);
            for (int k = 0; k < i; k++) { free(matrix[k]); }
            free(matrix);
            return 1;
        }
        // Copy the initial data into the dynamically allocated matrix
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = initial_data[i][j];
        }
    }
    // --- End Dynamic Allocation ---

    print_boxed_matrix(ROWS, COLS, matrix);

    // --- Memory Cleanup ---
    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);
    // --- End Memory Cleanup ---

    return 0;
}
