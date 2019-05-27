//
//  Snake.cpp
//  ch2
//
//  Created by Anton Z on 27/05/2019.
//  Copyright © 2019 Anton Z. All rights reserved.
//

#include "Snake.hpp"

Snake::Snake(int l_block_size) {
    m_size = l_block_size;
    m_bodyRect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
    Reset();
}

Snake::~Snake() {}

void Snake::CheckCollision() { 
    <#code#>;
}

void Snake::Reset() { 
    m_snakeBody.clear();
    
    m_snakeBody.push_back(SnakeSegment(5, 7));
    m_snakeBody.push_back(SnakeSegment(5, 6));
    m_snakeBody.push_back(SnakeSegment(5, 5));
    
    SetDirection(Direction::None);
    
    m_speed = 15;
    m_lives = 3;
    m_score = 0;
    m_lost = false;
}

void Snake::SetDirection(Direction l_dir) { m_dir = l_dir; }
Direction Snake::GetDirection() { return m_dir; }
int Snake::GetSpeed() { return m_speed; }

sf::Vector2i Snake::GetPosition() { 
    return (m_snakeBody.empty() ?
            sf::Vector2i(1, 1) : m_snakeBody.front().position);
}

void Snake::IncreaseScore() { m_score += 10; }
bool Snake::HasLost() { return m_lost; }
void Snake::Lose() { m_lost = true; }
void Snake::ToggleLost() { m_lost = !m_lost; }

void Snake::Extend() {
    if (m_snakeBody.empty()) { return; }
    
    // reference
    SnakeSegment& tail_head =
        m_snakeBody[m_snakeBody.size() - 1];
    
    if (m_snakeBody.size() > 1) {
        SnakeSegment& tail_bone =
        m_snakeBody[m_snakeBody.size() - 2];
        
        if (tail_head.position.x == tail_bone.position.x) {
            if (tail_head.position.y > tail_bone.position.y) {
                m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
            } else {
                m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
            }
        } else if (tail_head.position.y == tail_bone.position.y) {
            if (tail_head.position.x > tail_bone.position.x) {
                m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_bone.position.y));
            } else {
                m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_bone.position.y));
            }
        }
    } else {
        if (m_dir == Direction::Up) {
            m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
        } else if (m_dir == Direction::Down) {
            m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
        } else if (m_dir == Direction::Left) {
            m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
        } else if (m_dir == Direction::Right) {
            m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
        }
    }
}
