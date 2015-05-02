#pragma once

#include <ofMain.h>
#include <co/object.h>

namespace stardust
{

class Application;

    namespace internal
    {
        class Renderer;
    }

class Renderer{

friend internal::Renderer;

    public:

        Renderer();

        virtual void init( co::Object* initData ){};
        virtual void draw( co::Object* frameData ) = 0;
        virtual void exit(){};

        void applyRenderContext();
        void setNearFar( const float nearPlane, const float farPlane );
        void enableScreenFrustum();
        void enablePerspectiveFrustum();


    protected:
        ///> The internal renderer should already be set when these functions become available. 
        ///> Right now its set just before calling init on the stardust renderer which should be the entry point for users.
        ///> If not set, fail miserably since there is something seriously wrong.
        Application& getApplication();
        const Application& getApplication() const;
        int getCurrentWindowWidth();
        int getCurrentWindowHeight();

        ofPoint getCurrentWindowPosition();
        ofPoint getCurrentWindowSize();

        ofRectangle getCurrentPixelViewport();


    private:

        void setImplementation( internal::Renderer* internalRenderer );

        internal::Renderer* _internalRenderer;
};
}
