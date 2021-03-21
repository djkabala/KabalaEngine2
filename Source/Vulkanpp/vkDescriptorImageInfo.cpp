#include "vkDescriptorImageInfo.h"
vk::DescriptorImageInfo::DescriptorImageInfo(SamplerPtr      sampler,
    ImageViewPtr    imageView,
    VkImageLayout   imageLayout)
{
    _info.sampler = sampler->getRaw();
    _info.imageView = imageView->getRaw();
    _info.imageLayout = imageLayout;
}
