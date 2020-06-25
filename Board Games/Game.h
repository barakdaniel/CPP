#pragma once
#include "Move.h"

enum GameState
{
    PlayerWins,
    ComputerWins,
    Tie,
    InProgress
};

class Game
{
public:
    virtual void getComputerMove(Move &move) = 0;
    virtual void getPlayerMove(Move &move) = 0;
    virtual GameState getGameState() = 0;
};