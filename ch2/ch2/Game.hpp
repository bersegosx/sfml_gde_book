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

#include "Snake.hpp"


class Game{
public:
    Game();
    ~Game();
    
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();
    sf::Time GetElapsedTime();
    void RestartClock();
    
private:
    void MoveMushroom();
    
    Window m_window;
    sf::Texture m_mushroomTexture;
    sf::Sprite m_mushroom;
    sf::Vector2f m_increment;
    sf::Time m_elapsedTime;
    sf::Clock m_clock;
    
    Snake m_snake;
};

#endif /* Game_hpp */
