#include "MainMenu.hpp"
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.hpp"
#include "Tetris.hpp"
#include "Minesweeper.hpp"
#include "Xonix.hpp"
#include "Netwalk.hpp"


namespace GameBoy{
    int MainMenu(){
        sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Load button textures
    sf::Texture buttonTexture1;
    if (!buttonTexture1.loadFromFile(MAIN_MENU_BUTTON_1_FILEPATH)) {
        // error handling
    }
    sf::Texture buttonTexture2;
    if (!buttonTexture2.loadFromFile(MAIN_MENU_BUTTON_2_FILEPATH)) {
        // error handling
    }
    sf::Texture buttonTexture3;
    if (!buttonTexture3.loadFromFile(MAIN_MENU_BUTTON_3_FILEPATH)) {
        // error handling
    }
    sf::Texture buttonTexture4;
    if (!buttonTexture4.loadFromFile(MAIN_MENU_BUTTON_4_FILEPATH)) {
        // error handling
    }
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(MAIN_MENU_BACKGROUND_FILEPATH)) {
        // error handling
    }
    // Create buttons
    sf::Sprite button1(buttonTexture1), button2(buttonTexture2), button3(buttonTexture3), button4(buttonTexture4), background(backgroundTexture);
    button1.setPosition(161.2, 300);
    button2.setPosition(480.8, 300);
    button3.setPosition(161.2, 421.8);
    button4.setPosition(480.8, 421.8);
    background.setPosition(0, 0);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Check if buttons are clicked
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        window.close();
                        GameBoy::Tetris tetris;
                        tetris.Run();
                        
                    }
                    if (button2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        window.close();
                        GameBoy::Minesweeper();
                    }
                    if (button3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        window.close();
                        GameBoy::Xonix();
                    }
                    if (button4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        window.close();
                        GameBoy::Netwalk();
                    }
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);
        window.display();
    }

    return 0;
    }
}

