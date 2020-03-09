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

//calculates the total force on the circle
void Circle::calculateForces()
{
	forces.clear();
	//TODO

	forces.push_back(calculateAirDrag()); //Air Drag
	ci::vec2 Fg(0, -1.0f * mass * 9.8f * 1000); //Gravitational force
	forces.push_back(Fg);
	
	netForce = std::accumulate(forces.begin(), forces.end(), ci::vec2(0.0f, 0.0f));
}

//Caluculate acceleration, velocity, position using Velocity Vertlet Integration
void Circle::calculateAVP(float timeStep)
{
	ci::vec2 last_accel = accel;
	location += ((velocity * timeStep) + last_accel * (0.5f * timeStep * timeStep)); //x = ut + 0.5*a*t^2
	ci::vec2 new_accel = netForce / mass;
	accel = (last_accel + new_accel) / 2.0f;
	velocity += accel * timeStep;
}

//returns air drag according to en.wikipedia.org/wiki/Drag_equation
ci::vec2 Circle::calculateAirDrag()
{
	float rho = 1.225f;
	float Cd = 0.00046f;
	float A = radius; //set up constants
	ci::vec2 airDrag(0.0f, 0.0f);
	if (velocity.x != 0.0f || velocity.y != 0.0f)
	{
		float x = ci::length(velocity);
		airDrag = velocity * velocity * velocity * (-0.5f * rho) * (Cd * A) / x;
	}
	return airDrag;
}

void Circle::drawCircle()
{
	ci::gl::color(color);
	ci::gl::drawSolidCircle(coord2gl(location), radius);
}