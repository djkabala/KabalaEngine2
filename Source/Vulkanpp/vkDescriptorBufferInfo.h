#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "vkBuffer.h"

namespace vk
{

class DescriptorBufferInfo
{
public:
	DescriptorBufferInfo(BufferPtr       buffer,
                         VkDeviceSize    offset,
                         VkDeviceSize    range);

	inline VkDescriptorBufferInfo getRaw(void) {return _info;}

	inline const VkDescriptorBufferInfo getRaw(void) const {return _info;}
protected:
	VkDescriptorBufferInfo _info;
};
typedef std::shared_ptr<DescriptorBufferInfo> DescriptorBufferInfoPtr; 

};

