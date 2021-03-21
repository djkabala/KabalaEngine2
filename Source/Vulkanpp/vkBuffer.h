#pragma once
#include "vkBufferCreateInfo.h"
#include <memory>
#include "vkDevice.h"
#include "vkMemoryAllocateInfo.h"

namespace vk
{

class Buffer
{
public:
	Buffer(DevicePtr device, BufferCreateInfoPtr pCreateInfo, const VkAllocationCallbacks* pAllocator);

	~Buffer();

	VkBuffer getRaw(void) { return _buffer; }

	const VkBuffer getRaw(void) const { return _buffer; }

    VkMemoryRequirements getBufferMemoryRequirements(void) const;

	void allocate(MemoryAllocateInfoPtr allocInfo);

	void free(void);

	void bind(const VkDeviceSize offset);

	void map(VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags mapFlags, void** data);

	void unmap();

protected:
	VkBuffer _buffer;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;

	MemoryAllocateInfoPtr _allocInfo;
	VkDeviceMemory _deviceMemory;
};

typedef std::shared_ptr<Buffer> BufferPtr;

};


