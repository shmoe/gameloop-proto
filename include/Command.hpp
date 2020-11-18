#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "Player.hpp"

/**
 * Abstract Base Class
 * Encapsulates an Actor method call as an object.
 * Used in the Controller class to abstract actions
 * away from key/button presses.
 */

class Command {
	public:
		virtual ~Command() {}
		
		virtual void execute(Player* actor) = 0;		//execute the action of the extended class (e.g. MoveCommand)
														//on the Actor.

		virtual void end(Player* actor) = 0;			//end a sustained action of the extended class
														//(e.g. releasing the jump button on JumpCommand)
														//on the Actor.
};

#endif//__COMMAND_HPP__