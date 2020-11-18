#ifndef __PLAYERCOMMANDS_HPP__
#define __PLAYERCOMMANDS_HPP__

#include "Player.hpp"
#include "Command.hpp"

namespace pc {
	/*~~~ COMMAND TEMPLATE ~~~*/
	/*
	class [Action] : public Command {
		virtual void execute(Player* actor);	//make player start and continue to [Action]
		virtual void end(Player* actor);		//make player stop [Action]
	};
	*/

	class MoveUp : public Command {
		virtual void execute(Player* actor);	//make player start and continue to move up
		virtual void end(Player* actor);		//make player stop moving up
	} moveUp;

	class MoveDown : public Command {
		virtual void execute(Player* actor);	//make player start and continue to move down
		virtual void end(Player* actor);		//make player stop moving down
	} moveDown;


	class MoveRight : public Command {
		virtual void execute(Player* actor);	//make player start and continue to move right
		virtual void end(Player* actor);		//make player stop moving right
	} moveRight;

	class MoveLeft : public Command {
		virtual void execute(Player* actor);	//make player start and continue to move right
		virtual void end(Player* actor);		//make player stop moving left
	} moveLeft;
}
#endif//__PLAYERCOMMANDS_HPP__