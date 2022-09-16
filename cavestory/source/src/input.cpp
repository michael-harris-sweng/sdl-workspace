#include "input.h"

/* Input class
 * Keeps track of keyboard state
 */

/**
 * Resets key state on new frame.
 */
void Input::beginNewFrame() {
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
}

/**
 * Gets called when a key has been pressed.
 */
void Input::keyDownEvent(const SDL_Event& event) {
    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = true;
}

/**
 * Gets called when a key has been released.
 */
void Input::keyUpEvent(const SDL_Event& event) {
    this->_releasedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = false;
}

/**
 * Checks if a key was pressed in the current frame.
 */
bool Input::wasKeyPressed(SDL_Scancode scancode) {
    return this->_pressedKeys[scancode];
}

/**
 * Checks if a key was released in the current frame.
 */
bool Input::wasKeyReleased(SDL_Scancode scancode) {
    return this->_releasedKeys[scancode];
}

/**
 * Checks if a key is being held in the current frame.
 */
bool Input::isKeyHeld(SDL_Scancode scancode) {
    return this->_heldKeys[scancode];
}