#pragma once

class Move
{
public:
    Move() : _x(-1), _y(-1){};
    void setMove(int x, int y)
    {
        _x = x;
        _y = y;
    }
    int getX() const{return _x;}
    int getY() const{return _y;}

    Move& operator = (const Move& move)
    {
        _x = move._x;
        _y = move._y;

        return *this;
    }

private:
    int _x;
    int _y;
};
