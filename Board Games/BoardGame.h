#pragma once
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>

class BoardGame : public Game
{

public:
    BoardGame(int rows, int cols)
    {

        _rows = rows;
        _cols = cols;
        _state = InProgress;

        _board.resize(_rows);

        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                _board[i].push_back('-');
    }

    virtual ~BoardGame()
    {
        _board.erase(_board.begin(), _board.end());
    }

protected:
    int _rows;
    int _cols;
    std::vector<std::vector<char>> _board;
    GameState _state;
};
