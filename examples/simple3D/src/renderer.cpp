
/* Copyright (c) 2011-2013, Stefan Eilemann <eile@eyescale.ch>
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
 */

#include "renderer.h"

namespace simple3DApp
{
Renderer::Renderer( )
{
    ofLogVerbose();
}

void Renderer::init( co::Object* initData )
{
	cam.setDistance(100);
}

void Renderer::exit()
{
}

void Renderer::draw( co::Object* frameDataObj )
{
    const FrameData* frameData = static_cast< FrameData* >( frameDataObj );
    Application& application = static_cast< Application& >( getApplication( ));
    applyRenderContext();
    ofEnableDepthTest();
    ofMatrix4x4 frustum(getFrustum().compute_matrix());
    cam.setProjectionMatrix(frustum);
    setNearFar(10, 1000);
	cam.begin();		
        ofRotateX(ofRadToDeg(.5));
        ofRotateY(ofRadToDeg(-.5));
        ofBackground(0);
        ofSetColor(255,0,0);
        ofFill();
        ofSetColor(255,0,255);
        ofDrawBox(30);
        ofNoFill();
        ofSetColor(0);
        ofDrawBox(30);
        
        ofPushMatrix();
        ofTranslate(0,0,20);
        ofSetColor(0,0,255);
        ofFill();
        ofDrawBox(5);
        ofNoFill();
        ofSetColor(0);
        ofDrawBox(5);
        ofPopMatrix();
    cam.end();
}

}
