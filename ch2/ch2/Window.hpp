//
//  Window.hpp
//  ch2
//
//  Created by Anton Z on 26/05/2019.
//  Copyright © 2019 Anton Z. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <SFML/Graphics.hpp>

// class definition
class Window{
public:
    // constructor
    Window();
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    // destructor
    ~Window();
    
    // methods
    void Update();
    void ToggleFullScreen();
    
    void BeginDraw(); // clear the window
    void Draw(sf::Drawable&);
    void EndDraw(); // display the changes
    
    // helpers
    bool IsDone();
    bool IsFullScreen();
    sf::Vector2u GetWindowSize();
    sf::RenderWindow* GetRenderWindow();
    
private:
    // methods
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);
    void Destroy();
    void Create();
    
    // state
    sf::RenderWindow m_window;
    std::string m_windowTitle;
    sf::Vector2u m_windowSize;
    
    bool m_isFullScreen;
    bool m_isDone;
};

#endif /* Window_hpp */
