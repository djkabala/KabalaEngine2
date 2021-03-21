#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class VertexInputBindingDescription
{
public:
	VertexInputBindingDescription(uint32_t             binding,
                                  uint32_t             stride,
                                  VkVertexInputRate    inputRate);

    VkVertexInputBindingDescription getRaw(void)
    {
        return _info;
    }

    const VkVertexInputBindingDescription getRaw(void) const
    {
        return _info;
    }
protected:
	VkVertexInputBindingDescription _info;
};

typedef std::shared_ptr<VertexInputBindingDescription> VertexInputBindingDescriptionPtr; 

};

