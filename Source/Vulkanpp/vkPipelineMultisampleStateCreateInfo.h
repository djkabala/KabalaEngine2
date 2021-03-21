#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class PipelineMultisampleStateCreateInfo
{
public:
	PipelineMultisampleStateCreateInfo(VkPipelineMultisampleStateCreateFlags    flags,
                                       VkSampleCountFlagBits                    rasterizationSamples,
                                       VkBool32                                 sampleShadingEnable,
                                       float                                    minSampleShading,
                                       const VkSampleMask*                      pSampleMask,
                                       VkBool32                                 alphaToCoverageEnable,
                                       VkBool32                                 alphaToOneEnable);

    VkPipelineMultisampleStateCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkPipelineMultisampleStateCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkPipelineMultisampleStateCreateInfo _info;
};

typedef std::shared_ptr<PipelineMultisampleStateCreateInfo> PipelineMultisampleStateCreateInfoPtr; 

};

