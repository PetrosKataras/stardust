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

#include <window.h>
#include <ofGLRenderer.h>
#include <ofRectangle.h>

namespace stardust
{
namespace internal
{

Window::Window( eq::Window* window )
    : eqWindow( window )
    , _buttonPressed(false)
{
}

Window::~Window()
{
}

ofRectangle Window::getPixelViewport()
{
    return ofRectangle( eqWindow->getPixelViewport().x,
                        eqWindow->getPixelViewport().y,
                        eqWindow->getPixelViewport().w,
                        eqWindow->getPixelViewport().h 
                      );
}

const eq::Channels& Window::getEqChannels() const
{
    return eqWindow->getChannels();
}

const eq::PixelViewport& Window::getEqPixelViewport() const
{
    return eqWindow->getPixelViewport();
}

const eq::Viewport& Window::getEqViewport() const
{
    return eqWindow->getViewport();
}

void Window::setEqPixelViewport( const eq::PixelViewport& pvp )
{
    eqWindow->setPixelViewport( pvp );
}

void Window::setEqViewport( const eq::Viewport& vp )
{
    eqWindow->setViewport( vp );
}

void Window::initialiaze()
{
    currentRenderer = shared_ptr<ofBaseRenderer>( new ofGLRenderer(this) );
    static_cast<ofGLRenderer*>(currentRenderer.get())->setup();
    static_cast<ofGLRenderer*>(currentRenderer.get())->setOrientation( OF_ORIENTATION_DEFAULT, false );
}

ofPoint Window::getWindowPosition()
{
    windowPos.x = eqWindow->getPixelViewport().x;
    windowPos.y = eqWindow->getPixelViewport().y;
    return windowPos;
}

ofPoint Window::getWindowSize() 
{
    windowSize.x = getWidth();
    windowSize.y = getHeight();
    return windowSize;
}

int Window::getWidth() 
{
    width = eqWindow->getPixelViewport().w;
    return width;
}

int Window::getHeight()
{
    height = eqWindow->getPixelViewport().h; 
    return height;
}

}
}
