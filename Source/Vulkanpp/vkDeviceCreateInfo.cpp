#include "vkDeviceCreateInfo.h"

vk::DeviceCreateInfo::DeviceCreateInfo(const std::vector<const VkDeviceQueueCreateInfo*>& queueCreateInfos,
					const std::vector<const char*>& enabledLayerNames,
					const std::vector<const char*>& enabledExtensionNames,
					VkPhysicalDeviceFeatures* pEnabledFeatures
					) :
			_queueCreateInfos(queueCreateInfos),
			_enabledLayerNames(enabledLayerNames),
			_enabledExtensionNames(enabledExtensionNames)
{
    _info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = 0x0;
    _info.queueCreateInfoCount = _queueCreateInfos.size();
    _info.pQueueCreateInfos = ((_queueCreateInfos.size() == 0) ? nullptr : _queueCreateInfos[0]);
    _info.enabledLayerCount       = _enabledLayerNames.size();
    _info.ppEnabledLayerNames     = ((_enabledLayerNames.size() == 0) ? nullptr : _enabledLayerNames.data());
    _info.enabledExtensionCount   = _enabledExtensionNames.size();
    _info.ppEnabledExtensionNames = ((_enabledExtensionNames.size() == 0) ? nullptr : _enabledExtensionNames.data());
    _info.pEnabledFeatures        = pEnabledFeatures;
}
