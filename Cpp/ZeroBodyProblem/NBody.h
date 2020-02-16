#ifndef NBODY_H
#define NBODY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <math.h>
#include "Body.h"
#include "SFML/Graphics.hpp"

class NBody
{
  public:
    NBody();
    void step(double seconds);
    void pairwiseForceBetween(std::shared_ptr<Body> one, std::shared_ptr<Body> two, double deltaT);
    void form(std::vector<std::shared_ptr<Body>> solarSystem);
    void setScale(double scale);
    void setUniverseSize(double universeSize);
    void move(double deltaT);

  private:
    const double G = 6.67e-11;
    std::vector<std::shared_ptr<Body>> solarSystem;
    double scale;
    double universeSize;
};
#endif