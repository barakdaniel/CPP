#pragma once
#include "BoardGame.h"
#include <cstdlib>
#include <ctime>

class CatchTheBunny : public BoardGame
{
public:
    CatchTheBunny(Move &player, Move &bunny);
    virtual ~CatchTheBunny(){};

public:
    virtual void getPlayerMove(Move &move);
    virtual GameState getGameState();
    int manhattanCompute(const Move &a, const Move &b);

protected:
    Move _player;
    Move _bunny;
    int _PlayerCount;
};

class CatchTheBunnyEdu : public CatchTheBunny
{
public:
    CatchTheBunnyEdu(Move &player, Move &bunny) : CatchTheBunny(player, bunny){};

public:
    virtual void getComputerMove(Move &move);
};

class CatchTheBunnyRand : public CatchTheBunny
{
public:
    CatchTheBunnyRand(Move &player, Move &bunny) : CatchTheBunny(player, bunny){};

public:
    virtual void getComputerMove(Move &move);
};
