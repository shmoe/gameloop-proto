#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <vector>
#include <SFML/Graphics.hpp>

#include "Vector.hpp"
enum PlayerState{
	STANDING,
	RUNNING,
	FALLING,
	ROLLING,			//or doing a cartwheel
	SWIMMING,
	ATTACKING,
	HOLDING,			//a barrel
	CLIMBING,
	RAMBI_ATTACKING,
	ENGUARDE_SWIMMING,
	ENGUARDE_ATTACKING,
	EXPRESSO_FALLING
};
class Player {
	private:
		sf::Transform worldTransform;						//Player character's current place in the world, relative to the scene origin
		sf::Texture* spriteSheet;							//A pointer to the sprite sheet, which lives in the ResourceManager
		sf::Sprite current_sprite;							//holds the current frame of animation
	public:
		void setState(PlayerState state);					//set the player character's current state
		PlayerState getState();								//get the player character's current state

		sf::Transform getTransform();						//get the transform to be done to the sprite, relative to the scene origin
		sf::Transform getTransform(float steps_ahead);		//get the transform to be done to the sprite, relative to the scene origin,
																//interpolated *steps_ahead* physics engine steps in the future
		sf::Drawable* getCurrentSprite(float steps_ahead);	//get the current sprite in the animation, interpolated *floor(steps_ahead)*,
																//physics engine steps in the future

		void update(std::vector<bool> keys);				//update the player character by one step of the physics engine

		//expose internels for collisions and other external interactions
		void transform(sf::Transform transform);			//transform the player character, relative to it's current position in the scene
		Vector getVelocity();								//return the current velocity of the player character as a polar vector
		Vector getAcceleration();							//return the current velocity of the player character as a polar vector
		float getRotationalVelocity();						//probably not relevant
		float getRotationalAcceleration();					//probably not relevant
};
#endif//__PLAYER_HPP__