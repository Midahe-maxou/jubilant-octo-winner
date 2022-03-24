#include "Plan.h"

#include <cmath>

const double pi = std::acos(-1);

double Point::distance(const Point& p) const noexcept
{
	return std::sqrt(pow((x - p.x), 2) + pow((y - p.y), 2));
}

double Cercle::aire() const noexcept
{
	return pow(rayon, 2) * pi;
}

double Cercle::perimetre() const noexcept
{
	return 2 * pi * rayon;
}

bool appartient(const Cercle& c, const Point& p)
{
	return p.distance(c.centre) < c.rayon;
}