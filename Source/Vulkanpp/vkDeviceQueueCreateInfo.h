#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

namespace vk
{

class DeviceQueueCreateInfo
{
public:
	DeviceQueueCreateInfo(VkDeviceQueueCreateFlags flags, const uint32_t queueFamilyIndex, const std::vector<float>& queuePriorities);

	inline VkDeviceQueueCreateInfo* getRaw(void) {return &_info;}

	inline const VkDeviceQueueCreateInfo* getRaw(void) const {return &_info;}

protected:
	VkDeviceQueueCreateInfo _info;
	const std::vector<float> _queuePriorities;
};

typedef std::shared_ptr<DeviceQueueCreateInfo> DeviceQueueCreateInfoPtr; 

};

