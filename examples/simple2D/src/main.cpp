#include "application.h"

int main( const int argc, char** argv )
{
    simple2DApp::ApplicationPtr app = new simple2DApp::Application();

    if( app->init( argc, argv ) && app->run() && app->exit( ))
        return EXIT_SUCCESS;
    
    return EXIT_FAILURE;
}
