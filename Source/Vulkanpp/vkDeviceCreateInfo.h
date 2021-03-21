#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

namespace vk
{

class DeviceCreateInfo
{
public:
	DeviceCreateInfo(const std::vector<const VkDeviceQueueCreateInfo*>& queueCreateInfos,
					const std::vector<const char*>& enabledLayerNames,
					const std::vector<const char*>& enabledExtensionNames,
					VkPhysicalDeviceFeatures* pEnabledFeatures
					);

	inline VkDeviceCreateInfo* getRaw(void) {return &_info;}

	inline const VkDeviceCreateInfo* getRaw(void) const {return &_info;}
protected:
	VkDeviceCreateInfo _info;

	const std::vector<const VkDeviceQueueCreateInfo*> _queueCreateInfos;
	const std::vector<const char*> _enabledLayerNames;
	const std::vector<const char*> _enabledExtensionNames;
};

typedef std::shared_ptr<DeviceCreateInfo> DeviceCreateInfoPtr; 
};

