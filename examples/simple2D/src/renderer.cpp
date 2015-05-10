#include "renderer.h"

namespace simple2DApp
{
Renderer::Renderer( )
{
}

void Renderer::init( co::Object* initData )
{
	w = 250;
	h = 200;
	
	grayPixels.allocate(w,h,OF_PIXELS_GRAY);
	colorPixels.allocate(w,h,OF_PIXELS_RGB);
	colorAlphaPixels.allocate(w,h,OF_PIXELS_RGBA);

	// gray pixels, set them randomly
	for (int i = 0; i < w*h; i++){
		grayPixels[i] = ofRandomuf() * 255;
		
	}
	
	// color pixels, use x and y to control red and green
	for (int y = 0; y < h; y++){
		for (int x = 0; x < w; x++){
			colorPixels.setColor(x,y,ofColor(x,y,0));
		}
	}
	
	// color alpha pixels, use x to control alpha
	for (int y = 0; y < h; y++){
		for (int x = 0; x < w; x++){
			colorAlphaPixels.setColor(x,y,ofColor(255,133,200,x));
		}
	}

	texGray.allocate(grayPixels);
	texColor.allocate(colorPixels);
	texColorAlpha.allocate(colorAlphaPixels);
}

void Renderer::exit()
{
}

void Renderer::draw( co::Object* frameDataObj )
{
    const FrameData* frameData = static_cast< FrameData* >( frameDataObj );
    Application& application = static_cast< Application& >( getApplication( ));
    applyRenderContext();
    
    ///> Enables ortho 2d operations. One unit of the frustum covers one pixel on screen.
    enableScreenFrustum();

	ofSetHexColor(0xffffff);
	
	texGray.draw(100,100,w,h);
	texColor.draw(350,300,w,h);
	
	// 	blending had to be enabled 
	// 	for transparency to work:
	ofEnableAlphaBlending();
	texColorAlpha.draw(250,200,w,h);
	ofDisableAlphaBlending();
}

}
