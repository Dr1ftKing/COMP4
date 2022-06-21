// Copyright Juan Lopez [UMASS_Lowell] [06/06/2022]
#include "Triangle.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr <<\
        "Incorrect format. correct format: ./TFractal <length> <depth>"\
        << std::endl;
        exit(-1);
    }

    int color = newColor();

    // length of the side of the base equilateral triangle
    double length = std::stod(argv[1]);

    // depth of recursion
    int nDepth = std::stoi(argv[2]);
    double windowSize = length*3;

    // create empty shape
    std::vector<Triangle> tri;

    // put the first triangle to the vector
    tri.push_back(Triangle(nDepth, length, length*5/7, length, color));

    // iterate the function to create more triangles
    fTree(tri.front(), tri);  // crashes here

    sf::RenderWindow window(sf::VideoMode\
    (windowSize, windowSize), "Recursice Triangle");
    window.setFramerateLimit(60);

    // event loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        std::vector<Triangle>::iterator j;
        for (j = tri.begin(); j!= tri.end(); ++j) {
            window.draw(*j);
        }
        window.display();
    }

    return 0;
}
