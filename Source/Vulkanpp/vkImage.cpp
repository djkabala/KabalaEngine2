#include "vkImage.h"
#include <assert.h>

vk::Image::Image(DevicePtr device, ImageCreateInfoPtr info, const VkAllocationCallbacks* allocator) : _image(nullptr), _createInfo(info), _device(device), _allocator(allocator), _deviceMemory(nullptr)
{
     VkResult res = vkCreateImage(_device->getRaw(), _createInfo->getRaw(), _allocator, &_image);
     if (res != VK_SUCCESS)
     {
         throw res;
     }
}

vk::Image::~Image()
{
    if (_image != nullptr)
    {
        vkDestroyImage(_device->getRaw(), _image, _allocator);

        free();
    }
}

VkMemoryRequirements vk::Image::getImageMemoryRequirements(void) const
{
    assert(_image != nullptr && _device != nullptr);
    VkMemoryRequirements reqs;
	vkGetImageMemoryRequirements(_device->getRaw(), _image, &reqs);

    return reqs;
}

void vk::Image::allocate(MemoryAllocateInfoPtr allocInfo)
{
    assert(_deviceMemory == nullptr);
    _allocInfo = allocInfo;
    VkResult res = vkAllocateMemory(_device->getRaw(), allocInfo->getRaw(), _allocator, &_deviceMemory);
    if (res != VK_SUCCESS)
    {
        throw res;
    }
}

void vk::Image::free(void)
{
	if (_deviceMemory != nullptr)
	{
		vkFreeMemory(_device->getRaw(), _deviceMemory, _allocator);
        _deviceMemory = nullptr;
	}
}

void vk::Image::bind(const VkDeviceSize offset)
{
    assert(_deviceMemory != nullptr);
    VkResult res = vkBindImageMemory(_device->getRaw(), _image, _deviceMemory, offset);
    if (res != VK_SUCCESS)
    {
        throw res;
    }
}
