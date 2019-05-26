#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    
    // Load mushroom
    sf::Texture mushroomTexture;
    if (!mushroomTexture.loadFromFile(resourcePath() + "Mushroom.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite mushroomSprite(mushroomTexture);
    sf::Vector2u size = mushroomTexture.getSize();
    mushroomSprite.setOrigin(size.x/2, size.y/2);
    sf::Vector2f increment(0.4f, 0.4f);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    
    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(400, 300);
    rectangle.setOrigin(rectangle.getSize().x/2, rectangle.getSize().y/2);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // move mushroom
        sf::Vector2f pos(mushroomSprite.getPosition());
        
        if (
            ((pos.x + size.x/2 > window.getSize().x) && increment.x > 0) ||
            ((pos.x - size.x/2 < 0) && increment.x < 0)
        ) {
            increment.x *= -1;
        }
        
        if (
            ((pos.y + size.y/2 > window.getSize().y) && increment.y > 0) ||
            ((pos.y - size.y/2 < 0) && increment.y < 0)
            ) {
            increment.y *= -1;
        }
        
        window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
        
        mushroomSprite.setPosition(pos + increment);
        window.draw(mushroomSprite);
        
        window.display();
    }

    return EXIT_SUCCESS;
}
