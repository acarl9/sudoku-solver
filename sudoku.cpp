#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

/*
 * function headers
 */
std::vector<std::vector<int>> inputBoard();
std::vector<std::vector<std::vector<int*>>> setupBoard(std::vector<std::vector<int>> &board);
void displayBoard(std::vector<std::vector<int>> board);

int main(int argc,char* argv[])
{
    std::vector<std::vector<int>> board;
    std::vector<std::vector<std::vector<int*>>> grid;
    board = inputBoard();
    grid = setupBoard(board);
    displayBoard(board);
    return 0;
}

/*
 * inputs the board from game.txt file
 * turns all #'s to 0's
 * has a problem with empty lines
 */
std::vector<std::vector<int>> inputBoard()
{
    std::ifstream file;
    std::string line;
    std::vector<std::vector<int>> board;
    file.open("game.txt");

    while(!file.eof())
    {
        std::vector<int> row;
        getline(file,line);
        if (line[0] == line[1] and line[0] == '/')
            continue;
        for(char c: line)
        {
            if (!isdigit(c) && c != '#')
                continue;
            if (c == '#')
                c = '0';
            row.push_back(c - '0');
        }
        board.push_back(row);
    }
    file.close();
    return board;
}

/*
 * turns 9x9 vector grid into 9 3x3 grids with pointers to the original numbers
 */
std::vector<std::vector<std::vector<int*>>> setupBoard(std::vector<std::vector<int>> &board)
{
    std::vector<std::vector<std::vector<int*>>> gridList;
    for (int i = 0; i < 9; i++)
    {
        std::vector<std::vector<int*>> grid;
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
            {
                std::vector<int*> line;
                line.push_back((&board[i/3 + row][i%3 + col]));
                grid.push_back(line);
            }
        gridList.push_back(grid);
    }
    return gridList;
}

/*
 * displays the board through cout
 * changes all 0's to # for clarity
 */
void displayBoard(std::vector<std::vector<int>> board)
{
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
        {
            char c = board[row][col];
            if (c == 0)
                c = '#';
            if (col != 0 && col % 3 == 0)
                std::cout << "| ";
            std::cout << c << " ";
            if (col == 8)
            {
                if (!((row+1) % 3))
                    std::cout << std::endl;
                std::cout << std::endl;
            }
        }
}