#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<std::vector<int>> inputBoard();
std::vector<int*[3][3]> setupBoard(std::vector<std::vector<int>> &board);
void displayBoard(std::vector<std::vector<int>> board);

int main(int argc,char* argv[])
{
    std::vector<std::vector<int>> board;
    std::vector<int*[3][3]> grid;
    board = inputBoard();
    //grid = setupBoard(board);
    displayBoard(board);
    return 0;
}

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

/*std::vector<int*[3][3]> setupBoard(std::vector<std::vector<int>> &board)
{
    std::vector<int*[3][3]> gridList;
    for (int i = 0; i < 9; i++)
    {
        int* grid[3][3];
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
            {
                grid[row][col] = (&board[i/3 + row][i%3 + col]);
            }
        gridList.push_back(grid);
    }
    return gridList;
}*/

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