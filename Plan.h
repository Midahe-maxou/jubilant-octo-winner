#pragma once
#ifndef PLAN_HPP
#define PLAN_HPP

struct Point
{
	int x;
	int y;

	double distance(const Point& p) const noexcept;
};

struct Cercle
{
	Point centre;
	int rayon;

	double aire() const noexcept;
	double perimetre() const noexcept;
};

bool appartient(const Cercle& c, const Point& p);


#endif // PLAN_HPP