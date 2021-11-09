
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "BreakoutSystemComponent.h"

namespace Breakout
{
    void BreakoutSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<BreakoutSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<BreakoutSystemComponent>("Breakout", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void BreakoutSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("BreakoutService"));
    }

    void BreakoutSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("BreakoutService"));
    }

    void BreakoutSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void BreakoutSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    BreakoutSystemComponent::BreakoutSystemComponent()
    {
        if (BreakoutInterface::Get() == nullptr)
        {
            BreakoutInterface::Register(this);
        }
    }

    BreakoutSystemComponent::~BreakoutSystemComponent()
    {
        if (BreakoutInterface::Get() == this)
        {
            BreakoutInterface::Unregister(this);
        }
    }

    void BreakoutSystemComponent::Init()
    {
    }

    void BreakoutSystemComponent::Activate()
    {
        BreakoutRequestBus::Handler::BusConnect();
    }

    void BreakoutSystemComponent::Deactivate()
    {
        BreakoutRequestBus::Handler::BusDisconnect();
    }
}
