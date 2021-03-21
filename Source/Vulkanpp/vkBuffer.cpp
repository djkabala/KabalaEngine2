#include "vkBuffer.h"
#include <assert.h>

vk::Buffer::Buffer(DevicePtr device, BufferCreateInfoPtr info, const VkAllocationCallbacks* allocator) : _buffer(nullptr), _device(device), _allocator(allocator), _deviceMemory(nullptr)
{
     VkResult res = vkCreateBuffer(_device->getRaw(), info->getRaw(), _allocator, &_buffer);
     if (res != VK_SUCCESS)
     {
         throw res;
     }
}

vk::Buffer::~Buffer()
{
    if (_buffer != nullptr)
    {
        vkDestroyBuffer(_device->getRaw(), _buffer, _allocator);

        free();
    }
}

VkMemoryRequirements vk::Buffer::getBufferMemoryRequirements(void) const
{
    assert(_buffer != nullptr && _device != nullptr);
    VkMemoryRequirements reqs;
	vkGetBufferMemoryRequirements(_device->getRaw(), _buffer, &reqs);

    return reqs;
}

void vk::Buffer::allocate(MemoryAllocateInfoPtr allocInfo)
{
    assert(_deviceMemory == nullptr);
    _allocInfo = allocInfo;
    VkResult res = vkAllocateMemory(_device->getRaw(), allocInfo->getRaw(), _allocator, &_deviceMemory);
    if (res != VK_SUCCESS)
    {
        throw res;
    }
}

void vk::Buffer::free(void)
{
	if (_deviceMemory != nullptr)
	{
		vkFreeMemory(_device->getRaw(), _deviceMemory, _allocator);
        _deviceMemory = nullptr;
	}
}

void vk::Buffer::bind(const VkDeviceSize offset)
{
    assert(_deviceMemory != nullptr);
    VkResult res = vkBindBufferMemory(_device->getRaw(), _buffer, _deviceMemory, offset);
    if (res != VK_SUCCESS)
    {
        throw res;
    }
}

void vk::Buffer::map(VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags mapFlags, void** data)
{
    assert(_deviceMemory != nullptr);
    VkResult res = vkMapMemory(_device->getRaw(), _deviceMemory, offset, size, mapFlags, data);
    if (res != VK_SUCCESS)
    {
        throw res;
    }
}

void vk::Buffer::unmap()
{
    assert(_deviceMemory != nullptr);
    vkUnmapMemory(_device->getRaw(), _deviceMemory);
}
