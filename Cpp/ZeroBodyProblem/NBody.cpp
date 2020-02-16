#include "NBody.h"

NBody::NBody()
{
}

void NBody::step(double seconds)
{
    //compute all values for each planet without changing origional
    for (std::shared_ptr<Body> planet1 : solarSystem)
    {
        for (std::shared_ptr<Body> planet2 : solarSystem)
        {
            if (planet1->getFileName() != planet2->getFileName())
            {
                pairwiseForceBetween(planet1, planet2, seconds);
            }
        }
    }
    //changing origional.
    for (std::shared_ptr<Body> planet : solarSystem)
    {
        planet->update(universeSize, scale, seconds);
    }
}

void NBody::setUniverseSize(double size)
{
    universeSize = size;
}

void NBody::pairwiseForceBetween(std::shared_ptr<Body> one, std::shared_ptr<Body> two, double deltaT)
{
    double deltaX = (one->getXPostion() - two->getXPostion()) / scale;
    double deltaY = (one->getYPostion() - two->getYPostion()) / scale;

    double r = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

    double F = (G * one->getMass() * two->getMass()) / pow(r, 2);

    double Fx = F * (deltaX / r);
    double Fy = F * (deltaY / r);

    double ax = Fx / one->getMass();
    double ay = Fy / one->getMass();

    one->addXVelocity(deltaT * ax);
    one->addYVelocity(deltaT * ay);
}

void NBody::form(std::vector<std::shared_ptr<Body>> system)
{
    solarSystem = system;
}

void NBody::setScale(double setScale)
{
    scale = setScale;
}

int main(int argc, char *argv[])
{
    double t = std::atof(argv[2]);
    double T = std::atof(argv[1]);
    int numberOfPlanets = 0;
    double sizeOfSolarSystem = 0;

    NBody system;
    std::cin >> numberOfPlanets;
    std::cin >> sizeOfSolarSystem;
    double scale = 1;

    if (sf::VideoMode::getDesktopMode().height < sizeOfSolarSystem)
    {
        scale = sf::VideoMode::getDesktopMode().height / (sizeOfSolarSystem);
    }
    sf::RenderWindow mainWindow(sf::VideoMode(sizeOfSolarSystem * scale, sizeOfSolarSystem * scale), "Solar system");
    system.setScale(scale);
    system.setUniverseSize(sizeOfSolarSystem);

    std::shared_ptr<Body> newPlanet;
    std::vector<std::shared_ptr<Body>> solarSystem;

    for (int index = 0; index < numberOfPlanets; index++)
    {
        newPlanet = std::shared_ptr<Body>(new Body());
        std::cin >> *newPlanet;
        newPlanet->loadPicture(sizeOfSolarSystem, scale);
        solarSystem.push_back(newPlanet);
    }

    system.form(solarSystem);

    while (mainWindow.isOpen() && t <= T)
    {
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mainWindow.close();
            }
        }

        system.step(500);

        mainWindow.clear();

        for (std::shared_ptr<Body> plan : solarSystem)
        {
            mainWindow.draw(*plan);
        }
        mainWindow.display();

        t++;
    }

    std::ofstream done;
    done.open("done.txt");
    done << numberOfPlanets << std::endl;
    done << sizeOfSolarSystem << std::endl;
    for (std::shared_ptr<Body> planet : solarSystem)
    {
        done << std::scientific << planet->getXPostion() << "\t" << planet->getYPostion() << "\t" << planet->getXInitialVelocity() << "\t" << planet->getYInitialVelocity() << "\t" << planet->getMass() << "\t" << planet->getFileName() << std::endl;
    }
    done.close();

    mainWindow.close();
}