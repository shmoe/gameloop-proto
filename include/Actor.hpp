#ifndef __ACTOR_HPP__
#define __ACTOR_HPP__

#include <SFML/Graphics.hpp>
#include "Vector.hpp"

/**
 * defines an Actor in the scene
 * Abstract Base Class
 */
class Actor {
	protected:
		size_t z;													//Actor's position along the z-axis
		Vector velocity;											//Actor's velocity
		Vector acceleration;										//Actor's acceleration
		sf::Transform worldTransform;								//Actor's current place in the world, relative to the scene origin
		sf::Texture* spriteSheet;									//A pointer to the sprite sheet, which lives in the ResourceManager
		sf::Sprite current_sprite;									//holds the current frame of animation
		sf::Sprite next_sprite;										//holds the next frame of the animation, to avoid memory leaks
	public:
		void setZ(size_t);											//set the Actor's position along the z-axis
		size_t getZ();												//get the Actor's position along the z-axis
		bool operator<(const Actor& a);								//returns whether this actor's z index is less than a.z for Scene::actors

		virtual sf::Sprite* getCurrentSprite(float steps_ahead);	//get the current sprite in the animation, interpolated *floor(steps_ahead)*,
																		//physics engine steps in the future
		virtual sf::Sprite* getSprite();							//get the current sprite in the animation
	
		virtual void update() = 0;									//update the actor by one step of the physics engine and the sprite by one
																		//frame of animation
										

		//expose internals for collisions and other external interactions
		void move(Vector);											//translate the Actor, relative to it's current position in the world
		void scale(sf::Vector2f);									//scale the Actor
		Vector getVelocity();										//return the current velocity of the Actor as a polar vector
		Vector getAcceleration();									//return the current velocity of the Actor as a polar vector
		float getRotationalVelocity();								//probably not relevant
		float getRotationalAcceleration();							//probably not relevant
};
#endif//__ACTOR_HPP__