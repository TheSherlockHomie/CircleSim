#ifndef CIRCLE
#define CIRCLE

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

ci::vec2 coord2gl(ci::vec2 coordinates);

class Circle {
	ci::vec2 location;
	float radius;
	ci::Color color;
public:
	Circle();
	Circle(ci::vec2 loc, float r, ci::Color c);
	void drawCircle();
};

#endif