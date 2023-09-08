#include <SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"

/* Game class
 * This class holds all information for our main game loop.
 */

namespace {
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game() {
    
}

void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;
    bool exit;

    int LAST_UPDATE_TIME = SDL_GetTicks();
    do {
        input.beginNewFrame();
        bool newEvent = SDL_PollEvent(&event);
        if (!newEvent) {
            continue;
        }
        
        if (event.type == SDL_KEYDOWN) {
            if (event.key.repeat == 0) {
                input.keyDownEvent(event);
            }
        } else if (event.type == SDL_KEYUP) {
            input.keyUpEvent(event);
        }
        
        exit = event.type == SDL_QUIT || input.wasKeyPressed(SDL_SCANCODE_ESCAPE);
        
        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
    } while (!exit);
}

void Game::draw(Graphics &graphics) {

}

void Game::update(float elapsedTime) {

}