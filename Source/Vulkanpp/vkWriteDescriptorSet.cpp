#include "vkWriteDescriptorSet.h"

vk::WriteDescriptorSet::WriteDescriptorSet(DescriptorSetPtr           dstSet,
                                           uint32_t                   dstSetIndex,
                                           uint32_t                   dstBinding,
                                           uint32_t                   dstArrayElement,
                                           VkDescriptorType descriptorType,
                                           const std::vector<DescriptorImageInfoPtr>&     imageInfos)
{
    _imageInfos.reserve(imageInfos.size());
    for (DescriptorImageInfoPtr imageInfo : imageInfos)
    {
        _imageInfos.push_back(imageInfo->getRaw());
    }

    _write.sType            = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    _write.pNext            = nullptr;
    _write.dstSet           = dstSet->getRaw(dstSetIndex);
    _write.dstBinding       = dstBinding;
    _write.dstArrayElement  = dstArrayElement;
    _write.descriptorCount  = _imageInfos.size();
    _write.descriptorType   = descriptorType;
    _write.pImageInfo       = (_imageInfos.size() == 0) ? nullptr : _imageInfos.data();
    _write.pBufferInfo      = nullptr;
    _write.pTexelBufferView = nullptr;
}

vk::WriteDescriptorSet::WriteDescriptorSet(DescriptorSetPtr           dstSet,
                   uint32_t                   dstSetIndex,
                   uint32_t                   dstBinding,
                   uint32_t                   dstArrayElement,
                   VkDescriptorType           descriptorType,
                   const std::vector<DescriptorBufferInfoPtr>&    bufferInfos)
{
    _bufferInfos.reserve(bufferInfos.size());
    for (DescriptorBufferInfoPtr bufferInfo : bufferInfos)
    {
        _bufferInfos.push_back(bufferInfo->getRaw());
    }

    _write.sType            = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    _write.pNext            = nullptr;
    _write.dstSet           = dstSet->getRaw(dstSetIndex);
    _write.dstBinding       = dstBinding;
    _write.dstArrayElement  = dstArrayElement;
    _write.descriptorCount  = _bufferInfos.size();
    _write.descriptorType   = descriptorType;
    _write.pImageInfo       = nullptr;
    _write.pBufferInfo      = (_bufferInfos.size() == 0) ? nullptr : _bufferInfos.data();
    _write.pTexelBufferView = nullptr;
}

vk::WriteDescriptorSet::WriteDescriptorSet(DescriptorSetPtr           dstSet,
                   uint32_t                   dstSetIndex,
                   uint32_t                   dstBinding,
                   uint32_t                   dstArrayElement,
                   VkDescriptorType           descriptorType,
                   const std::vector<BufferViewPtr>&              bufferViews)
{
    _bufferViews.reserve(bufferViews.size());
    for (BufferViewPtr bufferView : bufferViews)
    {
        _bufferViews.push_back(bufferView->getRaw());
    }

    _write.sType            = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    _write.pNext            = nullptr;
    _write.dstSet           = dstSet->getRaw(dstSetIndex);
    _write.dstBinding       = dstBinding;
    _write.dstArrayElement  = dstArrayElement;
    _write.descriptorCount  = bufferViews.size();
    _write.descriptorType   = descriptorType;
    _write.pImageInfo       = nullptr;
    _write.pBufferInfo      = nullptr;
    _write.pTexelBufferView = (_bufferViews.size() == 0) ? nullptr : _bufferViews.data();
}

void vk::WriteDescriptorSet::updateDescriptorSets(DevicePtr device, CopyDescriptorSetPtr copySet)
{
    vkUpdateDescriptorSets(device->getRaw(), 1, &_write, ((copySet == nullptr) ? 0: 1) , copySet->getRaw());
}

void vk::WriteDescriptorSets::updateDescriptorSets(DevicePtr device, const CopyDescriptorSets& copySets)
{
    const std::vector<VkWriteDescriptorSet> writeSets(getRaw());
    const std::vector<VkCopyDescriptorSet> copySetsRaw(copySets.getRaw());
    vkUpdateDescriptorSets(device->getRaw(),
        writeSets.size(), ((writeSets.size() == 0) ? nullptr : writeSets.data()),
        copySetsRaw.size(), ((copySetsRaw.size() == 0) ? nullptr : copySetsRaw.data()));
}

const std::vector<VkWriteDescriptorSet> vk::WriteDescriptorSets::getRaw(void) const
{
    std::vector<VkWriteDescriptorSet> result(size());
    for (WriteDescriptorSetPtr set : *this)
    {
        result.push_back(*set->getRaw());
    }

    return result;
}
