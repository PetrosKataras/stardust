/*
 * Stardust
 * ========
 *
 * Copyright (c) 2015-2016, Petros Kataras <petroskataras@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of Stardust nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * Equalizer:
 * ==========
 *
 * Copyright (c) 2011-2014, Stefan Eilemann <eile@eyescale.ch>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of Eyescale Software GmbH nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * openFrameworks is released under the terms of the MIT licence.
 * ==============================================================
 *
 */
#include <internal/renderer.h>
#include <internal/window.h>
#include <renderer.h>
#include <viewData.h>

namespace stardust
{
namespace internal
{
typedef std::map< uint32_t, shared_ptr<internal::Window> >::const_iterator
    WindowsCIter;

seq::ViewData* Renderer::createViewData()
{
    return static_cast<seq::ViewData*>( new ViewData );
}

bool Renderer::init( co::Object* initData )
{
    _initData = initData;
    return seq::Renderer::init( initData );
}

void Renderer::draw( co::Object* frameData )
{
    if( !_userRenderer )
        return;

    /// update events
    WindowsCIter i = _windows.find( getWindowID() );
    if( i != _windows.end() ){
        i->second->events().notifyUpdate();
    }
    ///> update callback
    _userRenderer->update();
    ///> draw callback
    _userRenderer->draw( frameData );
}

bool Renderer::exit()
{
    if( _userRenderer )
        _userRenderer->exit();

    return seq::Renderer::exit();
}

void Renderer::enableScreenFrustum()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    applyScreenFrustum();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Renderer::enablePerspectiveFrustum()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    applyPerspectiveFrustum();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int Renderer::getCurrentWindowWidth()
{
    return getPixelViewport().w;
}

int Renderer::getCurrentWindowHeight()
{
    return getPixelViewport().h;
}

ofPoint Renderer::getCurrentWindowPosition()
{
    return ofPoint( getPixelViewport().x, getPixelViewport().y );
}

ofPoint Renderer::getCurrentWindowSize()
{
    return ofPoint( getPixelViewport().w, getPixelViewport().h );
}

ofRectangle Renderer::getCurrentPixelViewport()
{
    const seq::PixelViewport& pvp = getPixelViewport();
    return ofRectangle( pvp.x, pvp.y, pvp.w, pvp.h );
}

shared_ptr<ofBaseRenderer> Renderer::ofRenderer()
{
    WindowsCIter i = _windows.find( getWindowID() );
    if( i != _windows.end() ){
        return i->second->renderer();
    }
    LBERROR << "Stardust::Renderer::ofRenderer() ---> Something is seriously wrong -- Stardust could not find an OF renderer for window " << getWindowID() << "____Prepare to FAIL____" << std::endl;
    return 0;
}

ofCoreEvents& Renderer::events()
{
    WindowsCIter i = _windows.find( getWindowID() );
    return i->second->events();
}

bool Renderer::initContext( co::Object* object )
{
    if( !seq::Renderer::initContext( object ))
        return false;

    const uint32_t windowID = getWindowID();
    _windows[ windowID ] = shared_ptr<internal::Window>( new internal::Window );
    _windows[ windowID ]->initialiaze( getCurrentPixelViewport() );

    ofGetMainLoop()->addWindow( _windows[ windowID ] );
    ///> TODO: Loop through windows.
    ofGetMainLoop()->setCurrentWindow( _windows[ windowID ] );

    if( _userRenderer ) return true;

    _userRenderer = static_cast<stardust::Application&>(getApplication()).createStardustRenderer();

    if( _userRenderer )
    {
        _userRenderer->setImplementation(this);
        _userRenderer->init( _initData );
    }

    return true;
}

bool Renderer::exitContext()
{
    ///> TODO: Clear windows map.......

    return seq::Renderer::exitContext();
}

bool Renderer::processEvent( const eq::Event& event )
{
    ///> forward moused/keyboard events...
    WindowsCIter i = _windows.find( getWindowID() );
    if( i == _windows.end() )
        return false;

    switch(event.type)
    {
    case eq::Event::CHANNEL_POINTER_BUTTON_PRESS:
    {
        ofGetMainLoop()->setCurrentWindow(i->second);
        const eq::PointerEvent& pressEvent = event.pointerButtonPress;
        int button = 0;
        switch( pressEvent.button )
        {
        case eq::PTR_BUTTON1:
        {
            button = OF_MOUSE_BUTTON_LEFT;
            break;
        }
        case eq::PTR_BUTTON2:
        {
            button = OF_MOUSE_BUTTON_MIDDLE;
            break;
        }
        case eq::PTR_BUTTON3:
        {
            button = OF_MOUSE_BUTTON_RIGHT;
            break;
        }
        }
        i->second->_buttonPressed = true;
        i->second->_buttonInUse = button;
        i->second->events().notifyMousePressed( pressEvent.x, pressEvent.y, button );
        return true;
    }
    case eq::Event::CHANNEL_POINTER_BUTTON_RELEASE:
    {
        ofGetMainLoop()->setCurrentWindow(i->second);
        const eq::PointerEvent& releaseEvent = event.pointerButtonRelease;
        int button = 0;
        switch( releaseEvent.button )
        {
        case eq::PTR_BUTTON1:
        {
            button = OF_MOUSE_BUTTON_LEFT;
            break;
        }
        case eq::PTR_BUTTON2:
        {
            button = OF_MOUSE_BUTTON_MIDDLE;
            break;
        }
        case eq::PTR_BUTTON3:
        {
            button = OF_MOUSE_BUTTON_RIGHT;
            break;
        }
        }
        i->second->_buttonPressed = false;
        i->second->_buttonInUse = button;
        i->second->events().notifyMouseReleased( releaseEvent.x, releaseEvent.y, button );
        return true;
    }
    case eq::Event::CHANNEL_POINTER_MOTION:
    {
        ofGetMainLoop()->setCurrentWindow(i->second);
        if( i->second->_buttonPressed )
        {
            i->second->events().notifyMouseDragged( event.pointerMotion.x, event.pointerMotion.y, i->second->_buttonInUse );
        }
        else
        {
            i->second->events().notifyMouseMoved( event.pointerMotion.x, event.pointerMotion.y );
        }
        return true;
    }

    default:
        return false;
    }
}

}
}

