#include "vkDescriptorSetLayout.h"

vk::DescriptorSetLayout::DescriptorSetLayout(DevicePtr device, DescriptorSetLayoutCreateInfoPtr createInfo, const VkAllocationCallbacks* allocator ) :
    _layout(nullptr), _createInfo(createInfo), _device(device), _allocator(allocator)
{
     VkResult res = vkCreateDescriptorSetLayout(_device->getRaw(), _createInfo->getRaw(), _allocator, &_layout);
     if (res != VK_SUCCESS)
     {
         throw res;
     }
}

vk::DescriptorSetLayout::~DescriptorSetLayout()
{
    if (_layout != nullptr)
    {
         vkDestroyDescriptorSetLayout(_device->getRaw(), _layout, _allocator);
    }
}
