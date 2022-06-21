// Copyright Juan Lopez [UMASS_Lowell] [06/06/2022]
#include "Triangle.hpp"
// function to generate new color each time its called
int newColor(void) {
    return rand() % 255;
}

Triangle::Triangle(int n, double inLength, double x, double y, int color):\
depth(n), length(inLength), posX(x), posY(y) {
    double height = length*sqrt(3)/2;  // height

    // set three verticies
    triangle.setPointCount(3);

    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(length, 0));
    triangle.setPoint(2, sf::Vector2f(length/2, height));

    triangle.setFillColor(sf::Color(newColor()));
    triangle.setOutlineThickness(1);
    triangle.setOutlineColor(sf::Color\
    (newColor(), newColor(), newColor()));  // random color

    triangle.setPosition(posX, posY);
}
// getter
int Triangle::getDepth() const {
    return depth;
}

// getter
double Triangle::getLength() const {
    return length;
}

// getter
double Triangle::getX() const {
    return posX;
}

// getter
double Triangle::getY() const {
    return posY;
}

// deconstructor
Triangle::~Triangle() {
    length = 0;
    depth = 0;
}



void fTree(const Triangle &inputTriangle, std::vector<Triangle> &vecTri) {
    if (inputTriangle.getDepth() == 0) return;

    Triangle Left(inputTriangle.getDepth()-1.0, inputTriangle.getLength()\
    /2.0, inputTriangle.getX() - inputTriangle.getLength()\
    /4.0, inputTriangle.getY()\
     - inputTriangle.getLength()*sqrt(3.0)/4.0, newColor());
    // function called to make triangles diffrent color
    Triangle Right(inputTriangle.getDepth()-1.0, inputTriangle.getLength()\
    /2.0, inputTriangle.getX() + inputTriangle.getLength(), \
     inputTriangle.getY(), newColor());
    // function called to make triangles diffrent color
    Triangle Bottom(inputTriangle.getDepth()-1.0, inputTriangle.getLength()\
    /2.0, inputTriangle.getX(), inputTriangle.getY() +\
    inputTriangle.getLength()*sqrt(3.0)/2.0, newColor());

    vecTri.push_back(Left);
    vecTri.push_back(Right);
    vecTri.push_back(Bottom);

    fTree(Left, vecTri);
    fTree(Right, vecTri);
    fTree(Bottom, vecTri);
}

