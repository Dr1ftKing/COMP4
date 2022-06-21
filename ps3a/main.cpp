// Copyright Juan Lopez [UMASS_Lowell] [06/06/2022]
#include <cmath>
#include "Universe.hpp"

int main(int argc, char* argv[]) {
        if (argc != 1) {
        std::cerr <<\
         "Incorrect usage. Usage:./NBody < planets.txt"\
          << std::endl;
        exit(-1);
    }


    Universe universe;
    try {
        //  universe = Universe("nbody/starfield.jpg");
        std::cin >> universe;
    }
    catch (std::invalid_argument& err) {
        std::cout << err.what() << std::endl;
        exit(-1);
    }

    sf::RenderWindow window(sf::VideoMode\
    (1280, 720), "NBody");
    window.setFramerateLimit(60);

    // get universe data from file input
    // std::cin >> universe;

// SFML display loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        window.display();
    }
}
