#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <map>

class Input {
public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);

    bool wasKeyPressed(SDL_Scancode scancode);
    bool wasKeyReleased(SDL_Scancode scancode);
    bool isKeyHeld(SDL_Scancode scancode);
private:
    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;
};

#endif