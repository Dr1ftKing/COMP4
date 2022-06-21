// Copyright Juan Lopez [UMASS_Lowell] [06/06/2022]
#ifndef _HOME_OEM_DESKTOP_PROJECT_PROJECT_3_PS3A_CELESTIALBODY_HPP_
#define _HOME_OEM_DESKTOP_PROJECT_PROJECT_3_PS3A_CELESTIALBODY_HPP_

#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class CelestialBody: public sf::Drawable {
 public:
        // parameters constructors
        CelestialBody();
        CelestialBody(double inputPosX, double inputPosY, \
        double inputVelocityY, double inputVelocityX, \
        double inputMass, std::string imageFilename);
        // getter
        double getVelocityX(void) const;
        double getVelocityY(void) const;
        double getPosX(void) const;
        double getPosY(void) const;
        double getMass(void) const;
        sf::Image getImage() const;

        void setVelocityX(double);
        void setVelocityY(double);
        void setPosX(double);
        void setPosY(double);
        void setMass(double);
        void setImage(std::string imageFilename);

        // update x and y position of planet
        void updatePosition(void);

        // deconstructor
        ~CelestialBody();

    // overloaded insertion operator
    // for file input through terminal

 private:
       // It must be sf::Drawable, with a
       // private virtual void method named draw
       // (as required of sf::Drawable subclasses).
       void draw(sf::RenderTarget& target, sf::\
       RenderStates states) const override;

        // Each instance of the class should contain
        // all properties needed for the simulation
        // (e.g. x and y position, x and y velocity, mass, and image data).
        double posX;
        double posY;
        double velocityY;
        double velocityX;
        double mass;
        std::string imgFilename;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;
};

std::istream& operator>>(std::istream& in, CelestialBody& CelestialBody);
std::ostream& operator<<(std::ostream& out, CelestialBody& CelestialBody);

#endif  //  _HOME_OEM_DESKTOP_PROJECT_PROJECT_3_PS3A_CELESTIALBODY_HPP_
