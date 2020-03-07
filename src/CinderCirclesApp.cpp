#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "glm/gtc/random.hpp"
#include "Circle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

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
	a = Circle(vec2(glm::linearRand(0.0f, (float)getWindowWidth()), glm::linearRand(0.0f, (float)getWindowHeight())), 20.0, Color(1, 0, 0));
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
}

CINDER_APP( CinderCirclesApp, RendererGl )