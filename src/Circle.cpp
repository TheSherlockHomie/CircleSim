#include "Circle.h"


//converts cartesian coordinates in 1st quadrant to openGl's coordinate system
ci::vec2 coord2gl(ci::vec2 coordinates)
{
coordinates.y = ci::app::toPixels(ci::app::getWindowHeight()) - coordinates.y;
return coordinates;
}


Circle::Circle()
{
	location = ci::vec2(0.0f, 0.0f);
	radius = 0.0f;
	color = ci::Color(0, 0, 0);
}

Circle::Circle(float r, float m, ci::vec2 loc, ci::vec2 v, ci::vec2 a, ci::Color c)
{
	radius = r;
	mass = m;
	location = loc;
	velocity = v;
	accel = a;
	color = c;
}

void Circle::drawCircle()
{
	ci::gl::color(color);
	ci::gl::drawSolidCircle(coord2gl(location), radius);
}