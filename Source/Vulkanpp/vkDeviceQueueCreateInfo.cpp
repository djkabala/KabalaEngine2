#include "vkDeviceQueueCreateInfo.h"
vk::DeviceQueueCreateInfo::DeviceQueueCreateInfo(VkDeviceQueueCreateFlags flags, const uint32_t queueFamilyIndex, const std::vector<float>& queuePriorities) : _queuePriorities(queuePriorities)
{
    _info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = flags;
    _info.queueFamilyIndex = queueFamilyIndex;
    _info.queueCount = _queuePriorities.size();
    _info.pQueuePriorities = _queuePriorities.data();
}

