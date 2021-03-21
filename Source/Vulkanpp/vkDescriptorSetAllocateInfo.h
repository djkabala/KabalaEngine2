#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>
#include "vkDescriptorPool.h"
#include "vkDescriptorSetLayout.h"

namespace vk
{

class DescriptorSetAllocateInfo
{
public:
	DescriptorSetAllocateInfo(DescriptorPoolPtr                descriptorPool,
                              const std::vector<DescriptorSetLayoutPtr>&    setLayouts);

	inline VkDescriptorSetAllocateInfo* getRaw(void) {return &_info;}

	inline const VkDescriptorSetAllocateInfo* getRaw(void) const {return &_info;}

	inline uint32_t getDescriptorSetCount(void) const { return _info.descriptorSetCount; }
protected:
	VkDescriptorSetAllocateInfo _info;
	DescriptorPoolPtr                _descriptorPool;
	const std::vector<DescriptorSetLayoutPtr> _setLayouts;
	std::vector<VkDescriptorSetLayout> _setLayoutsRaw;

};

typedef std::shared_ptr<DescriptorSetAllocateInfo> DescriptorSetAllocateInfoPtr; 
};


