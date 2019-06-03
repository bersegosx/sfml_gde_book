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
Game::Game(): m_window("Snake", sf::Vector2u(1024, 768)),
m_snake(32), m_world(sf::Vector2u(1024, 768)) {
    m_mushroomTexture.loadFromFile(resourcePath() + "Mushroom.png");
    m_mushroom.setTexture(m_mushroomTexture);
    m_mushroom.setOrigin(m_mushroomTexture.getSize().x/2, m_mushroomTexture.getSize().y/2);
    m_increment = sf::Vector2f(400.1f, 400.1f);
    
    m_elapsedTime = 0.0f;
}

Game::~Game() {}

void Game::Render() { 
    m_window.BeginDraw();
//    m_window.Draw(m_mushroom);
    
    Window* window = GetWindow();
    sf::RenderWindow* renderWindow = window->GetRenderWindow();
    m_snake.Render(renderWindow);
    m_world.Render(renderWindow);
    
    m_window.EndDraw();
}

void Game::Update() { 
    m_window.Update();
//    MoveMushroom();
    
    float timestep = 1.0f / m_snake.GetSpeed();
    printf("m_elapsedTime: %f, timestep: %f\n", m_elapsedTime, timestep);
    if (m_elapsedTime >= timestep) {
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsedTime -= timestep;
        if (m_snake.HasLost()) {
            m_snake.Reset();
        }
    }
}

void Game::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetDirection() != Direction::Down) {
        m_snake.SetDirection(Direction::Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetDirection() != Direction::Up) {
        m_snake.SetDirection(Direction::Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetDirection() != Direction::Right) {
        m_snake.SetDirection(Direction::Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetDirection() != Direction::Left) {
        m_snake.SetDirection(Direction::Right);
    }
}

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
    
    float deltaTime = m_elapsedTime;
    m_mushroom.setPosition(
        pos.x + m_increment.x * deltaTime,
        pos.y + m_increment.y * deltaTime);
}

Window* Game::GetWindow() {
    return &m_window;
}

float Game::GetElapsedTime() { return m_elapsedTime; }

void Game::RestartClock() {
    m_elapsedTime += m_clock.restart().asSeconds();
}
