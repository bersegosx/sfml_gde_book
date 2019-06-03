//
//  World.cpp
//  ch2
//
//  Created by Anton Z on 02/06/2019.
//  Copyright © 2019 Anton Z. All rights reserved.
//

#include "World.hpp"


World::World(sf::Vector2u l_windowSize) {
    // init world const
    m_blockSize = 32;
    m_windowSize = l_windowSize;
    
    // init apple
    RespawnApple();
    m_appleShape.setFillColor(sf::Color::Red);
    m_appleShape.setRadius(m_blockSize/2);
    
    // init boundaries
    for (int i=0; i < 4; ++i) {
        m_bounds[i].setFillColor(sf::Color(150, 0, 0));
        
        // wtf? "if (!(i + 1) % 2)"
        if (i % 2) {
            m_bounds[i].setSize(sf::Vector2f(m_windowSize.x, m_blockSize));
        } else {
            m_bounds[i].setSize(sf::Vector2f(m_blockSize, m_windowSize.y));
        }
        
        if (i < 2) {
            m_bounds[i].setPosition(0, 0);
        } else {
            m_bounds[i].setOrigin(m_bounds[i].getSize());
            m_bounds[i].setPosition(sf::Vector2f(m_windowSize));
        }
    }
}

void World::Update(Snake &l_player) {
    // check apple
    if (l_player.GetPosition() == m_applePos) {
        l_player.Extend();
        l_player.IncreaseScore();
        
        RespawnApple();
    }
    
    int gridSize_x = m_windowSize.x / m_blockSize;
    int gridSize_y = m_windowSize.y / m_blockSize;
    
    // check player
    if (l_player.GetPosition().x <= 0 ||
        l_player.GetPosition().y <= 0 ||
        l_player.GetPosition().x >= gridSize_x - 1 ||
        l_player.GetPosition().y >= gridSize_y - 1)
    {
        l_player.Lose();
    }
}

void World::RespawnApple() { 
    int maxX = (m_windowSize.x / m_blockSize) - 2;
    int maxY = (m_windowSize.y / m_blockSize) - 2;
    
    m_applePos = sf::Vector2i(rand() % maxX + 1, rand()  % maxY + 1);
    m_appleShape.setPosition(m_applePos.x * m_blockSize, m_applePos.y * m_blockSize);
}


World::~World() { return; }

int World::GetBlockSize() { 
    return m_blockSize;
}

void World::Render(sf::RenderWindow* l_window) { 
    for (int i=0; i < 4; ++i) {
        l_window->draw(m_bounds[i]);
    }
    l_window->draw(m_appleShape);
}
