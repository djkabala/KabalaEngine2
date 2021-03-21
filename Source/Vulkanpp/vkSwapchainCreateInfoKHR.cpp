#include "vkSwapchainCreateInfoKHR.h"
#include "vkSurfaceKHR.h"

vk::SwapchainCreateInfoKHR::SwapchainCreateInfoKHR(VkSwapchainCreateFlagsKHR        flags,
    SurfaceKHRPtr                   surface,
    uint32_t                         minImageCount,
    VkFormat                         imageFormat,
    VkColorSpaceKHR                  imageColorSpace,
    VkExtent2D                       imageExtent,
    uint32_t                         imageArrayLayers,
    VkImageUsageFlags                imageUsage,
    VkSharingMode                    imageSharingMode,
    const std::vector<uint32_t>&     queueFamilyIndices,
    VkSurfaceTransformFlagBitsKHR    preTransform,
    VkCompositeAlphaFlagBitsKHR      compositeAlpha,
    VkPresentModeKHR                 presentMode,
    VkBool32                         clipped,
    VkSwapchainKHR                   oldSwapchain) : _queueFamilyIndices(queueFamilyIndices)
{
    _info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    _info.pNext = NULL;
    _info.flags = flags;
    _info.surface = surface->getRaw();
    _info.minImageCount = minImageCount;
    _info.imageFormat = imageFormat;
    _info.imageExtent.width = imageExtent.width;
    _info.imageExtent.height = imageExtent.height;
    _info.preTransform = preTransform;
    _info.compositeAlpha = compositeAlpha;
    _info.imageArrayLayers = imageArrayLayers;
    _info.presentMode = presentMode;
    _info.oldSwapchain = oldSwapchain;
    _info.clipped = clipped;
    _info.imageColorSpace = imageColorSpace;
    _info.imageUsage = imageUsage;
    _info.imageSharingMode = imageSharingMode;
    _info.queueFamilyIndexCount = _queueFamilyIndices.size();
    _info.pQueueFamilyIndices = (_queueFamilyIndices.size() == 0 ? nullptr : _queueFamilyIndices.data());
}
