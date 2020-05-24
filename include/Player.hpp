#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <vector>
#include "Actor.hpp"

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
	EXPRESSO_FALLING,
	MINECART_MOVING,
	MINECART_FALLING
};
class Player : public Actor {
	private:
		PlayerState state;									//the player character's current state
	public:
		void setState(PlayerState state);					//set the player character's current state
		PlayerState getState();								//get the player character's current state

		void update();										//update the player character by one step of the physics engine (do not use)
		void update(std::vector<bool> keys);				//update the player character by one step of the physics engine and the sprite by one
																//frame of animation
};
#endif//__PLAYER_HPP__