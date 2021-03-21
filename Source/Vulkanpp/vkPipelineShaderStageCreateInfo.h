#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "vkShaderModule.h"

namespace vk
{

class PipelineShaderStageCreateInfo
{
public:
	PipelineShaderStageCreateInfo(VkPipelineShaderStageCreateFlags    flags,
                                  VkShaderStageFlagBits               stage,
                                  ShaderModulePtr                     module,
                                  const char*                         pName,
                                  const VkSpecializationInfo*         pSpecializationInfo);

	VkPipelineShaderStageCreateInfo getRaw(void) { return _info; }

	const VkPipelineShaderStageCreateInfo getRaw(void) const { return _info; }
protected:
	VkPipelineShaderStageCreateInfo _info;
    ShaderModulePtr                 _module;
};

typedef std::shared_ptr<class PipelineShaderStageCreateInfo> PipelineShaderStageCreateInfoPtr;

};

