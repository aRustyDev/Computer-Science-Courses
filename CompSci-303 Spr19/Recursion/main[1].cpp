

#include <string>
#include <iostream>
using namespace std;

enum color{ BACKGROUND, ANBORMAL, TEMPORARY, PATH };
const int ROW_SIZE = 5;
const int COL_SIZE = 5;

bool findMazePath(color grid[ROW_SIZE][COL_SIZE], int r, int c)
{
	if (r < 0 || c < 0 || r >= ROW_SIZE || c >= COL_SIZE)
		return false;      // Cell is out of bounds.
	else if (grid[r][c] != BACKGROUND)
		return false;      // Cell is on barrier or dead end.
	else if (r == ROW_SIZE - 1 && c == COL_SIZE - 1)
	{
		grid[r][c] = PATH;         // Cell is on path
		return true;               // and is maze exit.
	}
	else
	{
		// Recursive case.
		// Attempt to find a path from each neighbor.
		// Tentatively mark cell as on path.
		grid[r][c] = PATH;
		if (findMazePath(grid, r - 1, c)
			|| findMazePath(grid, r + 1, c)
			|| findMazePath(grid, r, c - 1)
			|| findMazePath(grid, r, c + 1))
		{
			return true;
		}
		else
		{
			grid[r][c] = TEMPORARY;  // Dead end.
			return false;
		}
	}

}

bool find_maze_path(color grid[ROW_SIZE][COL_SIZE]){
	return findMazePath(grid, 0, 0);
}

//Towers of Hanoi

void show_moves(int n, char start_peg,
	char dest_peg, char temp_peg)
{
	if (n == 1)
	{
		cout << "Move disk 1 from peg " << start_peg
			<< " to peg " << dest_peg << "\n";
	}
	else
	{
		// Recursive step
		show_moves(n - 1, start_peg, temp_peg, dest_peg);
		cout << "Move disk " << n << " from peg " << start_peg
			<< " to peg " << dest_peg << "\n";
		show_moves(n - 1, temp_peg, dest_peg, start_peg);
	}
}

//you can change the number of queens here
int QUEENS = 4;

int row[4] = {};
int numsolutions = 0;


bool is_solution() {
	for (int i = 0; i < QUEENS-1; i++) {
		for (int j = i + 1; j < QUEENS; j++) {
			if (row[i] == row[j])
				return false;
			if (row[i] - row[j] == (i - j))
				return false;
			if (row[i] - row[j] == (j - i))
				return false;
		}
	}
	return true;
}

void print_board(){
	for (int i = 0; i < QUEENS; i++)
		cout << row[i]<<" ";
}


bool place_queen_improved(int i,int& counter){
	counter++;
	if (i == QUEENS) {
		print_board();
		cout << endl;
		if (is_solution()) {
			cout << "Solution # " << (++numsolutions)
				<< endl;
			print_board();
			cout << endl;
			return true;
		}
		else
			return false;
	}
	
	int start =-1; int end = -1;
	if (i>0){
		start = row[i-1] - 1;
		end = row[i-1] + 1;
	}
	
	int j = 0;
	while (j < QUEENS){
		if (j >= start && j <= end) //can it be attacked by the prev queen?
			j = end + 1;
		if (j >= QUEENS) //goes beyond the boundaries
			break;
		row[i] = j;
		place_queen_improved(i + 1,counter);
		++j;
	}
}



/** Try to place the ith queen on a row */
bool place_queen(int i,int& counter) {
	++counter;
	if (i == QUEENS) {
		if (is_solution()) {
			cout << "Solution # " << (++numsolutions)
				<< endl;
			print_board();
			cout << endl;
			return true;
		}
		else
			return false;
	}
	for (int j = 0; j < QUEENS; j++) {
		row[i] = j;
		place_queen(i + 1,counter);
	}
	return false;
}



int main()
{
	show_moves(3, 'L', 'R', 'M');


	color grid[ROW_SIZE][COL_SIZE] =
	{ { BACKGROUND, ANBORMAL, BACKGROUND, ANBORMAL, ANBORMAL },
	{ BACKGROUND, ANBORMAL, BACKGROUND, ANBORMAL, ANBORMAL },
	{ BACKGROUND, BACKGROUND, BACKGROUND, ANBORMAL, BACKGROUND },
	{ BACKGROUND, ANBORMAL, BACKGROUND, BACKGROUND, BACKGROUND },
	{ BACKGROUND, ANBORMAL, BACKGROUND, ANBORMAL, BACKGROUND } };

	std::cout << std::boolalpha << find_maze_path(grid) << "\n";
	int counter = 0;
	place_queen(0,counter); //92, counter: 19173961
	numsolutions = 0;
	counter = 0;
	place_queen_improved(0, counter); //92, counter: 1124593

	return 0;
}
