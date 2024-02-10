//
//  GameObject.cpp
//  2D_Game_Engine
//
//  Created by Dan Hembery on 09/02/2024.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
    objectTexture = TextureManager::LoadTexture(textureSheet);
    xpos = x;
    ypos = y;
    
};

void GameObject::Update()
{
    xpos++;
    ypos++;
    
    srcRect.w = 32;
    srcRect.h = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
    destRect.x = xpos;
    destRect.y = ypos;
};

 void GameObject::Render()
{
     SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
};
