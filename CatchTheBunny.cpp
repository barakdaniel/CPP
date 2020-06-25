#include "CatchTheBunny.h"

//---------------------------CatchTheBunny-------------------------------------//
CatchTheBunny::CatchTheBunny(Move &player, Move &bunny) : BoardGame(9, 9)
{
    srand(time(NULL));
    int x = rand() % 9;
    int y = rand() % 9;

    int a = rand() % 9;
    int b = rand() % 9;

    if (x == a)
    {
        int x = (4 + x) % 9;
    }

    _board[x][y] = 'B';
    _board[a][b] = 'P';

    _player.setMove(a, b);
    _bunny.setMove(x, y);

    player = _player;
    bunny = _bunny;

    _PlayerCount = manhattanCompute(_player, _bunny) * 4;
}

int CatchTheBunny::manhattanCompute(const Move &a, const Move &b)
{
    int row = abs(a.getX() - b.getX());
    int col = abs(a.getY() - b.getY());
    return (row + col);
}

void CatchTheBunny::getPlayerMove(Move &move)
{
    int row, col;
    std::cout << "Please choose the Coordinate you want to move to-" << std::endl;
    std::cin >> row >> col;

    if ((row < 0) || (row > 8) || (col < 0) || (col > 8))
        throw "Invalid move";

    Move tmpMov;
    tmpMov.setMove(row, col);
    if (manhattanCompute(tmpMov, _player) != 1)
        throw "Invalid move";
    else
        move = tmpMov;

    _board[_player.getX()][_player.getY()] = '-';
    _player = move;
    _board[_player.getX()][_player.getY()] = 'P';
    _PlayerCount--;
}

GameState CatchTheBunny::getGameState()
{
    if (manhattanCompute(_player, _bunny) == 0)
        _state = PlayerWins;

    else if (_PlayerCount == 0)
        _state = ComputerWins;

    return _state;
}

//---------------------------------CatchTheBunnyRand-------------------------------------//
void CatchTheBunnyRand::getComputerMove(Move &move)
{
    srand(time(NULL));
    int random = rand() % 2; //Choosing randomly between moving on row or col

    Move tmpMov;

    tmpMov = _bunny;

    if (random == 0)
    {
        if (_bunny.getX() - 1 >= 0)
            _bunny.setMove(_bunny.getX() - 1, _bunny.getY());
        else
            _bunny.setMove(_bunny.getX() + 1, _bunny.getY());
    }

    if (random == 1)
    {
        if (_bunny.getY() - 1 >= 0)
            _bunny.setMove(_bunny.getX(), _bunny.getY() - 1);
        else
            _bunny.setMove(_bunny.getX(), _bunny.getY() + 1);
    }

    _board[tmpMov.getX()][tmpMov.getY()] = '-';
    _board[_bunny.getX()][_bunny.getY()] = 'B';
    move = _bunny;
}

//---------------------------------CatchTheBunnyEdu--------------------------------------//
void CatchTheBunnyEdu::getComputerMove(Move &move)
{
    int currDist = manhattanCompute(_player, _bunny);
    std::vector<int> maxDist;

    Move tmpMov = _bunny;

    tmpMov.setMove(tmpMov.getX() + 1, tmpMov.getY());
    if (tmpMov.getX() <= 8)
        maxDist.push_back(manhattanCompute(_player, tmpMov) - currDist);
    else
        maxDist.push_back(0);

    tmpMov.setMove(tmpMov.getX() - 2, tmpMov.getY());
    if (tmpMov.getX() >= 0)
        maxDist.push_back(manhattanCompute(_player, tmpMov) - currDist);
    else
        maxDist.push_back(0);

    tmpMov.setMove(tmpMov.getX() + 1, tmpMov.getY() + 1);
    if (tmpMov.getY() <= 8)
        maxDist.push_back(manhattanCompute(_player, tmpMov) - currDist);
    else
        maxDist.push_back(0);

    tmpMov.setMove(tmpMov.getX(), tmpMov.getY() - 2);
    if (tmpMov.getY() >= 0)
        maxDist.push_back(manhattanCompute(_player, tmpMov) - currDist);
    else
        maxDist.push_back(0);

    int i, j;

    for (i = 0; i < 4; ++i)
    {
        if (maxDist[i] == -1)
            j = i;
        if (maxDist[i] == 1)
            break;
    }

    if (i == 4)
        i = j;

    tmpMov = _bunny;

    if (i == 0)
        tmpMov.setMove(tmpMov.getX() + 1, tmpMov.getY());
    else if (i == 1)
        tmpMov.setMove(tmpMov.getX() - 1, tmpMov.getY());
    else if (i == 2)
        tmpMov.setMove(tmpMov.getX(), tmpMov.getY() + 1);
    else if (i == 3)
        tmpMov.setMove(tmpMov.getX(), tmpMov.getY() - 1);

    _board[_bunny.getX()][_bunny.getY()] = '-';
    _bunny = tmpMov;
    _board[_bunny.getX()][_bunny.getY()] = 'B';

    move = _bunny;
}
