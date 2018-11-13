/**
 * Multiple main definition compiler error
 */

//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//void drawer(sf::RenderWindow* window,sf::Sprite* sprite){
//
//    window->draw(*sprite);
//
//}
//
//
//int main()
//{
//    // create the window
//    sf::RenderWindow* window;
//    window = new sf::RenderWindow(sf::VideoMode(800, 600), "My window");
//    sf::CircleShape shape(300.f);
//    shape.setFillColor(sf::Color::Green);
//    // run the program as long as the window is open
//
//    sf::Texture texture;
//    if(!texture.loadFromFile("res/toad.png")){
//        std::cout << "Nicht geladen" << std::endl;
//    }
//
//    sf::Sprite sprite;
//    sprite.setTexture(texture);
//    //sprite.setColor(sf::Color(255, 255, 255, 200));
//
//    sprite.setPosition(100, 100);
//    //sprite.setScale(sf::Vector2f(100,100));
//
//    while (window->isOpen())
//    {
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window->pollEvent(event))
//        {
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//                window->close();
//
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//                window->close();
//        }
//
//        // clear the window with black color
//        window->clear(sf::Color::Blue);
//
//        // draw everything here...
//
//        //window->draw(sprite);
//
//        drawer(window,&sprite);
//
//        //sprite.rotate(1);
//
//        // end the current frame
//        window->display();
//    }
//
//    return 0;
//}
