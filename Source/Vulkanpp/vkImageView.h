#pragma once
#include "vkImageViewCreateInfo.h"
#include <memory>
#include "vkDevice.h"

namespace vk
{

class ImageView
{
public:
	ImageView(DevicePtr device, ImageViewCreateInfoPtr pCreateInfo, const VkAllocationCallbacks* pAllocator);

	~ImageView();

	VkImageView getRaw(void) { return _view; }

	const VkImageView getRaw(void) const { return _view; }
protected:
	VkImageView _view;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<ImageView> ImageViewPtr;

};

