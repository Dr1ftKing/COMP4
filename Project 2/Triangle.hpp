// Copyright Juan Lopez [UMASS_Lowell] [06/06/2022]
#ifndef _HOME_OEM_DESKTOP_PROJECT_PROJECT_2_TRIANGLE_HPP_
#define _HOME_OEM_DESKTOP_PROJECT_PROJECT_2_TRIANGLE_HPP_

#include <iostream>
#include <exception>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


// 1 details
class Triangle: public sf::Drawable {
 public:
        // parameters constructors
        Triangle(int n, double l, double x, double y, int color);
        // getter
        int getDepth() const;
        double getLength() const;

            // coords of center
        double getX() const;
        double getY() const;

        // deconstructor
        ~Triangle();

 private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(triangle, states);
    }
        int depth;
        double length;
        double posX;
        double posY;
        // creates empty shape
        sf::ConvexShape triangle;
};

int newColor(void);

void fTree(const Triangle &inputTriangle, std::vector<Triangle> &vecTri);
#endif  // _HOME_OEM_DESKTOP_PROJECT_PROJECT_2_TRIANGLE_HPP_
