// Copyright Juan Lopez [UMASS_Lowell] [06/06/2022]
#include "CelestialBody.hpp"
CelestialBody::CelestialBody():\
posX(0) , posY(0) , velocityY(0) , velocityX(0) , mass(0) {}

CelestialBody::CelestialBody(double inputPosX, double inputPosY, \
        double inputVelocityY, double inputVelocityX, \
        double inputMass, std::string imageFilename) :\
        posX(inputPosX), posY(inputPosY), \
        velocityY(inputVelocityY), velocityX(inputVelocityX), \
        mass(inputMass) {
        imgFilename = imageFilename;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        }
// accessors
double CelestialBody:: getVelocityX() const {
    return velocityX;
}
double CelestialBody:: getVelocityY() const {
    return velocityY;
}
double CelestialBody:: getPosX() const {
    return posX;
}
double CelestialBody:: getPosY() const {
    return posY;
}
double CelestialBody:: getMass() const {
    return mass;
}
sf::Image CelestialBody::getImage() const {
    return image;
}

void CelestialBody:: setVelocityX(double x) {
    velocityX = x;
}
void CelestialBody::setVelocityY(double y) {
    velocityY = y;
}
void CelestialBody::setPosX(double x) {
    posX = x;
}
void CelestialBody::setPosY(double y) {
    posY = y;
}
void CelestialBody::setMass(double Mass) {
    mass = Mass;
}
void CelestialBody::setImage(std::string image_filename) {
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

CelestialBody:: ~CelestialBody() {
    velocityX = 0;
    velocityY = 0;
    posX = 0;
    posY = 0;
    mass = 0;
}

// update x and y position of planet given the scale of the universe
void CelestialBody::updatePosition() {
}

std::istream& operator>>(std::istream& in, CelestialBody& CelestialBody) {
    double dubVal;
    in >> dubVal;
    CelestialBody.setPosX(dubVal);
    in >> dubVal;
    CelestialBody.setPosY(dubVal);
    in >> dubVal;
    CelestialBody.setVelocityY(dubVal);
    in >> dubVal;
    CelestialBody.setVelocityX(dubVal);
    in >> dubVal;
    CelestialBody.setMass(dubVal);
    std::string fileName;
    in >> fileName;
    CelestialBody.setImage(fileName);

    return in;
}
void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states)
const {
    target.draw(sprite, states);
}

std::ostream& operator<<(std::ostream& out , \
CelestialBody& CelestialBody) {
    std::cout << CelestialBody.getVelocityX() << \
    " " << CelestialBody.getVelocityY() << " "\
     << CelestialBody.getPosX() << " " << \
    CelestialBody.getPosY()\
     << " " << CelestialBody.getMass();



    return out;
}
