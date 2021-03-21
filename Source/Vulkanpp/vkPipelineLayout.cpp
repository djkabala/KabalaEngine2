#include "vkPipelineLayout.h"

vk::PipelineLayout::PipelineLayout(DevicePtr device, PipelineLayoutCreateInfoPtr createInfo, const VkAllocationCallbacks* allocator ) :
    _layout(nullptr), _createInfo(createInfo), _device(device), _allocator(allocator)
{
     VkResult res = vkCreatePipelineLayout(_device->getRaw(), _createInfo->getRaw(), _allocator, &_layout);
     if (res != VK_SUCCESS)
     {
         throw res;
     }
}

vk::PipelineLayout::~PipelineLayout()
{
    if (_layout != nullptr)
    {
         vkDestroyPipelineLayout(_device->getRaw(), _layout, _allocator);
    }
}
