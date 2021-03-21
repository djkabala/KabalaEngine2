#include "vkDescriptorSetLayoutBinding.h"
vk::DescriptorSetLayoutBinding::DescriptorSetLayoutBinding(uint32_t              binding,
                                                           VkDescriptorType      descriptorType,
                                                           uint32_t              descriptorCount,
                                                           VkShaderStageFlags    stageFlags,
                                                           const VkSampler* pImmutableSamplers)
{
    _binding.binding = binding;
    _binding.descriptorType = descriptorType;
    _binding.descriptorCount = descriptorCount;
    _binding.stageFlags = stageFlags;
    _binding.pImmutableSamplers = pImmutableSamplers;
}
