#include "Player.hpp"
#include "GameConfig.hpp"
#include "GameInput.hpp"


Player::Player(Texture2D* tex)
{
    _sprite.Init(tex);
    _sprite.pivot = GameConfig::PLAYER_PIVOT;
    _transform.scale = GameConfig::PLAYER_SCALE;
    _movement.speed = GameConfig::PLAYER_SPEED;
}

void Player::Update(float delta)
{
    _movement.Update(_transform, GI::get().State(), delta, _collisionMap);
}

void Player::SetPosition(Vector2 position)
{
    _transform.position = position;
}

Vector2 Player::GetPosition() const
{
    return _transform.position;
}

void Player::SetCollisionMap(const CollisionMap *collisionMap)
{
    _collisionMap = collisionMap;
}

void Player::Draw() const
{
    _sprite.Draw(_transform);
}