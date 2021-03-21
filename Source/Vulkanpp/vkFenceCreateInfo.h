#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class FenceCreateInfo
{
public:
	FenceCreateInfo(const VkFenceCreateFlags flags);

    VkFenceCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkFenceCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkFenceCreateInfo _info;
};

typedef std::shared_ptr<FenceCreateInfo> FenceCreateInfoPtr; 

};

