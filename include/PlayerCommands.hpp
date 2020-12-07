#ifndef __PLAYERCOMMANDS_HPP__
#define __PLAYERCOMMANDS_HPP__

#include "Player.hpp"
#include "Command.hpp"

//TODO before PlayerCommands can be created, the Player class must be a functioning state machine


namespace pc {
	/*~~~ COMMAND TEMPLATE ~~~*/
	/*
	class [Action] : public Command {
		public:
			virtual void execute(Player* actor);	//make player start and continue to [Action]
			virtual void end(Player* actor);		//make player stop [Action]
	};
	*/


	/*~~~ FOR DEBUGGING ONLY ~~~*/
	//uses Actor internals, which should never be done in pratice to a Player object
	//utilize the state machine instead in real PlayerCommands

	class DebugMoveUp : public Command {
		public:
			virtual void execute(Player* actor);	//make player start and continue to move up
			virtual void end(Player* actor);		//make player stop moving up
	};

	class DebugMoveDown : public Command {
		public:
			virtual void execute(Player* actor);	//make player start and continue to move down
			virtual void end(Player* actor);		//make player stop moving down
	};

	class DebugMoveRight : public Command {
		public:
			virtual void execute(Player* actor);	//make player start and continue to move right
			virtual void end(Player* actor);		//make player stop moving right
	};

	class DebugMoveLeft : public Command {
		public:
			virtual void execute(Player* actor);	//make player start and continue to move right
			virtual void end(Player* actor);		//make player stop moving left
	};

	extern DebugMoveLeft db_moveLeft;
	extern DebugMoveRight db_moveRight;
	extern DebugMoveUp db_moveUp;
	extern DebugMoveDown db_moveDown;
}
#endif//__PLAYERCOMMANDS_HPP__