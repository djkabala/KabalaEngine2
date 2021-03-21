#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

#include "vkApplicationInfo.h"

namespace vk
{

class InstanceCreateInfo
{
public:
    InstanceCreateInfo(ApplicationInfoPtr appInfo);

    InstanceCreateInfo(const VkInstanceCreateFlags flags, ApplicationInfoPtr appInfo,
						std::vector<const char*>& enabledExtensionsNames,
						std::vector<const char*>& enabledLayerNames);

    VkInstanceCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkInstanceCreateInfo* getRaw(void) const
    {
        return &_info;
    }

    InstanceCreateInfo() = delete;

protected:
    VkInstanceCreateInfo _info;
    ApplicationInfoPtr   _appInfo;
    const std::vector<const char*> _enabledExtensionsNames;
    const std::vector<const char*> _enabledLayerNames;
};

typedef std::shared_ptr<InstanceCreateInfo> InstanceCreateInfoPtr; 

};

