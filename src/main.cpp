#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
    enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };
    auto state { State::GAME_OVER };

    const sf::Vector2f resolution(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Zombie Arena", sf::Style::Fullscreen);

    sf::View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

    sf::Clock clock{};
    sf::Time gameTimeTotal{};

    sf::Vector2f mouseWorldPosition{};
    sf::Vector2i mouseScreenPosition{};

    Player player{};
    sf::IntRect arena{};

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Return && state == State::PLAYING) {
                    state == State::PAUSED;
                } else if (event.key.code == sf::Keyboard::Return && state == State::PAUSED) {
                    state == State::PLAYING;
                    clock.restart();
                } else if (event.key.code == sf::Keyboard::Return && state == State::GAME_OVER) {
                    state == State::LEVELING_UP;
                }
                if (state == State::PLAYING) {

                }
            }
        } // end event polling

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if (state == State::PLAYING) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player.moveUp();
            } else {
                player.stopUp();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player.moveDown();
            } else {
                player.stopDown();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.moveLeft();
            } else {
                player.stopLeft();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player.moveRight();
            } else {
                player.stopRight();
            }
        } // end WASD while playing

        // Handle leveling up state
        if (state == State::LEVELING_UP) {
            if (event.key.code == sf::Keyboard::Num1) {
                state = State::PLAYING;
            }
            if (event.key.code == sf::Keyboard::Num2) {
                state = State::PLAYING;
            }
            if (event.key.code == sf::Keyboard::Num3) {
                state = State::PLAYING;
            }
            if (event.key.code == sf::Keyboard::Num4) {
                state = State::PLAYING;
            }
            if (event.key.code == sf::Keyboard::Num5) {
                state = State::PLAYING;
            }
            if (event.key.code == sf::Keyboard::Num6) {
                state = State::PLAYING;
            }
            if (state == State::PLAYING) {
                arena.width = 500;
                arena.height = 500;
                arena.left = 0;
                arena.top = 0;

                int tileSize{50};
                player.spawn(arena, resolution, tileSize);
                clock.restart();
            }
        } // end leveling up
    }

    return 0;
}