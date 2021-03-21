#pragma once
#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class DescriptorSetLayoutBinding
{
public:
	DescriptorSetLayoutBinding(uint32_t              binding,
                               VkDescriptorType      descriptorType,
                               uint32_t              descriptorCount,
                               VkShaderStageFlags    stageFlags,
                               const VkSampler*      pImmutableSamplers);

	inline VkDescriptorSetLayoutBinding getRaw(void) {return _binding;}

	inline const VkDescriptorSetLayoutBinding getRaw(void) const {return _binding;}
protected:
	VkDescriptorSetLayoutBinding _binding;
};

typedef std::shared_ptr<DescriptorSetLayoutBinding> DescriptorSetLayoutBindingPtr; 
};

