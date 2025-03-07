#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <iostream>
#include <SFML/OpenGL.hpp>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    srand(time(nullptr));

    const sf::Font font(L"Lab_1/Resources/Font/Times_New_roman-font.ttf");

    sf::RenderWindow window(sf::VideoMode().getDesktopMode(), L"Овдієнко Андрій ПА-22-2"/*, sf::Style::None*/);


    sf::Image icon;
    if (!icon.loadFromFile(L"Lab_1/Resources/img/Icon/Logo_of_DNU.png"))
    {
        std::cerr << "Failed to load icon!\n";

    }
    window.setIcon(icon);

    int r = 0;
    int g = 0;
    int b = 0;
    bool rl = true;
    bool gl = false;
    bool bl = false;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        /* glClearColor(0.0f, 1.0f, 0.0f,1.0f);

         glClear(GL_COLOR_BUFFER_BIT);*/


        window.clear(sf::Color(r, g, b));
        window.display();

        rl = rand() % 2;
        gl = rand() % 2;
        bl = rand() % 2;

        if (rl) {
            g += 1;
            g = g % 256;
        }
        if (gl) {
            b += 1;
            b = b % 256;
        }
        if (bl) {
            r += 1;
            r = r % 256;
        }
    }

}