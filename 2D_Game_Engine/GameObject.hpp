//
//  GameObject.hpp
//  2D_Game_Engine
//
//  Created by Dan Hembery on 09/02/2024.
//

#ifndef GameObject_hpp
#define GameObject_hpp
#include "Game.hpp"

class GameObject 
{
    
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();
    
    void Update();
    void Render();
    
private:
    int xpos;
    int ypos;
    
    SDL_Texture* objectTexture;
    SDL_Rect srcRect, destRect;
};

#endif /* GameObject_hpp */
