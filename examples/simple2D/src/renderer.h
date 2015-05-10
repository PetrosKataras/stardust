#pragma once

#include "application.h"
#include <stardust/renderer.h>

namespace simple2DApp
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
		ofTexture		texGray;
		ofTexture 		texColor;
		ofTexture		texColorAlpha;

		int 			w, h;
		
		ofPixels colorPixels;
		ofPixels grayPixels;
		ofPixels colorAlphaPixels;
		
    };

}


