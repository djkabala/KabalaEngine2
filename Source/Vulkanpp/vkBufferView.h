#pragma once
#include "vkBufferViewCreateInfo.h"
#include <memory>
#include "vkDevice.h"

namespace vk
{

class BufferView
{
public:
	BufferView(DevicePtr device, BufferViewCreateInfoPtr pCreateInfo, const VkAllocationCallbacks* pAllocator);

	~BufferView();

	VkBufferView getRaw(void) { return _view; }

	const VkBufferView getRaw(void) const { return _view; }

protected:
	VkBufferView _view;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<BufferView> BufferViewPtr;

};

