cat $1.txt
./sudoku2sat < $1.txt > $1.sat
./minisat $1.sat $1.out
./sat2sol < $1.out
