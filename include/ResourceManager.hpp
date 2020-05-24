#ifndef __RESOURCEMANAGER_HPP__
#define __RESOURCEMANAGER_HPP__

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

typedef size_t resource_id;

//the resource manager is a Meyer singleton, which is modern C++ that I don't really understand
//apparently it's thread-safe
class ResourceManager{
	private:
		ResourceManager();
		~ResourceManager();
		ResourceManager(const ResourceManager&)=delete;
		ResourceManager& operator=(const ResourceManager&)=delete;

		std::unordered_map<resource_id, sf::Music*> music;
		std::unordered_map<resource_id, sf::Texture*> textures;
		std::unordered_map<resource_id, sf::SoundBuffer*> sounds;
	public:
		static ResourceManager* getInstance();

		resource_id loadMusic(std::string path);
		resource_id loadTexture(std::string path);
		resource_id loadSoundBuffer(std::string path);
		void deleteMusic(resource_id);
		void deleteTexture(resource_id);
		void deleteSoundBuffer(resource_id);

		sf::Music* getMusic(resource_id);
		sf::Texture* getTexture(resource_id);
		sf::SoundBuffer* getSoundBuffer(resource_id);

		void clear();
};
#endif//__RESOURCEMANAGER_HPP__