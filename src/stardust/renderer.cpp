#include <renderer.h>
#include <application.h>
#include <internal/renderer.h>

namespace stardust
{

Renderer::Renderer()
    : _internalRenderer(0)
{
}

ofCoreEvents& Renderer::events()
{
    return _internalRenderer->events();
}

shared_ptr<ofBaseRenderer> Renderer::ofRenderer()
{
    return _internalRenderer->ofRenderer();
}

void Renderer::applyRenderContext()
{
    _internalRenderer->applyRenderContext();
}

void Renderer::applyModelMatrix()
{
    _internalRenderer->applyModelMatrix();
}

void Renderer::updateNearFar( const eq::Vector4f& boundingSphere )
{
    _internalRenderer->updateNearFar( boundingSphere );
}

void Renderer::setNearFar( const float nearPlane, const float farPlane )
{
    _internalRenderer->setNearFar( nearPlane, farPlane );
}

void Renderer::enableScreenFrustum()
{
    _internalRenderer->enableScreenFrustum();
}

void Renderer::enablePerspectiveFrustum()
{
    _internalRenderer->enablePerspectiveFrustum();
}

const eq::Frustumf& Renderer::getFrustum() const
{
    return _internalRenderer->getFrustum();
}

const eq::Matrix4f& Renderer::getViewMatrix() const
{
    return _internalRenderer->getViewMatrix();
}

const eq::Matrix4f& Renderer::getModelMatrix() const
{
    return _internalRenderer->getModelMatrix();
}

void Renderer::setImplementation( internal::Renderer* internalRenderer )
{
    _internalRenderer = internalRenderer;
}

Application& Renderer::getApplication()
{
    _internalRenderer->getApplication();
}

const Application& Renderer::getApplication() const
{
    _internalRenderer->getApplication();
}

int Renderer::getCurrentWindowWidth()
{
    _internalRenderer->getCurrentWindowWidth();
}

int Renderer::getCurrentWindowHeight()
{
    return _internalRenderer->getCurrentWindowHeight();
}

ofPoint Renderer::getCurrentWindowPosition()
{
    return _internalRenderer->getCurrentWindowPosition();
}

ofPoint Renderer::getCurrentWindowSize()
{
    return _internalRenderer->getCurrentWindowSize();
}

ofRectangle Renderer::getCurrentPixelViewport()
{
    return _internalRenderer->getCurrentPixelViewport();
}

}
