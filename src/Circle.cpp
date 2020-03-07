#include "Circle.h"

ci::vec2 coord2gl(ci::vec2 coordinates)
{
coordinates.y = (float)ci::app::getWindowHeight() - coordinates.y;
return coordinates;
}


Circle::Circle()
{
	location = ci::vec2(0.0f, 0.0f);
	radius = 0.0f;
	color = ci::Color(0, 0, 0);
}

Circle::Circle(ci::vec2 loc, float r, ci::Color c)
{
	location = loc;
	radius = r;
	color = c;
}

void Circle::drawCircle()
{
	ci::gl::color(color);
	ci::gl::drawSolidCircle(coord2gl(location), radius);
}