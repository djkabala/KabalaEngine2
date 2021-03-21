#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "vkDevice.h"
#include "vkDescriptorSetLayoutCreateInfo.h"

namespace vk
{

class DescriptorSetLayout
{
public:
	DescriptorSetLayout(DevicePtr device, DescriptorSetLayoutCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator );

    ~DescriptorSetLayout();

	inline VkDescriptorSetLayout getRaw(void) {return _layout;}

	inline const VkDescriptorSetLayout getRaw(void) const {return _layout;}
protected:
	VkDescriptorSetLayout _layout;
	DescriptorSetLayoutCreateInfoPtr _createInfo;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<DescriptorSetLayout> DescriptorSetLayoutPtr; 
};


