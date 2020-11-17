#include "Camera.hpp"

Camera::Camera(sf::RenderWindow* window){
	this->window = window;
	view = sf::View(window->getDefaultView());
	locked_actor = nullptr;
}

void Camera::lock(Actor* actor){
	locked_actor = actor;
}

void Camera::render(){
	window->setView(view);
}

void Camera::render(float steps_ahead){
	if(locked_actor){
		sf::View ahead_view(view);

		Vector actor_speed = locked_actor->getVelocity();

		ahead_view.move(steps_ahead * actor_speed.getX(), steps_ahead * actor_speed.getY());

		window->setView(ahead_view);
	}
}

void Camera::update(){
	if(locked_actor){
		//TODO smooth camera movement

		//temporary
		Vector actor_speed = locked_actor->getVelocity();
		view.move(actor_speed.getX(), actor_speed.getY());
	}
}