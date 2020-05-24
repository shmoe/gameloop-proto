#include "debug.hpp"
Tile::Tile(sf::Texture* sprite, float x, float y){
	spriteSheet = sprite;
	current_sprite = sf::Sprite(*spriteSheet);
	current_sprite.move(sf::Vector2f(x, y));
	z = 0;
}

sf::Sprite* Tile::getCurrentSprite(float steps_ahead){
	return getSprite();
}

void Tile::update(){

}