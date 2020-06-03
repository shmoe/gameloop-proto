#ifndef __TILE_HPP__
#define __TILE_HPP__
#include "Actor.hpp"

/**
 * a static type of actor, whose bounds and position will never change
 */
class Tile : public Actor {
	public:
		//constructors
		Tile(sf::Texture* sprite, float x, float y);
		Tile(sf::Texture* sprite, sf::Vector2f position);
		Tile(sf::Texture* sprite, float x, float y, float scale_factor);				//scale evenly
		Tile(sf::Texture* sprite, sf::Vector2f position, float scale_factor);			//scale evenly
		Tile(sf::Texture* sprite, sf::Vector2f position, sf::Vector2f scale_factor);	//scale along x and y

		virtual const sf::Sprite* getCurrentSprite(float steps_ahead);			//get the current sprite in the animation, interpolated *floor(steps_ahead)*,
																					//physics engine steps in the future

		virtual void update();													//update the actor by one step of the physics engine and the sprite by one
																					//frame of animation. will not change position or bounds

		virtual bool isStatic() const;											//returns true
};

#endif//__TILE_HPP__