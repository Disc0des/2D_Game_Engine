//
//  Game.cpp
//  2D_Game_Engine
//
//  Created by Dan Hembery on 27/01/2024.
//

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

SDL_Texture* playerOne;
SDL_Rect srcRect, destRect;

Game::Game() {
    
}

Game::~Game() {
    
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    
    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized..." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
        if(window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std:: endl;
        }

        // Rendering player one
        playerOne = TextureManager::LoadTexture("assets/player_1_S.png", renderer);

        SDL_PumpEvents();

        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    counter++;
    destRect.h = 64;
    destRect.w = 64;
    destRect.x = counter;
}

void Game::render() {
    SDL_RenderClear(renderer);
    
    // Render player one
    SDL_RenderCopy(renderer, playerOne, NULL, &destRect);
    
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
