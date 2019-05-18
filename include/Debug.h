#pragma once

#include <SFML/Window/Window.hpp>


/**
 * Static debugging utilities
 */
class Debug {
public:

    /** Wait for key press */
    static void waitKey()
    {
        // TODO: Turn off key repeat?
        while (true) {
            for (uint32_t key = 0; key < sf::Keyboard::Key::KeyCount; ++key) {
                if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key)) return;    
            }
        }    
        
    }
};
