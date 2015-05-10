#include "application.h"
#include "renderer.h"

namespace simple2DApp
{
bool Application::init( const int argc, char** argv )
{
    if( !stardust::Application::init( argc, argv, 0 ))
    {
       return false;
    }

    return true;
}

shared_ptr<stardust::Renderer> Application::createStardustRenderer()
{
    return shared_ptr<stardust::Renderer>(new Renderer);
}

bool Application::run()
{
    return stardust::Application::run( &_frameData );
}

void Application::update()
{
}

bool Application::exit()
{
    return stardust::Application::exit();
}

co::Object* Application::createObject( const uint32_t type )
{
    switch( type )
    {
      case seq::OBJECTTYPE_FRAMEDATA:
          return new simple2DApp::FrameData;

      default:
          return seq::Application::createObject( type );
    }
}

}
