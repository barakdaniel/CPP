#pragma once
#include <memory>
#include "Interface.h"
#include "CatchTheBunny.h"
#include "TicTacToe.h"

class BoardGameController
{
public:
    void play();

private:
    std::unique_ptr<Interface> _view;
    std::unique_ptr<BoardGame> _game;
};