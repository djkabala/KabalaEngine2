#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

namespace vk
{

class DescriptorPoolCreateInfo
{
public:
	DescriptorPoolCreateInfo(VkDescriptorPoolCreateFlags    flags,
                             uint32_t                       maxSets,
                             const std::vector<VkDescriptorPoolSize>&    poolSizes);

	inline VkDescriptorPoolCreateInfo* getRaw(void) {return &_pool;}

	inline const VkDescriptorPoolCreateInfo* getRaw(void) const {return &_pool;}
protected:
	VkDescriptorPoolCreateInfo _pool;
	const std::vector<VkDescriptorPoolSize> _poolSizes;

};

typedef std::shared_ptr<DescriptorPoolCreateInfo> DescriptorPoolCreateInfoPtr; 
};

