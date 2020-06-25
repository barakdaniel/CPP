#include "Interface.h"

//-------------------------------------------------ConsoleBoard-----------------------------------//
ConsoleBoard::ConsoleBoard(int rows, int cols)
{

    _cols = cols;
    _rows = rows;
    _board.resize(_rows);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _board[i].push_back('-');
}

ConsoleBoard::~ConsoleBoard()
{
    _board.erase(_board.begin(), _board.end());
}

void ConsoleBoard::draw(GameState state)
{
    std::vector<std::string> enumConv{"Player wins", "Computer wins", "Tie", "In Progress"};
    std::cout << "\t";
    for (int i = 0; i < _cols; i++)
    {
        std::cout << i << "\t";
    }
    std::cout<< "\n" << std::endl;
    for (int i = 0; i < _rows; ++i)
    {
        std::cout << i << "\t";
        for (int j = 0; j < _cols; j++)
            std::cout << _board[i][j] << "\t";
        std::cout << std::endl;
    }
    std::cout << "\n" << enumConv[state] << std::endl;
}

//----------------------------------------------------ConsoleBoardTicTacToe-------------------------------------//
void ConsoleBoardTicTacToe::update(const Move &move, int typeOfMove)
{
    char type = '-';
    if (typeOfMove == 0)
        type = 'X';
    else
        type = 'O';

    _board[move.getX()][move.getY()] = type;
}

//----------------------------------------------------ConsoleBoardCatchTheBunny-------------------------------------//
ConsoleBoardCatchTheBunny::ConsoleBoardCatchTheBunny(const Move &player, const Move &bunny) : ConsoleBoard(9, 9)
{
    _player = player;
    _bunny = bunny;
    _board[player.getX()][player.getY()] = 'P';
    _board[bunny.getX()][bunny.getY()] = 'B';
}

void ConsoleBoardCatchTheBunny::update(const Move &move, int typeOfMove)
{

    if (typeOfMove == 0)
    {
        _board[_player.getX()][_player.getY()] = '-';
        _player = move;
        _board[_player.getX()][_player.getY()] = 'P';
    }

    else
    {
        _board[_bunny.getX()][_bunny.getY()] = '-';
        _bunny = move;
        _board[_bunny.getX()][_bunny.getY()] = 'B';
    }
}
