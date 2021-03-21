#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "vkDevice.h"
#include "vkDescriptorSetAllocateInfo.h"

namespace vk
{

class DescriptorSet
{
public:
	DescriptorSet(DevicePtr device, DescriptorSetAllocateInfoPtr allocateInfo);

	inline VkDescriptorSet getRaw(const uint32_t index) {return _sets[index];}

	inline const VkDescriptorSet getRaw(const uint32_t index) const {return _sets[index];}

	inline const std::vector<VkDescriptorSet>& getRaw(void) const {return _sets;}

protected:
	std::vector<VkDescriptorSet> _sets;
	DescriptorSetAllocateInfoPtr _allocateInfo;
	DevicePtr _device;
};

typedef std::shared_ptr<DescriptorSet> DescriptorSetPtr; 
};




