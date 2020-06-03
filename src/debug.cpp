#include "debug.hpp"
void getBoundsOutline(sf::FloatRect bounds, sf::RectangleShape& bb_outline){
	bb_outline.setOutlineColor(sf::Color::Red);
	bb_outline.setOutlineThickness(1.f);
	bb_outline.setFillColor(sf::Color::Transparent);

	bb_outline.setPosition(sf::Vector2f(bounds.left, bounds.top));
	bb_outline.setSize(sf::Vector2f(bounds.width, bounds.height));
}