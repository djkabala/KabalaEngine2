#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>
#include "vkDescriptorSet.h"

namespace vk
{

class CopyDescriptorSet
{
public:
    CopyDescriptorSet(DescriptorSetPtr   srcSet,
                      uint32_t           srcIndex,
                      uint32_t           srcBinding,
                      uint32_t           srcArrayElement,
                      DescriptorSetPtr   dstSet,
                      uint32_t           dstIndex,
                      uint32_t           dstBinding,
                      uint32_t           dstArrayElement,
                      uint32_t           descriptorCount);

	inline VkCopyDescriptorSet* getRaw(void) {return &_copy;}

	inline const VkCopyDescriptorSet* getRaw(void) const {return &_copy;}
protected:
	VkCopyDescriptorSet                _copy;
};

typedef std::shared_ptr<CopyDescriptorSet> CopyDescriptorSetPtr; 

class CopyDescriptorSets : public std::vector<CopyDescriptorSetPtr>
{
public:
    const std::vector<VkCopyDescriptorSet> getRaw(void) const;

protected:
};

};


