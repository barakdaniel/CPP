#pragma once
#include "BoardGame.h"

class TicTacToe : public BoardGame
{
public:
    TicTacToe() : BoardGame(3, 3){};
    virtual ~TicTacToe(){};

public:
    virtual void getPlayerMove(Move &move);
    virtual GameState getGameState();
};

class TicTacToeEdu : public TicTacToe
{
public:
    virtual void getComputerMove(Move &move);
};

class TicTacToeRand : public TicTacToe
{
public:
    virtual void getComputerMove(Move &move);
};
