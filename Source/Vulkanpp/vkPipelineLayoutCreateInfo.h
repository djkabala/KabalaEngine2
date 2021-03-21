#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

#include "vkDescriptorSetLayout.h"

namespace vk
{

class PipelineLayoutCreateInfo
{
public:
	PipelineLayoutCreateInfo(VkPipelineLayoutCreateFlags     flags,
                             const std::vector<DescriptorSetLayoutPtr>&    setLayouts,
                             const std::vector<VkPushConstantRange>&      pushConstantRanges);

	inline VkPipelineLayoutCreateInfo* getRaw(void) {return &_info;}

	inline const VkPipelineLayoutCreateInfo* getRaw(void) const {return &_info;}

    inline const std::vector<DescriptorSetLayoutPtr>& getDescriptorSetLayouts(void) const { return _layouts; }
protected:
	VkPipelineLayoutCreateInfo _info;

    std::vector<DescriptorSetLayoutPtr> _layouts;
    std::vector<VkDescriptorSetLayout> _layoutsRaw;
    std::vector<VkPushConstantRange>   _ranges;

};

typedef std::shared_ptr<PipelineLayoutCreateInfo> PipelineLayoutCreateInfoPtr; 
};

