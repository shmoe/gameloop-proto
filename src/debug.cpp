#include "debug.hpp"
Tile::Tile(sf::Texture* sprite, float x, float y){
	spriteSheet = sprite;
	current_sprite = sf::Sprite(*spriteSheet);
	current_sprite.move(sf::Vector2f(x, y));
	z = 0;
}

const sf::Sprite* Tile::getCurrentSprite(float steps_ahead) {
	return getSprite();
}

void Tile::update(){

}

bool Tile::isStatic() const {
	return true;
}

void getBoundsOutline(sf::FloatRect bounds, sf::RectangleShape& bb_outline){
	bb_outline.setOutlineColor(sf::Color::Red);
	bb_outline.setOutlineThickness(1.f);
	bb_outline.setFillColor(sf::Color::Transparent);

	bb_outline.setPosition(sf::Vector2f(bounds.left, bounds.top));
	bb_outline.setSize(sf::Vector2f(bounds.width, bounds.height));
}