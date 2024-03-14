//
//  Game.hpp
//  2D_Game_Engine
//
//  Created by Dan Hembery on 27/01/2024.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "SDL2/SDL.h"
#include <SDL2_image/SDL_image.h>

class Game 
{
public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() 
    {
        return isRunning;
    };
    
    static SDL_Renderer* renderer;
    
private:
    int counter = 0;
    bool isRunning;
    SDL_Window *window;
};


#endif /* Game_hpp */
