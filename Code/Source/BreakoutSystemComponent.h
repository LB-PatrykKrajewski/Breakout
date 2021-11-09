
#pragma once

#include <AzCore/Component/Component.h>

#include <Breakout/BreakoutBus.h>

namespace Breakout
{
    class BreakoutSystemComponent
        : public AZ::Component
        , protected BreakoutRequestBus::Handler
    {
    public:
        AZ_COMPONENT(BreakoutSystemComponent, "{fbc123ba-fa9d-4b10-8bce-88634a369c51}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        BreakoutSystemComponent();
        ~BreakoutSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // BreakoutRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
