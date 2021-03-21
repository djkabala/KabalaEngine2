#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class SemaphoreCreateInfo
{
public:
	SemaphoreCreateInfo(const VkSemaphoreCreateFlags flags);

    VkSemaphoreCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkSemaphoreCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkSemaphoreCreateInfo _info;
};

typedef std::shared_ptr<SemaphoreCreateInfo> SemaphoreCreateInfoPtr; 

};

