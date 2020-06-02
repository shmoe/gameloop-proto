#ifndef __DEBUG_HPP__
#define __DEBUG_HPP__
#include <SFML/Graphics.hpp>
#include <vector>
#include "Actor.hpp"
#include "Quadtree.hpp"

class Tile : public Actor {
	public:
		Tile(sf::Texture* sprite, float x, float y);
		virtual const sf::Sprite* getCurrentSprite(float steps_ahead);
		virtual void update();
		virtual bool isStatic() const;
};

void getBoundsOutline(sf::FloatRect, sf::RectangleShape&);
#endif//__DEBUG_HPP__