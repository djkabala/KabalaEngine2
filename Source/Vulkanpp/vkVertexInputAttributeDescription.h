#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class VertexInputAttributeDescription
{
public:
	VertexInputAttributeDescription(uint32_t    location,
                                    uint32_t    binding,
                                    VkFormat    format,
                                    uint32_t    offset);

    VkVertexInputAttributeDescription getRaw(void)
    {
        return _info;
    }

    const VkVertexInputAttributeDescription getRaw(void) const
    {
        return _info;
    }
protected:
	VkVertexInputAttributeDescription _info;
};

typedef std::shared_ptr<VertexInputAttributeDescription> VertexInputAttributeDescriptionPtr; 

};


