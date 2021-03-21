#include "vkBufferView.h"
vk::BufferView::BufferView(DevicePtr device, BufferViewCreateInfoPtr info, const VkAllocationCallbacks* allocator) : _view(nullptr), _device(device), _allocator(allocator)
{
     VkResult res = vkCreateBufferView(_device->getRaw(), info->getRaw(), _allocator, &_view);
     if (res != VK_SUCCESS)
     {
         throw res;
     }
}

vk::BufferView::~BufferView()
{
    if (_view != nullptr)
    {
        vkDestroyBufferView(_device->getRaw(), _view, _allocator);
    }
}
