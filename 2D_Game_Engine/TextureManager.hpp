//
//  TextureManager.hpp
//  2D_Game_Engine
//
//  Created by Dan Hembery on 09/02/2024.
//
#pragma once
#include "Game.hpp"

class TextureManager {
    
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
    
};
