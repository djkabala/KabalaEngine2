#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class CommandPoolCreateInfo
{
public:
	CommandPoolCreateInfo(const VkCommandPoolCreateFlags flags, uint32_t queueFamilyIndex);

    VkCommandPoolCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkCommandPoolCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkCommandPoolCreateInfo _info;
};

typedef std::shared_ptr<CommandPoolCreateInfo> CommandPoolCreateInfoPtr; 

};

