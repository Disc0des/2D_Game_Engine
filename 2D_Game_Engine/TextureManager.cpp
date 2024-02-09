//
//  TextureManager.cpp
//  2D_Game_Engine
//
//  Created by Dan Hembery on 09/02/2024.
//

#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);
    if (tempSurface == NULL) {
        std::cout << "Unable to load image from filepath: " << fileName << std::endl;
    }
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    
    return texture;
};
