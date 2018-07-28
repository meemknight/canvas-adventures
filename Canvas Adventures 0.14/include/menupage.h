#ifndef MENUPAGE_H
#define MENUPAGE_H
#include <SFML/Graphics.hpp>
#include <vector>

class menupage
{
    sf::Sprite menu_sprite;
    sf::Texture menu_texture;
    sf::Vector2i croppos1;
    sf::Vector2i croppos2;
    sf::Vector2i position;
    sf::Vector2i size;
    sf::RenderWindow window;

    public:

        bool active=0;

        menupage();
        menupage(sf::Texture texture, sf::RenderWindow &window, sf::Vector2i position_, sf::Vector2i size_, sf::Vector2i croppos1_, sf::Vector2i croppos2_);

    void create(sf::Texture texture, sf::RenderWindow &window, sf::Vector2i position_, sf::Vector2i size_, sf::Vector2i croppos1_, sf::Vector2i croppos2_);

    void update();




};

#endif // MENUPAGE_H
