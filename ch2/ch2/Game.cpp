//
//  Game.cpp
//  ch2
//
//  Created by Anton Z on 26/05/2019.
//  Copyright © 2019 Anton Z. All rights reserved.
//

#include "ResourcePath.hpp"
#include "Game.hpp"

/*
 `m_window` was declared in Game.hpp. Custom inline init
 */
Game::Game(): m_window("Chapter 2", sf::Vector2u(1024, 768)) {
    m_mushroomTexture.loadFromFile(resourcePath() + "Mushroom.png");
    m_mushroom.setTexture(m_mushroomTexture);
    m_mushroom.setOrigin(m_mushroomTexture.getSize().x/2, m_mushroomTexture.getSize().y/2);
    m_increment = sf::Vector2f(400.1f, 400.1f);
}

Game::~Game() {}

void Game::Render() { 
    m_window.BeginDraw();
    m_window.Draw(m_mushroom);
    m_window.EndDraw();
}

void Game::Update() { 
    m_window.Update();
    MoveMushroom();
}

void Game::HandleInput() {}

void Game::MoveMushroom() {
    // move mushroom
    sf::Vector2f pos(m_mushroom.getPosition());
    sf::Vector2u size(m_mushroomTexture.getSize());
    
    if (
        ((pos.x + size.x/2 > m_window.GetWindowSize().x) && m_increment.x > 0) ||
        ((pos.x - size.x/2 < 0) && m_increment.x < 0)
        ) {
        m_increment.x *= -1;
    }
    
    if (
        ((pos.y + size.y/2 > m_window.GetWindowSize().y) && m_increment.y > 0) ||
        ((pos.y - size.y/2 < 0) && m_increment.y < 0)
        ) {
        m_increment.y *= -1;
    }
    
    float deltaTime = m_elapsedTime.asSeconds();
    m_mushroom.setPosition(
        pos.x + m_increment.x * deltaTime,
        pos.y + m_increment.y * deltaTime);
}

Window* Game::GetWindow() {
    return &m_window;
}

sf::Time Game::GetElapsedTime() { return m_elapsedTime; }

void Game::RestartClock() {
    m_elapsedTime = m_clock.restart();
}
