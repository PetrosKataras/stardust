#include <viewData.h>

#include <application.h>

#include <eq/eventICommand.h>
#include <eq/fabric/event.h>
#ifndef EQ_2_0_API
#   include <eq/configEvent.h>
#endif

namespace stardust
{

ViewData::ViewData()
    : _stardustApplication(NULL)
{
}

ViewData::~ViewData()
{
}

void ViewData::setApplication( Application* stardustApp )
{
    _stardustApplication = stardustApp;
}

#ifndef EQ_2_0_API
bool ViewData::handleEvent( const eq::ConfigEvent* event )
{
    bool needsRedraw = seq::ViewData::handleEvent( event );
    if( _stardustApplication )
    {
        return needsRedraw || _stardustApplication->handleEvent( event->data );
    }
    return needsRedraw;
}
#endif

bool ViewData::handleEvent( eq::EventICommand command )
{
    bool needsRedraw =  seq::ViewData::handleEvent(command);
    if( _stardustApplication )
    {
        const eq::Event& event = command.read< eq::Event >();
        return needsRedraw || _stardustApplication->handleEvent( event );
    }
    return needsRedraw;
}

bool ViewData::update()
{
    ///> Not sure if this the best since we can have multiple views potentially ??
    ///> Maybe exposing a callback from MasterConfig between frameFinish/frameStart is a better idea??
    if( _stardustApplication )
    {
        _stardustApplication->update();
    }
    ///> We update all the time for now.
    return true;
}

void ViewData::serialize( co::DataOStream& os, const uint64_t dirtyBits )
{
    seq::ViewData::serialize( os, dirtyBits );
}

void ViewData::deserialize( co::DataIStream& is, const uint64_t dirtyBits )
{
    seq::ViewData::deserialize( is, dirtyBits );
}

}
