/* Author: Petros Kataras 2015 <petroskataras@gmail.com>
 *
 * Based on sequel examples and modified for stardust.
 *
 * Original sequel examples: Copyright (c) 2011-2014, Stefan Eilemann <eile@eyescale.ch>
 *
 */
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


