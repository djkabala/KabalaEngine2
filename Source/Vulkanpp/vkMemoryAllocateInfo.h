#pragma once
#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class MemoryAllocateInfo
{
public:
	MemoryAllocateInfo(VkDeviceSize allocationSize, uint32_t memoryTypeIndex);

	VkMemoryAllocateInfo* getRaw(void) { return &_info; }

	const VkMemoryAllocateInfo* getRaw(void) const { return &_info; }
protected:
	VkMemoryAllocateInfo _info;
};

typedef std::shared_ptr<class MemoryAllocateInfo> MemoryAllocateInfoPtr;

};

