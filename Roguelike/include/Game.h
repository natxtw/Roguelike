#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();
        virtual ~Game();

    void run();

    protected:

    private:
    int ScreenWidth{1280};
    int ScreenHeight{1024};
    sf::RenderWindow window;
};

#endif // GAME_H
