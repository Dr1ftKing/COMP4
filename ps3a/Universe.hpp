// Copyright Juan Lopez [UMASS_Lowell] [06/06/2022]
#ifndef _HOME_OEM_DESKTOP_PROJECT_PROJECT_3_PS3A_UNIVERSE_HPP_
#define _HOME_OEM_DESKTOP_PROJECT_PROJECT_3_PS3A_UNIVERSE_HPP_
#include <vector>
#include <string>
#include "CelestialBody.hpp"

class Universe : public sf::Drawable {
 public:
    // constructors
    Universe();
    explicit Universe(std::string image_filename);
    explicit Universe(const Universe& copyUniverse);
    explicit Universe(Universe&& moveUniverse) noexcept;
    ~Universe();

    // accessors and mutators
    int getNumOfPlanets(void) const;
    double getRadius(void) const;
    sf::Image getImage(void) const;


    void setNumOfPlanets(int);
    void setRadius(double);
    void setImage(std::string imageFileName);

    // vector of pointers to celestial bodies
    std::vector<CelestialBody*> planets;

    // overloaded assignment operators for Universe setup in main
    Universe& operator=(Universe& cpyInptVal);
    Universe& operator=(Universe&& mvInptVal) noexcept;


    // overloaded insertion operator for file input through terminal
 private:
    // override virtual draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    int numOfPlanets;
    double radius;               // radius of universe
    sf::Image image;            // image data for universe
    sf::Texture texture;
    sf::Sprite sprite;
};
std::istream& operator>>(std::istream& in, Universe& Universe);
std::ostream& operator<<(std::ostream& out, Universe& Universe);

#endif  // _HOME_OEM_DESKTOP_PROJECT_PROJECT_3_PS3A_UNIVERSE_HPP_
