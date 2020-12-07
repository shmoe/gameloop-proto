#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <map>
#include <string>
#include "Command.hpp"


/**
 * Bind different Commands to the inputs of each "controller."
 */
class Controller {
	public:
		Controller();

		Command* getCommand();											//TODO determine whether to use events or direct queries

		void setButtonUp(Command* command);
		void setButtonDown(Command* command);
		void setButtonLeft(Command* command);
		void setButtonRight(Command* command);

		void setButtonA(Command* command);
		void setButtonB(Command* command);
		void setButtonX(Command* command);
		void setButtonY(Command* command);

		void setButtonL(Command* command);
		void setButtonR(Command* command);

		void setButtonSelect(Command* command);
		void setButtonStart(Command* command);
		void setButtonMeta(Command* command);
	private:
		//directional pad
		Command* buttonUp = nullptr;
		Command* buttonDown = nullptr;
		Command* buttonLeft = nullptr;
		Command* buttonRight = nullptr;

		//primary buttons
		Command* buttonA = nullptr;
		Command* buttonB = nullptr;
		Command* buttonX = nullptr;
		Command* buttonY = nullptr;

		//shoulder buttons
		Command* buttonL = nullptr;
		Command* buttonR = nullptr;
		
		//system buttons
		Command* buttonSelect = nullptr;
		Command* buttonStart = nullptr;
		Command* buttonMeta = nullptr;			//i.e. PS button or Xbox button, when available.
};

#endif//__CONTROLLER_HPP__