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
#include <eq/client/window.h>
#include <internal/window.h>
#include <renderer.h>
#include <viewData.h>

namespace stardust
{
namespace internal
{

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
    if( _userRenderer )
    {
        /// update events
        windows_iterator = _windows.find( getCurrentWindow() );
        if( windows_iterator != _windows.end() ){
            windows_iterator->second->events().notifyUpdate();
        }
        ///> update callback
        _userRenderer->update();
        ///> draw callback
        _userRenderer->draw( frameData );
    }
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
   windows_iterator = _windows.find( getCurrentWindow() );
   if( windows_iterator != _windows.end() ){
        return windows_iterator->second->getWidth();
   }
   return -1;
}

int Renderer::getCurrentWindowHeight()
{
    windows_iterator = _windows.find( getCurrentWindow() );
    if( windows_iterator != _windows.end() ){
        return windows_iterator->second->getHeight();
    }
    return -1;
}

ofPoint Renderer::getCurrentWindowPosition()
{
    windows_iterator = _windows.find( getCurrentWindow() );
    if( windows_iterator != _windows.end() ){
        return windows_iterator->second->getWindowPosition();
    }
    return ofPoint(-1,-1);
}

ofPoint Renderer::getCurrentWindowSize()
{
    windows_iterator = _windows.find( getCurrentWindow() );
    if( windows_iterator != _windows.end() ){
        return windows_iterator->second->getWindowSize();
    }
    return ofPoint(-1,-1);
}

ofRectangle Renderer::getCurrentPixelViewport()
{
    windows_iterator = _windows.find( getCurrentWindow() );
    if( windows_iterator != _windows.end() ){
        return windows_iterator->second->getPixelViewport();
    }
    return ofRectangle();
}

shared_ptr<ofBaseRenderer> Renderer::ofRenderer()
{
    windows_iterator = _windows.find( getCurrentWindow() );
    if( windows_iterator != _windows.end() ){
        return windows_iterator->second->renderer();
    }
    LBERROR << "Stardust::Renderer::ofRenderer() ---> Something is seriously wrong -- Stardust could not find an OF renderer for window " << getCurrentWindow() << "____Prepare to FAIL____" << std::endl;
}

ofCoreEvents& Renderer::events()
{
    windows_iterator = _windows.find( getCurrentWindow() );
    return windows_iterator->second->events();
}

void Renderer::notifyWindowInitGL( eq::Window* eqWindow )
{
    _windows[ eqWindow ] =  shared_ptr<internal::Window>( new internal::Window( eqWindow ) );
    _windows[ eqWindow ]->initialiaze();

    ofGetMainLoop()->addWindow( _windows[ eqWindow ] );
    ///> TODO: Loop through windows.
    ofGetMainLoop()->setCurrentWindow( _windows[ eqWindow ] );

    if( _userRenderer ) return;

    _userRenderer = static_cast<stardust::Application&>(getApplication()).createStardustRenderer();

    if( _userRenderer )
    {
        _userRenderer->setImplementation(this);
        _userRenderer->init( _initData );
    }

}

void Renderer::notifyWindowExitGL( eq::Window* eqWindow )
{
    ///> TODO: Clear windows map.......

}

void Renderer::processWindowEvent( eq::Window* eqWindow, const eq::Event& event )
{
    ///> forward moused/keyboard events...
    windows_iterator = _windows.find( getCurrentWindow() );
    if( windows_iterator != _windows.end() )
    {
        switch(event.type)
        {
            case eq::Event::WINDOW_POINTER_BUTTON_PRESS:
            {
                ofGetMainLoop()->setCurrentWindow(windows_iterator->second);
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
                windows_iterator->second->_buttonPressed = true;
                windows_iterator->second->_buttonInUse = button;
                windows_iterator->second->events().notifyMousePressed( pressEvent.x, pressEvent.y, button );
                break;
            }
            case eq::Event::WINDOW_POINTER_BUTTON_RELEASE:
            {
                ofGetMainLoop()->setCurrentWindow(windows_iterator->second);
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
                windows_iterator->second->_buttonPressed = false;
                windows_iterator->second->_buttonInUse = button;
                windows_iterator->second->events().notifyMouseReleased( releaseEvent.x, releaseEvent.y, button );
                break;
            }
            case eq::Event::WINDOW_POINTER_MOTION:
            {
                ofGetMainLoop()->setCurrentWindow(windows_iterator->second);
                if( windows_iterator->second->_buttonPressed )
                {
                    windows_iterator->second->events().notifyMouseDragged( event.pointerMotion.x, event.pointerMotion.y, windows_iterator->second->_buttonInUse );
                }
                else
                {
                    windows_iterator->second->events().notifyMouseMoved( event.pointerMotion.x, event.pointerMotion.y );
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

}
}
