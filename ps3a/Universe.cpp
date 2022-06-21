// Copyright Juan Lopez [UMASS_Lowell] [06/06/2022]
#include "Universe.hpp"
Universe::Universe():\
numOfPlanets(0), radius(0) {}

Universe::Universe(std::string image_filename) {
    if (!image.loadFromFile(image_filename)) {
        throw std::invalid_argument("Universe image file not found,"
        " exiting");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    numOfPlanets = 0;
    radius = 0;
}

Universe::Universe(const Universe& cpyConstructor) {
    numOfPlanets = cpyConstructor.numOfPlanets;
    radius = cpyConstructor.radius;
    image = cpyConstructor.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

Universe::Universe(Universe&& mvConstructor) noexcept {
    numOfPlanets = mvConstructor.numOfPlanets;
    radius = mvConstructor.radius;
    image = mvConstructor.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    mvConstructor.numOfPlanets = 0;
    mvConstructor.radius = 0;
}
int Universe::getNumOfPlanets(void) const {
    return numOfPlanets;
}
double Universe::getRadius(void) const {
    return radius;
}
sf::Image Universe::getImage(void) const {
    return image;
}


void Universe::setNumOfPlanets(int numOf) {
    numOfPlanets = numOf;
}
void Universe::setRadius(double rad) {
    radius = rad;
}
void Universe::setImage(std::string imageFileName) {
    if (!image.loadFromFile(imageFileName)) {
        throw std::invalid_argument("Universe image file not found, exiting.");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

Universe:: ~Universe() {
    numOfPlanets = 0;
    radius = 0;
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

std::ostream& operator<<(std::ostream& out, Universe& universe) {
    std::cout << universe.getNumOfPlanets() <<" "<< universe.getRadius();

    return out;
}



// overloaded insertion operator for file input through terminal
std::istream& operator>>(std::istream& in, Universe& universe) {
    double dubVal;
    std::string image;
    std::string imageFileName;
    sf::Vector2u windowSize = universe.getImage().getSize();

    double numPlan;
    in >> numPlan;
    universe.setNumOfPlanets(numPlan);
    double tempRad;
    in >> tempRad;
    universe.setRadius(tempRad);

    // get data for each planet
    for (int i = 0; i < universe.getNumOfPlanets(); i++) {
        CelestialBody* planet = new CelestialBody();

        // get xPos
        in >> dubVal;
        dubVal = (((dubVal / 2) / universe.getRadius())\
         * windowSize.x) + (windowSize.x / 2);
        planet->setPosX(dubVal);

        // get yPos
        in >> dubVal;
        dubVal = (((dubVal / 2) / universe.getRadius())\
         * windowSize.y) + (windowSize.y / 2);
        planet->setPosY(dubVal);

        //  planet->updatePosition();

        // get velocity, mass and image file
        in >> dubVal;
        planet->setVelocityX(dubVal);
        in >> dubVal;
        planet->setVelocityY(dubVal);
        in >> dubVal;
        planet->setMass(dubVal);
        in >> imageFileName;
        image = "nbody/" + imageFileName;

        try {
            planet->setImage(image);
        }
        catch (std::invalid_argument& err) {
            std::cout << err.what() << std::endl;
            exit(-1);
        }
        universe.planets.push_back(planet);
    }

    return in;
}

Universe& Universe::operator=(Universe& cpyInptVal) {
    if (this == &cpyInptVal) {
       return *this;
    }

    numOfPlanets = cpyInptVal.numOfPlanets;
    radius = cpyInptVal.radius;
    image = cpyInptVal.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    return *this;
}

Universe& Universe::operator=(Universe&& mvInptVal) noexcept {
    if (this == &mvInptVal) {
        return *this;
    }

    // copy
    numOfPlanets = mvInptVal.numOfPlanets;
    // delete
    mvInptVal.numOfPlanets = 0;
    // copy
    radius = mvInptVal.radius;
    // delete
    mvInptVal.radius = 0;
    // copy
    image = mvInptVal.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    // delete
    mvInptVal.setImage(nullptr);

    return *this;
}
