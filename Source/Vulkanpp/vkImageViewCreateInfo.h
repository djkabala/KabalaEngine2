#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>
#include "vkImage.h"

namespace vk
{

class ImageViewCreateInfo
{
public:
	ImageViewCreateInfo(VkImageViewCreateFlags     flags,
						VkImage                    image,
						VkImageViewType            viewType,
						VkFormat                   format,
						VkComponentMapping         components,
						VkImageSubresourceRange    subresourceRange);

	ImageViewCreateInfo(VkImageViewCreateFlags     flags,
						ImagePtr                   image,
						VkImageViewType            viewType,
						VkFormat                   format,
						VkComponentMapping         components,
						VkImageSubresourceRange    subresourceRange);

	~ImageViewCreateInfo();

	inline VkImageViewCreateInfo* getRaw(void) {return &_info;}

	inline const VkImageViewCreateInfo* getRaw(void) const {return &_info;}
protected:
	VkImageViewCreateInfo _info;
};

typedef std::shared_ptr<ImageViewCreateInfo> ImageViewCreateInfoPtr; 
};
