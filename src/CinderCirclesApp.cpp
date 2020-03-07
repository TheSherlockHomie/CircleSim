#include <random>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Circle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

float get_random();

class CinderCirclesApp : public App {
	public:
		void setup() override;
		void mouseDown( MouseEvent event ) override;
		void update() override;
		void draw() override;
	private:
		float white;
		Circle a;
};

void CinderCirclesApp::setup()
{
	white = 1.0f;
	float rad = 20.0f;
	float mass = 1.0f;
	vec2 location((get_random() * (toPixels(getWindowWidth()) - 2 * rad) + rad), (get_random() * (toPixels(getWindowHeight()) - rad)) + rad);
	a = Circle(rad, mass, location);
}

void CinderCirclesApp::mouseDown( MouseEvent event )
{
}

void CinderCirclesApp::update()
{
	
}

void CinderCirclesApp::draw()
{
	gl::clear(Color(white, white, white), true);
	a.drawCircle();
}

//return uniformly distributed random float between 0.0f and 1.0f
float get_random()
{
	std::random_device rdev{};
	std::default_random_engine e{rdev()};
	std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
	return dis(e);
}

CINDER_APP( CinderCirclesApp, RendererGl )