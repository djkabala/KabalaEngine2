#include "vkImageView.h"
vk::ImageView::ImageView(DevicePtr device, ImageViewCreateInfoPtr info, const VkAllocationCallbacks* allocator) : _view(nullptr), _device(device), _allocator(allocator)
{
     VkResult res = vkCreateImageView(_device->getRaw(), info->getRaw(), _allocator, &_view);
     if (res != VK_SUCCESS)
     {
         throw res;
     }
}

vk::ImageView::~ImageView()
{
    if (_view != nullptr)
    {
        vkDestroyImageView(_device->getRaw(), _view, _allocator);
    }
}
