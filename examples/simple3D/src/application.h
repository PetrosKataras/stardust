#pragma once

#include <stardust/application.h>
#include "frameData.h"

namespace simple3DApp
{
using simple3DApp::FrameData;

class Application : public stardust::Application
{
public:
    Application() {}

    bool init( const int argc, char** argv );
    bool run();
    virtual bool exit();

    virtual shared_ptr<stardust::Renderer>  createStardustRenderer();
    virtual co::Object* createObject( const uint32_t type );

    virtual void update();

private:
    FrameData _frameData;

    virtual ~Application() {}
};

typedef lunchbox::RefPtr< simple3DApp::Application > ApplicationPtr;
}

