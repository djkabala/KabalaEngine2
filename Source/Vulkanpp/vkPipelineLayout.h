#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "vkDevice.h"
#include "vkPipelineLayoutCreateInfo.h"

namespace vk
{

class PipelineLayout
{
public:
	PipelineLayout(DevicePtr device, PipelineLayoutCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator);

    ~PipelineLayout();

	inline VkPipelineLayout getRaw(void) {return _layout;}

	inline const VkPipelineLayout getRaw(void) const {return _layout;}

	inline const std::vector<DescriptorSetLayoutPtr>& getDescriptorSetLayouts(void) const { return _createInfo->getDescriptorSetLayouts(); }
protected:
	VkPipelineLayout _layout;
	PipelineLayoutCreateInfoPtr _createInfo;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<PipelineLayout> PipelineLayoutPtr; 
};



