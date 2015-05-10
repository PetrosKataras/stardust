#include "application.h"

int main( const int argc, char** argv )
{
    simple3DApp::ApplicationPtr app = new simple3DApp::Application();

    if( app->init( argc, argv ) && app->run() && app->exit( ))
        return EXIT_SUCCESS;
    
    return EXIT_FAILURE;
}
