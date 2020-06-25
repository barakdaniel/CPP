#include "BoardGameController.h"

void BoardGameController::play()
{
    int gameType;
    int levelDiff;
    Move player;
    Move computer;

    std::cout << "What game would you like to play?\n1.Tic Tac Toe\n2.Catch The Bunny" << std::endl;
    std::cin >> gameType;
    std::cout << "Please choose a difficulty:\n1.vs Random\n2.vs AI" << std::endl;
    std::cin >> levelDiff;

    std::cout << "\nGood luck on, may the Odds be with you!\n"
              << std::endl;

    if ((gameType == 1) && (levelDiff == 1))
    {
        _game = std::unique_ptr<BoardGame>(new TicTacToeRand());
        _view = std::unique_ptr<Interface>(new ConsoleBoardTicTacToe());
    }

    if (gameType == 1 && levelDiff == 2)
    {
        _game = std::unique_ptr<BoardGame>(new TicTacToeEdu());
        _view = std::unique_ptr<Interface>(new ConsoleBoardTicTacToe());
    }

    if (gameType == 2 && levelDiff == 1)
    {
        _game = std::unique_ptr<BoardGame>(new CatchTheBunnyRand(player, computer));
        _view = std::unique_ptr<Interface>(new ConsoleBoardCatchTheBunny(player, computer));
    }

    if (gameType == 2 && levelDiff == 2)
    {
        _game = std::unique_ptr<BoardGame>(new CatchTheBunnyEdu(player, computer));
        _view = std::unique_ptr<Interface>(new ConsoleBoardCatchTheBunny(player, computer));
    }

    _view->draw(_game->getGameState());

    while (_game->getGameState() == InProgress)
    {
        try
        {
            _game->getPlayerMove(player);
            _view->update(player, 0);
            std::cout << "\nUpdated Board:\n" << std::endl;
            _game->getGameState();

            if (_game->getGameState() != InProgress)
            {
                _view->draw(_game->getGameState());
                break;
            }
        }
        catch (const char *er)
        {
            std::cout << er << std::endl;
            continue;
        }

        _game->getComputerMove(computer);
        _view->update(computer, 1);
        _view->draw(_game->getGameState());
    }
}
