#ifndef BODY_H
#define BODY_H

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"

class Body : public sf::Drawable, sf::Transformable
{
  public:
    Body();
    Body(double xPostion, double yPostion, double xInitialVelocity, double yInitialVelocity, std::string fileName);
    float getXPostion();
    float getYPostion();
    double getXInitialVelocity();
    double getYInitialVelocity();
    void addXVelocity(double changeInX);
    void addYVelocity(double changeInY);
    double getMass();
    void moveX(double changeInX);
    void moveY(double changeInY);
    void update(double universeSize, double scale, double deltaT);
    std::string getFileName();
    sf::Sprite getPlanet();
    void loadPicture(double universeSize, double loadscale);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    friend std::istream &operator>>(std::istream &input, Body &b);
    friend std::ostream &operator<<(std::ostream &output, Body &b);
    friend std::ofstream &operator<<(std::ofstream &output, Body &body);

  private:
    double xPostion;
    double yPostion;
    double xVelocity;
    double yVelocity;
    double mass;
    std::string fileName;
    sf::Texture picture;
    sf::Sprite planet;
};
#endif