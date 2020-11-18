#include "Actor.hpp"

sf::FloatRect Actor::getBounds() const {
	return current_sprite.getGlobalBounds();
}

void Actor::setZ(size_t z_index){
	z = z_index;
}
size_t Actor::getZ() const {
	return z;
}

bool Actor::operator<(const Actor& a){
	return this->z < a.z;
}

const sf::Sprite* Actor::getSprite() const {
	return &current_sprite;
}

const sf::Sprite* Actor::getCurrentSprite(float steps_ahead){
	next_sprite = sf::Sprite(current_sprite);
	next_sprite.move(steps_ahead * velocity.getX(), steps_ahead * velocity.getY());
	return &next_sprite;
}

void Actor::move(Vector dPos){
	current_sprite.move(dPos.getX(), dPos.getY());
}

void Actor::scale(sf::Vector2f factor){
	current_sprite.scale(factor);
}

Vector Actor::getVelocity() const {
	return velocity;
}

Vector Actor::getAcceleration() const {
	return acceleration;
}

float Actor::getRotationalVelocity() const {
	//stub
	return 0.0;
}

float Actor::getRotationalAcceleration() const {
	//stub
	return 0.0;
}

void Actor::setVelocity(Vector velocity){
	this->velocity = velocity;
}

void Actor::setAcceleration(Vector acceleration){
	this->acceleration = acceleration;
}