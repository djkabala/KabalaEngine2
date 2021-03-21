#include "vkDescriptorPool.h"

vk::DescriptorPool::DescriptorPool(DevicePtr device, DescriptorPoolCreateInfoPtr createInfo, const VkAllocationCallbacks* allocator ) :
    _pool(nullptr), _createInfo(createInfo), _device(device), _allocator(allocator)
{
     VkResult res = vkCreateDescriptorPool(_device->getRaw(), _createInfo->getRaw(), _allocator, &_pool);
     if (res != VK_SUCCESS)
     {
         throw res;
     }
}

vk::DescriptorPool::~DescriptorPool()
{
    if (_pool != nullptr)
    {
         vkDestroyDescriptorPool(_device->getRaw(), _pool, _allocator);
    }
}
