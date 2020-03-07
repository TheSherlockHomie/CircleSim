#ifndef CIRCLE
#define CIRCLE

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

ci::vec2 coord2gl(ci::vec2 coordinates);

class Circle {
	float radius;
	float mass;
	ci::vec2 location;
	ci::vec2 velocity;
	ci::vec2 accel;
	ci::Color color;
public:
	Circle();
	Circle(float r, float m, ci::vec2 loc = ci::vec2(0.0f, 0.0f), ci::vec2 v = ci::vec2(0.0f, 0.0f), ci::vec2 a = ci::vec2(0.0f,0.0f), ci::Color c = ci::Color(1, 0, 0));
	void drawCircle();
};

#endif