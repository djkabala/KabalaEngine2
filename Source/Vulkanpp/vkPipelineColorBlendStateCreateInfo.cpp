#include "vkPipelineColorBlendStateCreateInfo.h"
vk::PipelineColorBlendStateCreateInfo::PipelineColorBlendStateCreateInfo(VkPipelineColorBlendStateCreateFlags          flags,
    VkBool32                                      logicOpEnable,
    VkLogicOp                                     logicOp,
    const std::vector<PipelineColorBlendAttachmentStatePtr>& attachments,
    float                                         blendConstants[4])
{
    for (PipelineColorBlendAttachmentStatePtr attachment : attachments)
    {
        _attachments.push_back(attachment->getRaw());
    }

	_info.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	_info.pNext = nullptr;
	_info.flags = flags;
    _info.logicOpEnable = logicOpEnable;
    _info.logicOp = logicOp;
    _info.blendConstants[0] = blendConstants[0];
    _info.blendConstants[1] = blendConstants[1];
    _info.blendConstants[2] = blendConstants[2];
    _info.blendConstants[3] = blendConstants[3];
    _info.attachmentCount = _attachments.size();
    _info.pAttachments = ((_attachments.size() == 0) ? nullptr : _attachments.data());
}
