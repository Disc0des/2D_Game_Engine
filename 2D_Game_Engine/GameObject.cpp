//
//  GameObject.cpp
//  2D_Game_Engine
//
//  Created by Dan Hembery on 09/02/2024.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer)
{
    renderer = renderer;
    objectTexture = TextureManager::LoadTexture(textureSheet, renderer);
    
    
};

void GameObject::Update()
{
    xpos = 0;
    ypos = 0;
    
    srcRect.w = 13;
    srcRect.h = 17;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
    destRect.x = xpos;
    destRect.y = ypos;
};
 void GameObject::Render()
{
     SDL_RenderCopy(renderer, objectTexture, &srcRect, &destRect);
};
