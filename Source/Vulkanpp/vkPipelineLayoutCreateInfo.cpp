#include "vkPipelineLayoutCreateInfo.h"
vk::PipelineLayoutCreateInfo::PipelineLayoutCreateInfo(VkPipelineLayoutCreateFlags     flags,
    const std::vector<DescriptorSetLayoutPtr>& setLayouts,
    const std::vector<VkPushConstantRange>& pushConstantRanges)
    :
    _layouts(setLayouts),
    _ranges(pushConstantRanges)

{
    for (DescriptorSetLayoutPtr layout : _layouts)
    {
        _layoutsRaw.push_back(layout->getRaw());
    }

    _info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    _info.pNext = NULL;
    _info.setLayoutCount         = _layoutsRaw.size();
    _info.pSetLayouts            = (_layoutsRaw.size() == 0) ? nullptr : _layoutsRaw.data();
    _info.pushConstantRangeCount = _ranges.size();
    _info.pPushConstantRanges    = (_ranges.size() == 0) ? nullptr : _ranges.data();
}
