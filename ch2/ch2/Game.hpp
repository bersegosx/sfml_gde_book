//
//  Game.hpp
//  ch2
//
//  Created by Anton Z on 26/05/2019.
//  Copyright © 2019 Anton Z. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include <SFML/Graphics.hpp>

class Game{
public:
    Game();
    ~Game();
    
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();
    
private:
    void MoveMushroom();
    
    Window m_window;
    sf::Texture m_mushroomTexture;
    sf::Sprite m_mushroom;
    sf::Vector2f m_increment;
};

#endif /* Game_hpp */
