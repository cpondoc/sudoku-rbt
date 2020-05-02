#include <iostream>
using namespace std;

/* Class for the Board */
class Board {

    // Variable for board
    int board[9][9];

    // Public functions 
    public:

        // Constructor 
        Board() {

            cout << "This program allows the user to input a sudoku board and solves it." << endl;
            cout << "Begin enter in each row, with each number separated by a space. Represent blanks as zeroes.\n" << endl;

            for (int i = 0; i < 9; i++)
            {
                cout << "Row " << i + 1 << " : ";
                int n;
                for (int j = 0; j < 9; j++)
                {
                    cin >> n;
                    board[i][j] = n;
                }
            }

            cout << endl;

            cout << "Here is the Sudoku Grid: \n" << endl;

            printValues();
        }

        // Printing the grid
        void printValues() {

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }

            cout << endl;
        }

        // Checking possible moves
        bool possible(int y, int x, int n) {

            // Checking y values
            for (int i = 0; i < 9; i++) {
                if (board[y][i] == n) {
                    return false;
                }
            }

            for (int i = 0; i < 9; i++) {
                if (board[i][x] == n) {
                    return false;
                }
            }

            int xNot = int(x / 3) * 3;
            int yNot = int(y / 3) * 3;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[yNot + i][xNot + j] == n) {
                        return false;
                    }
                }
            }

            return true;
        }

        // Solving board with recursive backtracking
        void solveBoard() {
            for (int i = 0; i < 9; i++) 
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] == 0) 
                    {
                        for (int n = 1; n < 10; n++) 
                        {
                            if (possible(i, j, n)) 
                            {
                                board[i][j] = n;
                                solveBoard();
                                board[i][j] = 0;
                            }
                        }
                        return;
                    }
                }
            }

            cout << "Here is a solution to the board: \n" << endl;
            printValues();
        }
};

/* Creates and solves board */
int main() {
    
    //Create board object
    Board bobo = Board();

    // Solving the board
    bobo.solveBoard();

    return 0;
}
