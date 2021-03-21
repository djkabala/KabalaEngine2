#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "vkDevice.h"
#include "vkDescriptorPoolCreateInfo.h"

namespace vk
{

class DescriptorPool
{
public:
	DescriptorPool(DevicePtr device, DescriptorPoolCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator);

    ~DescriptorPool();

	inline VkDescriptorPool getRaw(void) {return _pool;}

	inline const VkDescriptorPool getRaw(void) const {return _pool;}
protected:
	VkDescriptorPool _pool;
	DescriptorPoolCreateInfoPtr _createInfo;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<DescriptorPool> DescriptorPoolPtr; 
};




