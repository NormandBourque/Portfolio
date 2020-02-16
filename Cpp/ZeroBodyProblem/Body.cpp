#include "Body.h"

Body::Body()
{
}

Body::Body(double ixPostion, double iyPostion, double ixInitialVelocity, double iyInitialVelocity, std::string ifileName)
{
    xPostion = ixPostion;
    yPostion = iyPostion;
    xVelocity = ixInitialVelocity;
    yVelocity = iyInitialVelocity;
    fileName = ifileName;
    if (!picture.loadFromFile(fileName))
    {
        std::cout << "File did not load!";
    }
    else
    {
        planet.setTexture(picture);
        planet.setOrigin(planet.getLocalBounds().width / 2, planet.getLocalBounds().height / 2);
    }
}

float Body::getXPostion()
{
    return planet.getPosition().x;
}

float Body::getYPostion()
{
    return planet.getPosition().y;
}

double Body::getXInitialVelocity()
{
    return xVelocity;
}

double Body::getYInitialVelocity()
{
    return yVelocity;
}

std::string Body::getFileName()
{
    return fileName;
}

sf::Sprite Body::getPlanet()
{
    return planet;
}

double Body::getMass()
{
    return mass;
}

void Body::moveX(double changeInX)
{
    xPostion += changeInX;
}

void Body::moveY(double changeInY)
{
    yPostion += changeInY;
}

void Body::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(planet);
}

void Body::loadPicture(double universeSize, double scale)
{
    float xOrigin = universeSize / 2;
    float yOrigin = universeSize / 2;
    xPostion = (xOrigin + xPostion / 2);
    yPostion = (yOrigin - yPostion / 2);
    if (!picture.loadFromFile(fileName))
    {
        std::cout << "File did not load!";
    }
    else
    {
        planet.setTexture(picture);
        planet.setOrigin(planet.getLocalBounds().width / 2, planet.getLocalBounds().height / 2);
        planet.setPosition(sf::Vector2f(xPostion * scale, yPostion * scale));
    }
}

std::istream &operator>>(std::istream &input, Body &planet)
{
    input >> planet.xPostion >> planet.yPostion >> planet.xVelocity >> planet.yVelocity >> planet.mass >> planet.fileName;
    return input;
}
std::ostream &operator<<(std::ostream &output, Body &body)
{
    output << body.xPostion << "\t" << body.yPostion << "\t" << body.xVelocity << "\t" << body.yVelocity << "\t" << body.mass << "\t" << body.fileName << std::endl;
    return output;
}

void Body::update(double universeSize, double scale, double deltaT)
{
    xPostion = (xPostion - deltaT * xVelocity);
    yPostion = (yPostion - deltaT * yVelocity);

    planet.setPosition(sf::Vector2f(xPostion * scale, yPostion * scale));
}

void Body::addXVelocity(double deltaTxax)
{
    xVelocity += deltaTxax;
}

void Body::addYVelocity(double deltaTxay)
{
    yVelocity += deltaTxay;
}
