//
//  Snake.hpp
//  ch2
//
//  Created by Anton Z on 27/05/2019.
//  Copyright © 2019 Anton Z. All rights reserved.
//

#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

struct SnakeSegment{
    SnakeSegment(int x, int y): position(x, y){}
    sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction{ None, Up, Down, Left, Right };

class Snake{
public:
    Snake(int l_block_size);
    ~Snake();
    
    void Reset();
    void SetDirection(Direction l_dir);
    Direction GetDirection();
    int GetSpeed();
    sf::Vector2i GetPosition();
    int GetLives();
    int GetScore();
    void IncreaseScore();
    bool HasLost();
    void Lose();
    void ToggleLost();
    void Extend();
    
private:
    void CheckCollision();
    
    SnakeContainer m_snakeBody;
    
    int m_size;
    Direction m_dir;
    sf::RectangleShape m_bodyRect;
    int m_speed;
    int m_lives;
    int m_score;
    bool m_lost;
};

#endif /* Snake_hpp */
