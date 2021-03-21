#include "vkDescriptorPoolCreateInfo.h"

vk::DescriptorPoolCreateInfo::DescriptorPoolCreateInfo(VkDescriptorPoolCreateFlags    flags,
    uint32_t                       maxSets,
    const std::vector<VkDescriptorPoolSize>& poolSizes) : _poolSizes(poolSizes)
{
    _pool.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    _pool.pNext = NULL;
    _pool.flags = flags;
    _pool.maxSets = maxSets;
    _pool.poolSizeCount = _poolSizes.size();
    _pool.pPoolSizes = (_poolSizes.size() == 0) ? nullptr : _poolSizes.data();
}
