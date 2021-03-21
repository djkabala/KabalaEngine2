#include "vkSamplerCreateInfo.h"
vk::SamplerCreateInfo::SamplerCreateInfo(VkSamplerCreateFlags    flags,
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
                                         VkBool32                unnormalizedCoordinates)
{
    _info.sType                   = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
    _info.pNext                   = nullptr;
    _info.flags                   = flags;
    _info.magFilter               = magFilter;
    _info.minFilter               = minFilter;
    _info.mipmapMode              = mipmapMode;
    _info.addressModeU            = addressModeU;
    _info.addressModeV            = addressModeV;
    _info.addressModeW            = addressModeW;
    _info.mipLodBias              = mipLodBias;
    _info.anisotropyEnable        = anisotropyEnable;
    _info.maxAnisotropy           = maxAnisotropy;         
    _info.compareEnable           = compareEnable;         
    _info.compareOp               = compareOp;             
    _info.minLod                  = minLod;                
    _info.maxLod                  = maxLod;                
    _info.borderColor             = borderColor;
    _info.unnormalizedCoordinates = unnormalizedCoordinates;
}
