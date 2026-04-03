#include "Player.hpp"
#include "GameConfig.hpp"


Player::Player(Texture2D* tex)
{
    _sprite.Init(tex);
    _transform.scale = GameConfig::PLAYER_SCALE;
    _movement.speed = GameConfig::PLAYER_SPEED;
}

void Player::Update(Vector2 moveDir, float delta)
{
    _movement.Update(_transform, moveDir, delta);
}

void Player::SetPosition(Vector2 position)
{
    _transform.position = position;
}

Vector2 Player::GetPosition() const
{
    return _transform.position;
}

void Player::Draw() const
{
    _sprite.Draw(_transform);
}