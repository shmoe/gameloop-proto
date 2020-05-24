#include "Actor.hpp"

void Actor::setZ(size_t z_index){
	z = z_index;
}
size_t Actor::getZ(){
	return z;
}

bool Actor::operator<(const Actor& a){
	return this->z < a.z;
}

sf::Sprite* Actor::getSprite(){
	return &current_sprite;
}

sf::Sprite* Actor::getCurrentSprite(float steps_ahead){
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

Vector Actor::getVelocity(){
	return velocity;
}

Vector Actor::getAcceleration(){
	return acceleration;
}

float Actor::getRotationalVelocity(){
	//stub
	return 0.0;
}

float Actor::getRotationalAcceleration(){
	//stub
	return 0.0;
}