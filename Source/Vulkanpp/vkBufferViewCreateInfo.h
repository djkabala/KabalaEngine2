#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>
#include "vkBuffer.h"

namespace vk
{

class BufferViewCreateInfo
{
public:
	BufferViewCreateInfo(VkBufferViewCreateFlags    flags,
                         BufferPtr                  buffer,
                         VkFormat                   format,
                         VkDeviceSize               offset,
                         VkDeviceSize               range);

	~BufferViewCreateInfo();

	inline VkBufferViewCreateInfo* getRaw(void) {return &_info;}

	inline const VkBufferViewCreateInfo* getRaw(void) const {return &_info;}
protected:
	VkBufferViewCreateInfo _info;
};

typedef std::shared_ptr<BufferViewCreateInfo> BufferViewCreateInfoPtr; 
};
