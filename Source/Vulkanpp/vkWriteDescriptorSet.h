#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>
#include "vkDescriptorSet.h"
#include "vkDescriptorImageInfo.h"
#include "vkDescriptorBufferInfo.h"
#include "vkBufferView.h"
#include "vkDevice.h"
#include "vkCopyDescriptorSet.h"

namespace vk
{

class WriteDescriptorSet
{
public:
	WriteDescriptorSet(DescriptorSetPtr           dstSet,
                       uint32_t                   dstSetIndex,
                       uint32_t                   dstBinding,
                       uint32_t                   dstArrayElement,
                       VkDescriptorType           descriptorType,
                       const std::vector<DescriptorImageInfoPtr>&     imageInfos);

	WriteDescriptorSet(DescriptorSetPtr           dstSet,
                       uint32_t                   dstSetIndex,
                       uint32_t                   dstBinding,
                       uint32_t                   dstArrayElement,
                       VkDescriptorType           descriptorType,
                       const std::vector<DescriptorBufferInfoPtr>&    bufferInfos);

	WriteDescriptorSet(DescriptorSetPtr           dstSet,
                       uint32_t                   dstSetIndex,
                       uint32_t                   dstBinding,
                       uint32_t                   dstArrayElement,
                       VkDescriptorType           descriptorType,
                       const std::vector<BufferViewPtr>&              texelBufferViews);


    void updateDescriptorSets(DevicePtr device, CopyDescriptorSetPtr copySet);

	inline VkWriteDescriptorSet* getRaw(void) {return &_write;}

	inline const VkWriteDescriptorSet* getRaw(void) const {return &_write;}
protected:
	VkWriteDescriptorSet                _write;
    std::vector<VkDescriptorImageInfo>  _imageInfos;
    std::vector<VkDescriptorBufferInfo> _bufferInfos;
    std::vector<VkBufferView>           _bufferViews;

};

typedef std::shared_ptr<WriteDescriptorSet> WriteDescriptorSetPtr; 

class WriteDescriptorSets : public std::vector<WriteDescriptorSetPtr>
{
public:
    void updateDescriptorSets(DevicePtr device, const CopyDescriptorSets& copySets);

    const std::vector<VkWriteDescriptorSet> getRaw(void) const;

protected:
};

};


