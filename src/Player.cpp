#include "Player.h"
#include <cmath>

Player::Player()
    : m_Health(START_HEALTH),
      m_MaxHealth(START_HEALTH),
      m_Speed(START_SPEED)
{
    m_Texture.loadFromFile(ROOT_DIR "/graphics/player.png");
    m_Sprite.setTexture(m_Texture);
    // Set the origin of the sprite to the center for smooth rotation
    m_Sprite.setOrigin(25, 25);

}

void Player::spawn(sf::IntRect arena, sf::Vector2f resolution, const int tileSize) {
    // Place the player in the middle of the arena
    m_Position.x = arena.width / 2;
    m_Position.y = arena.height / 2;

    // Copy the details of the arena to the player's m_Arena
    m_Arena.left = arena.left;
    m_Arena.width = arena.width;
    m_Arena.top = arena.top;
    m_Arena.height = arena.height;

    // Remember how big the tiles are in this arena
    m_TileSize = tileSize;
    // Store the resolution for future use
    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;
}

void Player::resetPlayerStats() {
    m_Speed = START_SPEED;
    m_Health = START_HEALTH;
    m_MaxHealth = START_HEALTH;
}

sf::Time Player::getLastHitTime() const {
    return m_LastHit;
}

bool Player::hit(const sf::Time& timeHit) {
    if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200) {
        m_LastHit = timeHit;
        m_Health -= 10;
        return true;
    }
    return false;
}

sf::FloatRect Player::getPosition() const {
    return m_Sprite.getGlobalBounds();
}

sf::Vector2f Player::getCenter() const {
    return m_Position;
}

float Player::getRotation() const {
    return m_Sprite.getRotation();
}

sf::Sprite Player::getSprite() const {
    return m_Sprite;
}

int Player::getHealth() const {
    return m_Health;
}

void Player::moveLeft() {
    m_LeftPressed = true;
}

void Player::moveRight() {
    m_RightPressed = true;
}

void Player::moveUp() {
    m_UpPressed = true;
}

void Player::moveDown() {
    m_DownPressed = true;
}

void Player::stopLeft() {
    m_LeftPressed = false;
}

void Player::stopRight() {
    m_RightPressed = false;
}

void Player::stopUp() {
    m_UpPressed = false;
}

void Player::stopDown() {
    m_DownPressed = false;
}

void Player::update(const float elapsedTime, const sf::Vector2i& mousePosition) {
    if (m_UpPressed) {
        m_Position.y -= m_Speed * elapsedTime;
    }
    if (m_DownPressed) {
        m_Position.y += m_Speed * elapsedTime;
    }
    if (m_RightPressed) {
        m_Position.x += m_Speed * elapsedTime;
    }
    if (m_LeftPressed) {
        m_Position.x -= m_Speed * elapsedTime;
    }
    m_Sprite.setPosition(m_Position);
    // Keep the player in the arena
    if (m_Position.x > m_Arena.width - m_TileSize) {
        m_Position.x = m_Arena.width - m_TileSize;
    }
    if (m_Position.x < m_Arena.left + m_TileSize) {
        m_Position.x = m_Arena.left + m_TileSize;
    }
    if (m_Position.y > m_Arena.height - m_TileSize) {
        m_Position.y = m_Arena.height - m_TileSize;
    }
    if (m_Position.y < m_Arena.top + m_TileSize) {
        m_Position.y = m_Arena.top + m_TileSize;
    }
    // Calculate the angle the player is facing
    float angle = (atan2(mousePosition.y - m_Resolution.y / 2, mousePosition.x - m_Resolution.x / 2) * 180) / 3.141;
    m_Sprite.setRotation(angle);
}

void Player::upgradeSpeed() {
    m_Speed += (START_SPEED * 0.2);
}

void Player::upgradeHealth() {
    m_MaxHealth += (START_HEALTH * 0.2);
}

void Player::increaseHealthLevel(int amount) {
    m_Health += amount;
    if (m_Health > m_MaxHealth) {
        m_Health = m_MaxHealth;
    }
}
