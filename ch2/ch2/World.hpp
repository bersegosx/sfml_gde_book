//
//  World.hpp
//  ch2
//
//  Created by Anton Z on 02/06/2019.
//  Copyright © 2019 Anton Z. All rights reserved.
//

#ifndef World_hpp
#define World_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Snake.hpp"

class World {
public:
    World(sf::Vector2u l_windowSize);
    ~World();
    
    int GetBlockSize();
    void RespawnApple();
    
    void Update(Snake& l_player);
    void Render(sf::RenderWindow* l_window);
    
private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_applePos;
    int m_blockSize;
    
    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];
};

#endif /* World_hpp */
