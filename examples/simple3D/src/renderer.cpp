#include "renderer.h"

namespace simple3DApp
{
Renderer::Renderer( )
{
    ofLogVerbose();
}

void Renderer::init( co::Object* initData )
{
    cam.setPosition(ofVec3f(0,0,100));
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
        applyModelMatrix();
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
