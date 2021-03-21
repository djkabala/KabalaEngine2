#include "vkDescriptorSetAllocateInfo.h"

vk::DescriptorSetAllocateInfo::DescriptorSetAllocateInfo(DescriptorPoolPtr                descriptorPool,
    const std::vector<DescriptorSetLayoutPtr>& setLayouts) : _descriptorPool(descriptorPool), _setLayouts(setLayouts)
{
    _setLayoutsRaw.reserve(_setLayouts.size());
    for (DescriptorSetLayoutPtr layout : _setLayouts)
    {
        _setLayoutsRaw.push_back(layout->getRaw());
    }

    _info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    _info.pNext = NULL;
    _info.descriptorPool = descriptorPool->getRaw();
    _info.descriptorSetCount = _setLayoutsRaw.size();
    _info.pSetLayouts = (_setLayoutsRaw.size() == 0) ? nullptr : _setLayoutsRaw.data();
}
