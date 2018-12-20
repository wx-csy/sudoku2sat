.PHONY : ALL, clean

ALL : sudoku2sat sat2sol

sudoku2sat : sudoku2sat.cpp
	g++ sudoku2sat.cpp -o sudoku2sat

sat2sol: sat2sol.cpp
	g++ sat2sol.cpp -o sat2sol

clean : 
	rm -f sudoku2sat sat2sol
