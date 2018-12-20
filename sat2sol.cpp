#include <iostream>
#include <vector>
#include <string>

int sudoku[9][9];

int main() {
    std::string result; std::cin >> result;
    if (result == "UNSAT") {
        printf("No solution!\n");
        return 0;
    }
    printf("Solution found!\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                int v; std::cin >> v;
                if (v > 0) sudoku[i][j] = k + 1;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) 
            printf("%d ", sudoku[i][j]);
        puts("");
    }
    return 0;
}
