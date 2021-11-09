
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "BreakoutSystemComponent.h"

namespace Breakout
{
    class BreakoutModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(BreakoutModule, "{80ad3f32-24de-4bc3-99db-d25f6781d2cc}", AZ::Module);
        AZ_CLASS_ALLOCATOR(BreakoutModule, AZ::SystemAllocator, 0);

        BreakoutModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                BreakoutSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<BreakoutSystemComponent>(),
            };
        }
    };
}// namespace Breakout

AZ_DECLARE_MODULE_CLASS(Gem_Breakout, Breakout::BreakoutModule)
