#ifndef __DEBUG_HPP__
#define __DEBUG_HPP__
#include <SFML/Graphics.hpp>
#include "Actor.hpp"

class Tile : public Actor {
	public:
		Tile(sf::Texture* sprite, float x, float y);
		virtual const sf::Sprite* getCurrentSprite(float steps_ahead);
		void update();
};
#endif//__DEBUG_HPP__