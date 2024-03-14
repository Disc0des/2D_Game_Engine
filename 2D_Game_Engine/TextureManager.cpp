//
//  TextureManager.cpp
//  2D_Game_Engine
//
//  Created by Dan Hembery on 09/02/2024.
//

#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);
    if (tempSurface == NULL) 
    {
        std::cout << "Unable to load image from filepath: " << fileName << std::endl;
    }
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    
    return texture;
};

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect)
{
    
};
