#include "Camera.hpp"

Camera::Camera(sf::RenderWindow* window){
	this->window = window;
	view = sf::View(window->getDefaultView());
	locked_actor = nullptr;
}

void Camera::lock(Actor* actor){
	locked_actor = actor;
}

sf::FloatRect Camera::getBounds() const {
	sf::Vector2f center = view.getCenter(), size = view.getSize();
	
	return 	sf::FloatRect(
		center.x - size.x / 2,
		center.y - size.y / 2,
		size.x,
		size.y
	);
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

void Camera::resizeViewport(float aspect_ratio){
	//shrink viewport horizontally  to fit ratio (vertical black bars)

	float oldWidth = window->getSize().x;
	float height = window->getSize().y;

	if(oldWidth / height != aspect_ratio){
		// width / height = ratio
		// width = ratio * height
		// newWidth = ratio * height
		float newWidth = height * aspect_ratio;

		// width_offset = (old_width - newWidth) / 2
		// width_offset_scale_factor = width / width_offset
		// 							 = width / ((old_width - newWidth) / 2)
		//							 = 2 * width / (old_width - newWidth)				
		float width_offset_scale_factor = (oldWidth - newWidth) / (2 * newWidth);

		// width_scale_factor = width / old_width
		float width_scale_factor = newWidth / oldWidth;

		view.setViewport(sf::FloatRect(width_offset_scale_factor, 0.0f, width_scale_factor, 1.0f));
		window->setView(view);
	}
}