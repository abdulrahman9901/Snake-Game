#include <iostream>
#include "player.h"

Player::Player(const Snake* Snake, const SDL_Point* Food) : snake(Snake), food(Food){
    std::cout << "Player's Constructor called.\n";
};

Player::~Player() {
    std::cout << "Player's Destructor called.\n";
}

void Player::play()
{
    // Find snake's head on the grid
    int curr_x = static_cast<int>(snake->head_x);
    int curr_y = static_cast<int>(snake->head_y);

    if (curr_x != food->x && curr_y != food->y) return; // Continue moving
    if (curr_x == food->x && curr_y == food->y) return; // Grab food and continue moving

    // Prepare an event
    SDL_Event sdlevent;
    sdlevent.type = SDL_KEYDOWN;

    if (curr_x == food->x)
    {
        if (curr_y > food->y) sdlevent.key.keysym.sym = SDLK_UP;
        else sdlevent.key.keysym.sym = SDLK_DOWN;
    }
    else
    {
        if (curr_x > food->x) sdlevent.key.keysym.sym = SDLK_LEFT;
        else sdlevent.key.keysym.sym = SDLK_RIGHT;
    }

    SDL_PushEvent(&sdlevent);
}
