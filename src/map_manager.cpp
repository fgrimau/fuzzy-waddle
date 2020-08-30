/**
    name : map_manager.cpp
    purpose : Contains the source code for the MapManager class

    @author : minigrim0
    @version : 1.0
*/

#include <iostream>
#include <SDL2/SDL.h>

#include "../includes/map_manager.hpp"
#include "../includes/map_element.hpp"

//Constructors
MapManager::MapManager()
:m_position(nullptr),
m_chunk(new Chunk)
{}

MapManager::MapManager(int x, int y)
:m_position(nullptr),
m_chunk(new Chunk)
{
    set_position(x, y);
}

MapManager::MapManager(SDL_Rect position)
:m_position(nullptr),
m_chunk(new Chunk)
{
    set_position(position);
}

MapManager::~MapManager(){
    delete m_position;
    delete m_chunk;
}

//Override
MapManager& MapManager::operator=(const MapManager& mm){
    m_position = mm.get_position();

    return *this;
}

//Getters
SDL_Rect* MapManager::get_position() const{
    return m_position;
}

//Setters
void MapManager::set_position(SDL_Rect pos){
    m_position = &pos;
}

void MapManager::set_position(int x, int y){
    m_position->x = x;
    m_position->y = y;
}
