#include "vkInstance.h"

vk::Instance::Instance(InstanceCreateInfoPtr info) : _inst(nullptr), _info(info)
{
    VkResult res = vkCreateInstance(_info->getRaw(), NULL, &_inst);
	if (res != VK_SUCCESS)
	{
		throw res;
	}
}

vk::Instance::~Instance()
{
	if (_inst != nullptr)
	{
		vkDestroyInstance(_inst, NULL);
	}
}

VkResult vk::Instance::create(void)
{
    return vkCreateInstance(_info->getRaw(), NULL, &_inst);
}

bool vk::Instance::isValid(void) const
{
	return _inst != nullptr;
}

std::vector<VkLayerProperties> vk::Instance::GetSupportedLayers(void)
{
	uint32_t numLayers(0);
    vkEnumerateInstanceLayerProperties(&numLayers, nullptr);

    std::vector<VkLayerProperties> availableLayers(numLayers);
    vkEnumerateInstanceLayerProperties(&numLayers, availableLayers.data());

	return availableLayers;
}

std::vector<VkExtensionProperties> vk::Instance::GetSupportedExtensions(const std::string& layerName)
{
	uint32_t numExtensions(0);
    vkEnumerateInstanceExtensionProperties((layerName.empty() ? nullptr : layerName.c_str()), &numExtensions, nullptr);

    std::vector<VkExtensionProperties> availableExtensions(numExtensions);
    vkEnumerateInstanceExtensionProperties((layerName.empty() ? nullptr : layerName.c_str()), &numExtensions, availableExtensions.data());

	return availableExtensions;
}
