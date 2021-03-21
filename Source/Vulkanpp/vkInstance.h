#pragma once

#include <vulkan/vulkan.h>
#include <string>
#include "vkInstanceCreateInfo.h"

namespace vk
{

class Instance
{
public:
	Instance(InstanceCreateInfoPtr info);

	~Instance();

	VkResult create(void);

	bool isValid(void) const;
	
    VkInstance getRaw(void)
    {
        return _inst;
    }

    const VkInstance getRaw(void) const
    {
        return _inst;
    }

    static std::vector<VkLayerProperties> GetSupportedLayers(void);
    static std::vector<VkExtensionProperties> GetSupportedExtensions(const std::string& layerName);
protected:

    VkInstance _inst;
	InstanceCreateInfoPtr _info;
};

typedef std::shared_ptr<Instance> InstancePtr;

};

