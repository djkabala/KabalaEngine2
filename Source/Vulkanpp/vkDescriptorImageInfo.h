#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "vkSampler.h"
#include "vkImageView.h"

namespace vk
{

class DescriptorImageInfo
{
public:
	DescriptorImageInfo(SamplerPtr      sampler,
                        ImageViewPtr    imageView,
                        VkImageLayout   imageLayout);

	inline VkDescriptorImageInfo getRaw(void) {return _info;}

	inline const VkDescriptorImageInfo getRaw(void) const {return _info;}
protected:
	VkDescriptorImageInfo _info;
};
typedef std::shared_ptr<DescriptorImageInfo> DescriptorImageInfoPtr; 

};

