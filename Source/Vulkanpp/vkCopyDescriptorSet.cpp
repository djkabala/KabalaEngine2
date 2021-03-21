#include "vkCopyDescriptorSet.h"
vk::CopyDescriptorSet::CopyDescriptorSet(DescriptorSetPtr   srcSet,
                                         uint32_t           srcIndex,
                                         uint32_t           srcBinding,
                                         uint32_t           srcArrayElement,
                                         DescriptorSetPtr   dstSet,
                                         uint32_t           dstIndex,
                                         uint32_t           dstBinding,
                                         uint32_t           dstArrayElement,
                                         uint32_t           descriptorCount)
{
    _copy.sType           = VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET;
    _copy.pNext           = nullptr;
    _copy.srcSet          = srcSet->getRaw(srcIndex);
    _copy.srcBinding      = srcBinding;
    _copy.srcArrayElement = srcArrayElement;
    _copy.dstSet          = dstSet->getRaw(dstIndex);
    _copy.dstBinding      = dstBinding;
    _copy.dstArrayElement = dstArrayElement;
    _copy.descriptorCount = descriptorCount;
}

const std::vector<VkCopyDescriptorSet> vk::CopyDescriptorSets::getRaw(void) const
{
    std::vector<VkCopyDescriptorSet> result(size());
    for (CopyDescriptorSetPtr set : *this)
    {
        result.push_back(*set->getRaw());
    }

    return result;
}
