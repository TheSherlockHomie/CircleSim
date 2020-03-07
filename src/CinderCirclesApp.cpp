#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderCirclesApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void CinderCirclesApp::setup()
{
}

void CinderCirclesApp::mouseDown( MouseEvent event )
{
}

void CinderCirclesApp::update()
{
}

void CinderCirclesApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( CinderCirclesApp, RendererGl )
