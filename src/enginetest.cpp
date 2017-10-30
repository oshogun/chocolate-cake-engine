#include <SFML/Graphics.hpp>
/*
 * This code is based on the book SFML Game Development By Example,
 * and it is the starting point for finding out what is needed in a 
 * SFML game.
 */
class Game {
public:
    Game(): 
    mWindow(sf::VideoMode(640, 480), "Chocolate Cake"), 
    mPlayer(),
    mIsMovingUp{false},
    mIsMovingDown{false},
    mIsMovingLeft{false},
    mIsMovingRight{false}
    {
        mPlayer.setRadius(40.f);
        mPlayer.setPosition(100.f, 100.f);
        mPlayer.setFillColor(sf::Color::Cyan);
    }
    void run() 
    {
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while (mWindow.isOpen()) {
            processEvents();
            timeSinceLastUpdate += clock.restart();
            while (timeSinceLastUpdate > timePerFrame) {
                timeSinceLastUpdate -= timePerFrame;
                update(timePerFrame);
                render();
            }
        }
    }
private:
    void processEvents()
    {
        sf::Event ev;
        while (mWindow.pollEvent(ev)) {
            switch(ev.type) {
                case sf::Event::KeyPressed:
                    handlePlayerInput(ev.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    handlePlayerInput(ev.key.code, false);
                    break;
                case sf::Event::Closed:
                    mWindow.close();
                    break;
            }
        }
    }
    void update(sf::Time deltaTime) 
    {
        sf::Vector2f movement(0.f, 0.f);
        if (mIsMovingUp)
            movement.y -= playerSpeed;
        if (mIsMovingDown)
            movement.y += playerSpeed;
        if (mIsMovingLeft)
            movement.x -= playerSpeed;
        if (mIsMovingRight)
            movement.x += playerSpeed;

        mPlayer.move (movement * deltaTime.asSeconds());
    }
    void render()
    {
        mWindow.clear();
        mWindow.draw(mPlayer);
        mWindow.display();
    }

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
    {
        switch(key) {
            case sf::Keyboard::Up:
                mIsMovingUp = isPressed;
                break;
            case sf::Keyboard::Down:
                mIsMovingDown = isPressed;
                break;
            case sf::Keyboard::Left:
                mIsMovingLeft = isPressed;
                break;
            case sf::Keyboard::Right:
                mIsMovingRight = isPressed;
                break;
        }
    }
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;

    const sf::Time timePerFrame{sf::seconds(1.f / 60.f)};
    float playerSpeed = 100.f;
    bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
};

int main()
{
    Game game;
    game.run();
}