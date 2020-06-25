#pragma once
#include <vector>
#include "Move.h"
#include <iostream>
#include "Game.h"
#include <string>

class Interface
{
public:
    virtual void draw(GameState state) = 0;
     virtual void update(const Move &move, int typeOfMove) = 0;
};

class ConsoleBoard : public Interface
{
public:
    ConsoleBoard(int rows, int cols);
    ~ConsoleBoard();

    virtual void draw(GameState state);    
   


protected:
    std::vector<std::vector<char>> _board;
    int _rows;
    int _cols;
};

class ConsoleBoardTicTacToe : public ConsoleBoard
{
public:
    ConsoleBoardTicTacToe() : ConsoleBoard(3, 3){};
    ~ConsoleBoardTicTacToe(){};

public:
    virtual void update(const Move &move, int typeOfMove);
};

class ConsoleBoardCatchTheBunny : public ConsoleBoard
{
public:
    ConsoleBoardCatchTheBunny(const Move &player, const Move &bunny);
    ~ConsoleBoardCatchTheBunny(){};

public:
    virtual void update(const Move &move, int typeOfMove);

private:
    Move _player;
    Move _bunny;
};
