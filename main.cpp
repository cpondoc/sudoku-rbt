#include <iostream>
using namespace std;

/* Class for the Board */
class Board {

    // Variable for board
    int board[9][9];

    // Public functions 
    public:

        // Constructor 
        Board(int inputBoard[9][9]) {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    board[i][j] = inputBoard[i][j];
                }
            }
            printValues();
        }

        // Printing the grid
        void printValues() {
            cout << "Here is the Sudoku Grid: \n" << endl;

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
            printValues();
        }
};

/* Creates board, solves, prints out */
int main() {
    
    // 2D Array for board
    int board[9][9] = 
    {{5, 3, 0, 0, 7, 0, 0, 0, 0}, 
    {6, 0, 0, 1, 9, 5, 0, 0, 0}, 
    {0, 9, 8, 0, 0, 0, 0, 6, 0}, 
    {8, 0, 0, 0, 6, 0, 0, 0, 3}, 
    {4, 0, 0, 8, 0, 3, 0, 0, 1}, 
    {7, 0, 0, 0, 2, 0, 0, 0, 6}, 
    {0, 6, 0, 0, 0, 0, 2, 8, 0}, 
    {0, 0, 0, 4, 1, 9, 0, 0, 5}, 
    {0, 0, 0, 0, 8, 0, 0, 0, 0}};

    //Create board object
    Board bobo = Board(board);

    bobo.solveBoard();
    bobo.solveBoard();
    return 0;
}