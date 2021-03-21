#include "vkPipelineInputAssemblyStateCreateInfo.h"
vk::PipelineInputAssemblyStateCreateInfo::PipelineInputAssemblyStateCreateInfo(VkPipelineInputAssemblyStateCreateFlags    flags,
    VkPrimitiveTopology                        topology,
    VkBool32                                   primitiveRestartEnable)
{
    _info.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    _info.pNext = nullptr;
    _info.flags = flags;
    _info.topology = topology;
    _info.primitiveRestartEnable = primitiveRestartEnable;

}
