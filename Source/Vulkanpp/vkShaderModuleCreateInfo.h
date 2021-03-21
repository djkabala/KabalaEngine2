#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

namespace vk
{

class ShaderModuleCreateInfo
{
public:
	ShaderModuleCreateInfo(VkShaderModuleCreateFlags     flags,
                           const std::vector<uint32_t>&  code);

	VkShaderModuleCreateInfo* getRaw(void) { return &_info; }

	const VkShaderModuleCreateInfo* getRaw(void) const { return &_info; }
protected:
	VkShaderModuleCreateInfo _info;
	const std::vector<uint32_t>& _code;
};

typedef std::shared_ptr<class ShaderModuleCreateInfo> ShaderModuleCreateInfoPtr;

};

