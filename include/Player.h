#pragma once
#include <SFML/Graphics.hpp>

class Player {
private:
    const float START_SPEED { 200 };
    const float START_HEALTH { 100 };
    // Location of the player
    sf::Vector2f m_Position;
    // Player sprite
    sf::Sprite m_Sprite;
    // Player texture
    sf::Texture m_Texture;
    // Screen resolution
    sf::Vector2f m_Resolution;
    // Size of the current arena
    sf::IntRect m_Arena;
    // Tile size of the arena
    int m_TileSize{};
    // Player direction
    bool m_UpPressed{};
    bool m_DownPressed{};
    bool m_LeftPressed{};
    bool m_RightPressed{};
    // Player health
    int m_Health;
    // Max health
    int m_MaxHealth;
    // Time of last hit
    sf::Time m_LastHit;
    // Speed in pixels per second
    float m_Speed;

public:
    Player();
    void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);
    // Reset player stats at the end of each game
    void resetPlayerStats();

    // Handle the player getting hit by a zombie
    bool hit(const sf::Time& timeHit);
    // How long ago was the player last hit
    sf::Time getLastHitTime() const;
    // Where is the player
    sf::FloatRect getPosition() const;
    // Where is the center of the player
    sf::Vector2f getCenter() const;
    // Which angle is the player facing
    float getRotation() const;
    // Send a copy of the sprite to main
    sf::Sprite getSprite() const;
    // Move the player
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    // Stop the player moving in a specific direction
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();
    // To be called every frame
    void update(float elapsedTime, const sf::Vector2i& mousePosition);
    // Give the player a speed boost
    void upgradeSpeed();
    // Give the player some health
    void upgradeHealth();
    // Increase the maximum health of the player
    void increaseHealthLevel(int amount);
    // Current player health
    int getHealth() const;
};