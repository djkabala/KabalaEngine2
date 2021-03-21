#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

namespace vk
{

class BufferCreateInfo
{
public:
	BufferCreateInfo(VkBufferCreateFlags    flags,
                     VkDeviceSize           size,
                     VkBufferUsageFlags     usage,
                     VkSharingMode          sharingMode,
                     const std::vector<uint32_t>& queueFamilyIndices);

	inline VkBufferCreateInfo* getRaw(void) {return &_info;}

	inline const VkBufferCreateInfo* getRaw(void) const {return &_info;}

protected:
	VkBufferCreateInfo _info;
    const std::vector<uint32_t> _queueFamilyIndices;
};

typedef std::shared_ptr<BufferCreateInfo> BufferCreateInfoPtr; 
};

