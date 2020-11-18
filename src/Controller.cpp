#include "Controller.hpp"

Controller::Controller(){
}

Command* Controller::getCommand(){
	//TODO events or queries?
	
}

void Controller::setButtonUp(Command* command){
	buttonUp = command;
}
void Controller::setButtonDown(Command* command){
	buttonDown = command;
}
void Controller::setButtonLeft(Command* command){
	buttonLeft = command;
}
void Controller::setButtonRight(Command* command){
	buttonRight = command;
}

void Controller::setButtonA(Command* command){
	buttonA = command;
}
void Controller::setButtonB(Command* command){
	buttonB = command;
}
void Controller::setButtonX(Command* command){
	buttonX = command;
}
void Controller::setButtonY(Command* command){
	buttonY = command;
}

void Controller::setButtonL(Command* command){
	buttonL = command;
}
void Controller::setButtonR(Command* command){
	buttonR = command;
}

void Controller::setButtonSelect(Command* command){
	buttonSelect = command;
}
void Controller::setButtonStart(Command* command){
	buttonStart = command;
}
void Controller::setButtonMeta(Command* command){
	buttonMeta = command;
}