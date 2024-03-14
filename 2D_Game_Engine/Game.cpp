//
//  Game.cpp
//  2D_Game_Engine
//
//  Created by Dan Hembery on 27/01/2024.
//

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "ECS.hpp"
#include "Components.hpp"

GameObject* playerOne;
GameObject* playerTwo;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game() 
{
    
}

Game::~Game() 
{
    
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
    
    int flags = 0;
    if(fullscreen) 
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized..." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
        if(window) 
        {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) 
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std:: endl;
        }

        // Rendering players
        playerOne = new GameObject("assets/player_1_S.png", 0, 0);
        playerTwo = new GameObject("assets/player_2_S.png", 100, 0);
        
        newPlayer.addComponent<PositionComponent>();
        newPlayer.getComponent<PositionComponent>().setPos(500, 500);

        SDL_PumpEvents();

        isRunning = true;
    } 
    else
    {
        isRunning = false;
    }
}

void Game::handleEvents() 
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch(event.type) 
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    counter++;
    playerOne->Update();
    playerTwo->Update();
    manager.update();
    std::cout << newPlayer.getComponent<PositionComponent>().getPosX() << "," << newPlayer.getComponent<PositionComponent>().getPosY() << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    
    // Render players
    playerOne->Render();
    playerTwo->Render();
    
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
