#include "Tile.hpp"

Tile::Tile(sf::Texture* sprite, float x, float y){
	spriteSheet = sprite;
	current_sprite = sf::Sprite(*spriteSheet);
	current_sprite.move(sf::Vector2f(x, y));
	z = 0;
}

Tile::Tile(sf::Texture* sprite, float x, float y, float scale_factor) : Tile(sprite, x, y) {
	scale(sf::Vector2f(scale_factor, scale_factor));
}

Tile::Tile(sf::Texture* sprite, sf::Vector2f position) : Tile(sprite, position.x, position.y) {
}

Tile::Tile(sf::Texture* sprite, sf::Vector2f position, float scale_factor) : Tile(sprite, position.x, position.y, scale_factor) {
}

Tile::Tile(sf::Texture* sprite, sf::Vector2f position, sf::Vector2f scale_factors) : Tile(sprite, position) {
	scale(scale_factors);
}

const sf::Sprite* Tile::getCurrentSprite(float steps_ahead) {
	return getSprite();
}

void Tile::update(){

}

bool Tile::isStatic() const {
	return true;
}
