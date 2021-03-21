#include "vkPipelineShaderStageCreateInfo.h"
vk::PipelineShaderStageCreateInfo::PipelineShaderStageCreateInfo(VkPipelineShaderStageCreateFlags    flags,
    VkShaderStageFlagBits               stage,
    ShaderModulePtr                      module,
    const char* pName,
    const VkSpecializationInfo* pSpecializationInfo) : _module(module)
{
    _info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    _info.pNext = NULL;
    _info.pSpecializationInfo = pSpecializationInfo;
    _info.flags = flags;
    _info.stage = stage;
    _info.pName = pName;
    _info.module = _module->getRaw();
}
