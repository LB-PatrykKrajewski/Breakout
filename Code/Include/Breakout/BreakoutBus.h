
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Breakout
{
    class BreakoutRequests
    {
    public:
        AZ_RTTI(BreakoutRequests, "{b3bec8a4-558d-41df-bb89-4775f2c00209}");
        virtual ~BreakoutRequests() = default;
        // Put your public methods here
    };
    
    class BreakoutBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using BreakoutRequestBus = AZ::EBus<BreakoutRequests, BreakoutBusTraits>;
    using BreakoutInterface = AZ::Interface<BreakoutRequests>;

} // namespace Breakout
