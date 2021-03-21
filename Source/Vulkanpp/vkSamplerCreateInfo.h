#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

namespace vk
{

class SamplerCreateInfo
{
public:
	SamplerCreateInfo(VkSamplerCreateFlags    flags,
                      VkFilter                magFilter,
                      VkFilter                minFilter,
                      VkSamplerMipmapMode     mipmapMode,
                      VkSamplerAddressMode    addressModeU,
                      VkSamplerAddressMode    addressModeV,
                      VkSamplerAddressMode    addressModeW,
                      float                   mipLodBias,
                      VkBool32                anisotropyEnable,
                      float                   maxAnisotropy,
                      VkBool32                compareEnable,
                      VkCompareOp             compareOp,
                      float                   minLod,
                      float                   maxLod,
                      VkBorderColor           borderColor,
                      VkBool32                unnormalizedCoordinates);

	inline VkSamplerCreateInfo* getRaw(void) {return &_info;}

	inline const VkSamplerCreateInfo* getRaw(void) const {return &_info;}
protected:
	VkSamplerCreateInfo _info;
};

typedef std::shared_ptr<SamplerCreateInfo> SamplerCreateInfoPtr; 
};

