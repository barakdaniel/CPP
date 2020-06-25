#include "TicTacToe.h"

//-----------------------------------TicTacToe-----------------------------------//
void TicTacToe::getPlayerMove(Move &move)
{
    int row, col;
    std::cout << "Enter two game Coordinate: " << std::endl;
    std::cin >> row >> col;

    if ((row < 0) || (row > 2) || (col < 0) || (col > 2))
        throw "Invalid input";

    if (_board[row][col] == '-')
        move.setMove(row, col);
    else
        throw "Invalid input";
    _board[row][col] = 'X';
}

GameState TicTacToe::getGameState()
{
    char type = 'n';
    bool win = false;
    bool tie = true;

    for (int i = 0; i < 3; i++)
    {
        type = _board[i][0];
        if (type == _board[i][1] && type == _board[i][2] && type != '-')
        {
            win = true;
            break;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        if (win)
            break;

        type = _board[0][j];
        if (type == _board[1][j] && type == _board[2][j] && type != '-')
        {
            win = true;
            break;
        }
    }

    if (!win)
    {
        type = _board[1][1];
        if (_board[0][0] == type && _board[2][2] == type && type != '-')
            win = true;
        if (_board[0][2] == type && _board[2][0] == type && type != '-')
            win = true;
    }

    if (win)
        switch (type)
        {
        case 'O':
            _state = ComputerWins;
            break;
        case 'X':
            _state = PlayerWins;
        }

    else
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (_board[i][j] == '-')
                    tie = false;
    if (tie && !win)
        _state = Tie;

    return _state;
}

//-----------------------------------TicTacToeRand-----------------------------------//

void TicTacToeRand::getComputerMove(Move &move)
{
    int col = 0, row = 0;
    bool flag = false;

    for (; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            if (_board[row][col] == '-')
            {
                flag = true;
                break;
            }
        }

        if (flag)
            break;
    }

    _board[row][col] = 'O';
    move.setMove(row, col);
}

//-----------------------------------TicTacToeEdu-----------------------------------//
//----------------To do- improve simple Edu to move advenct-------------------------//

void TicTacToeEdu::getComputerMove(Move &move)
{
    char x = 'X';
    Move m;

    for (int i = 0; i < _rows; i++) //This for is checking for strike in row
        for (int j = 0; j < _cols - 1; j++)
        {

            if ((_board[i][j] == 'X') && (_board[i][j + 1] == 'X'))
            {
                if (j == 0)
                {
                    if (_board[i][2] == '-')
                    {
                        _board[i][2] = 'O';
                        move.setMove(i, 2);
                        return;
                    }
                }

                else if (_board[i][0] == '-')
                {
                    _board[i][0] = 'O';
                    move.setMove(i, 0);
                    return;
                }
            }
        }

    for (int i = 0; i < _cols; i++) //This for is checking for strike in cols
        for (int j = 0; j < _rows - 1; j++)
        {
            if ((_board[j][i] == 'X') && (_board[j + 1][i] == 'X'))
            {
                if (j == 0)
                {
                    if (_board[2][i] == '-')
                    {
                        _board[2][i] = 'O';
                        move.setMove(2, i);
                        return;
                    }
                }

                else if (_board[0][i] == '-')
                {
                    _board[0][i] = 'O';
                    move.setMove(0, i);
                    return;
                }
            }
        }

    if (_board[1][1] == 'X') //This for is checking for strike in  diagonal
    {
        if (_board[0][0] == 'X')
        {
            if (_board[2][2] == '-')
            {
                move.setMove(2, 2);
                _board[2][2] = 'O';
                return;
            }
        }
        else if (_board[2][2] == 'X')
        {
            if (_board[0][0] == '-')
            {
                move.setMove(0, 0);
                _board[0][0] = 'O';
                return;
            }
        }

        if (_board[0][2] == 'X')
        {
            if (_board[2][0] == '-')
            {
                move.setMove(2, 0);
                _board[2][0] = 'O';
                return;
            }
        }
        else if (_board[2][0] == 'X')
        {
            if (_board[0][2] == '-')
            {
                move.setMove(0, 2);
                _board[0][2] = 'O';
                return;
            }
        }
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (_board[i][j] == '-')
            {
                move.setMove(i, j);
                _board[i][j] = 'O';
                return;
            }
}
