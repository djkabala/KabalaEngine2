#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include <vector>
#include "vkSurfaceKHR.h"

namespace vk
{

class SwapchainCreateInfoKHR
{
public:
	SwapchainCreateInfoKHR(VkSwapchainCreateFlagsKHR        flags,
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
							VkSwapchainKHR                   oldSwapchain);

	VkSwapchainCreateInfoKHR* getRaw(void) { return &_info; }
	const VkSwapchainCreateInfoKHR* getRaw(void) const { return &_info; }

	inline const VkSwapchainCreateFlagsKHR     getFlags                (void) const { return _info.flags; }
	inline const VkSurfaceKHR                  getSurface              (void) const { return _info.surface; }
	inline const uint32_t                      getMinImageCount        (void) const { return _info.minImageCount; }
	inline const VkFormat                      getImageFormat          (void) const { return _info.imageFormat; }
	inline const VkSurfaceTransformFlagBitsKHR getPreTransform         (void) const { return _info.preTransform; }
	inline const VkCompositeAlphaFlagBitsKHR   getCompositeAlpha       (void) const { return _info.compositeAlpha; }
	inline const uint32_t                      getImageArrayLayers     (void) const { return _info.imageArrayLayers; }
	inline const VkPresentModeKHR              getPresentMode          (void) const { return _info.presentMode; }
	inline const VkSwapchainKHR                getOldSwapchain         (void) const { return _info.oldSwapchain; }
	inline const VkBool32                      getClipped              (void) const { return _info.clipped; }
	inline const VkColorSpaceKHR               getImageColorSpace      (void) const { return _info.imageColorSpace; }
	inline const VkExtent2D&                   getExtent               (void) const { return _info.imageExtent; }
	inline const VkImageUsageFlags             getImageUsage           (void) const { return _info.imageUsage; }
	inline const VkSharingMode                 getImageSharingMode     (void) const { return _info.imageSharingMode; }
	inline const uint32_t                      getQueueFamilyIndexCount(void) const { return _info.queueFamilyIndexCount; }
	inline const uint32_t*                     getQueueFamilyIndices   (void) const { return _info.pQueueFamilyIndices; }

protected:
	VkSwapchainCreateInfoKHR _info;
	const std::vector<uint32_t> _queueFamilyIndices;
};

typedef std::shared_ptr<SwapchainCreateInfoKHR> SwapchainCreateInfoKHRPtr;

};

