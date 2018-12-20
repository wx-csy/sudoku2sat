#include <iostream>
#include <vector>
#include <string>

int sudoku[9][9];
int lit[9][9][9];
int id = 0;
std::vector<std::vector<int>> clauses;

bool conflict(int i, int j, int k, int l) {
    if (i == k or j == l) return true;
    if (i / 3 == k / 3 and j / 3 == l / 3) return true;
    return false;
}

int init() {
    // assign literal for each entry
    // lit[i][j][k] means "sudoku[i][j] == k"
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            for (int k = 0; k < 9; k++) 
                lit[i][j][k] = ++id;

    
    // exactly one of lit[i][j][.] should be true
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // 1. at least one of them are true
            std::vector<int> clause;
            for (int k = 0; k < 9; k++) 
                clause.push_back(lit[i][j][k]);
            clauses.push_back(clause);
            // 2. no two of them are both true
            /*
            for (int k = 0; k < 9; k++) 
                for (int l = k + 1; l < 9; l++) 
                    clauses.push_back({-lit[i][j][k], -lit[i][j][l]});
            */
        }
    }
  

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                for (int l = 0; l < 9; l++) {
                    if (i == k and j == l) continue;
                    if (conflict(i, j, k, l)) 
                        for (int a = 0; a < 9; a++) 
                            clauses.push_back({-lit[i][j][a], -lit[k][l][a]});
                }
            }
        }
    }
}

int main() {
    init();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cin >> sudoku[i][j];
            if (sudoku[i][j] > 0)
                clauses.push_back({lit[i][j][sudoku[i][j]-1]});
        }
    }
    printf("p cnf %d %d\n", id, (int) clauses.size());
    for (auto& clause : clauses) {
        for (int x : clause) 
            printf("%d ", x);
        printf("0\n");
    }
    return 0;
}
