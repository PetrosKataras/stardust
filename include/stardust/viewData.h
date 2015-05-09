#pragma once

#include <seq/viewData.h>

namespace stardust
{

class Application;

class ViewData : public seq::ViewData{

public:
    ViewData();
    virtual ~ViewData();

#ifndef EQ_2_0_API
    virtual bool handleEvent( const eq::ConfigEvent* event );
#endif

    virtual bool handleEvent( eq::EventICommand command );

    virtual bool update();

    void setApplication( Application* stardustApp ); 
protected:

    virtual void serialize( co::DataOStream& os, const uint64_t dirtyBits );
    virtual void deserialize( co::DataIStream& is, const uint64_t dirtyBits );

private:
    Application* _stardustApplication;
};
}
