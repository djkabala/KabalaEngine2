#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>
#include "vkDescriptorSetLayoutBinding.h"

namespace vk
{

class DescriptorSetLayoutCreateInfo
{
public:
	DescriptorSetLayoutCreateInfo(VkDescriptorSetLayoutCreateFlags       flags,
                                  const std::vector<DescriptorSetLayoutBindingPtr>&    bindings);

	inline VkDescriptorSetLayoutCreateInfo* getRaw(void) {return &_info;}

	inline const VkDescriptorSetLayoutCreateInfo* getRaw(void) const {return &_info;}
protected:
	VkDescriptorSetLayoutCreateInfo _info;

	std::vector<VkDescriptorSetLayoutBinding> _bindings;
};

typedef std::shared_ptr<DescriptorSetLayoutCreateInfo> DescriptorSetLayoutCreateInfoPtr; 
};


