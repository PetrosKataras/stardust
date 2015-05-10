#pragma once

#include <co/serializable.h>

namespace simple2DApp
{
/**
 * Frame-specific data.
 *
 * The frame-specific data is used as a per-config distributed object and
 * contains mutable, rendering-relevant data. Each rendering thread (pipe) keeps
 * its own instance synchronized with the frame currently being rendered. The
 * data is managed by the Config, which modifies it directly.
 */
class FrameData : public co::Serializable
{
public:
    FrameData();

    virtual ~FrameData() {}

protected:
    /** @sa Object::serialize() */
    virtual void serialize( co::DataOStream& os,
                            const uint64_t dirtyBits );
    /** @sa Object::deserialize() */
    virtual void deserialize( co::DataIStream& is,
                              const uint64_t dirtyBits );

    virtual ChangeType getChangeType() const { return DELTA; }

    /** The changed parts of the data since the last pack(). */
    enum DirtyBits
    {
    };

private:
};
}

