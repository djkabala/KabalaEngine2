#pragma once
#include "vkImageCreateInfo.h"
#include <memory>
#include "vkDevice.h"
#include "vkMemoryAllocateInfo.h"

namespace vk
{

class Image
{
public:
	Image(DevicePtr device, ImageCreateInfoPtr pCreateInfo, const VkAllocationCallbacks* pAllocator);

	~Image();

	VkImage getRaw(void) { return _image; }

	const VkImage getRaw(void) const { return _image; }

    VkMemoryRequirements getImageMemoryRequirements(void) const;

	void allocate(MemoryAllocateInfoPtr allocInfo);
	void free(void);

	void bind(const VkDeviceSize offset);

	inline ImageCreateInfoPtr getInfo(void) const { return _createInfo; }

protected:
	VkImage _image;
	ImageCreateInfoPtr _createInfo;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;

	MemoryAllocateInfoPtr _allocInfo;
	VkDeviceMemory _deviceMemory;
};

typedef std::shared_ptr<Image> ImagePtr;

};

