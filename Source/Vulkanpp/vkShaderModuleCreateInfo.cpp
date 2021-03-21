#include "vkShaderModuleCreateInfo.h"

vk::ShaderModuleCreateInfo::ShaderModuleCreateInfo(VkShaderModuleCreateFlags     flags,
                                                   const std::vector<uint32_t>&  code) : _code(code)
{
    _info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = flags;
    _info.codeSize = _code.size() * sizeof(uint32_t);
    _info.pCode = _code.data();
}
