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
	MINECART_MOVING,
	MINECART_FALLING,
	RAMBI_ATTACKING,
	ENGUARDE_SWIMMING,
	ENGUARDE_ATTACKING,
	EXPRESSO_FALLING
};

/**
 * Class for the player character
 */
class Player : public Actor {
	private:
		PlayerState state;									//the player character's current state
	public:
		void setState(PlayerState state);					//set the player character's current state
		PlayerState getState() const;								//get the player character's current state

		virtual void update() override;						//update the player character by one step of the physics engine (do not use)
		void update(std::vector<bool> keys);				//update the player character by one step of the physics engine and the sprite by one
																//frame of animation

		virtual bool isStatic() const override;				//return whether the player will ever move or change/rotate its bounds (it will)
};
#endif//__PLAYER_HPP__