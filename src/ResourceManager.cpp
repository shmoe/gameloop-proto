#include "ResourceManager.hpp"

#include <functional>

ResourceManager::ResourceManager()=default;
ResourceManager::~ResourceManager()=default;
ResourceManager* ResourceManager::getInstance(){
	static ResourceManager instance;
	return &instance;
}

resource_id hashFunction(std::string str){
	static std::hash<std::string> hash;
	return hash(str);
}

resource_id ResourceManager::loadTexture(std::string path){
	sf::Texture* new_texture = new sf::Texture();
	new_texture->loadFromFile(path);
	
	resource_id id = hashFunction(path);

	textures.emplace(id, new_texture);
	return id;
}
resource_id ResourceManager::loadSoundBuffer(std::string path){
	sf::SoundBuffer* new_sound = new sf::SoundBuffer();
	new_sound->loadFromFile(path);

	resource_id id = hashFunction(path);

	sounds.emplace(id, new_sound);
	return id;
}
resource_id ResourceManager::loadMusic(std::string path){
	sf::Music* new_music = new sf::Music();
	new_music->openFromFile(path);

	resource_id id = hashFunction(path);

	music.emplace(id, new_music);
	return id;
}

void ResourceManager::deleteMusic(resource_id id){
	delete music.at(id);
	music.erase(id);
}
void ResourceManager::deleteTexture(resource_id id){
	delete textures.at(id);
	textures.erase(id);
}
void ResourceManager::deleteSoundBuffer(resource_id id){
	delete sounds.at(id);
	sounds.erase(id);
}

sf::Music* ResourceManager::getMusic(resource_id id){
	return music.at(id);
}
sf::Texture* ResourceManager::getTexture(resource_id id){
	return textures.at(id);
}
sf::SoundBuffer* ResourceManager::getSoundBuffer(resource_id id){
	return sounds.at(id);
}