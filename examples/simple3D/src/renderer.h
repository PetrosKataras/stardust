#pragma once

#include "application.h"
#include <stardust/renderer.h>

namespace simple3DApp
{
    class Renderer : public stardust::Renderer
    {
    public:
        Renderer( ) ;
        virtual ~Renderer() {}

    protected:
        virtual void init( co::Object* initData );
        virtual void exit();
        virtual void draw( co::Object* frameData );

    private:
        ofCamera cam;
    };

}


