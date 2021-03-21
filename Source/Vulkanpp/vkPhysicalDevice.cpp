#include "vkPhysicalDevice.h"
#include <assert.h>

vk::PhysicalDevices::PhysicalDevices(InstancePtr instance)
{
    if (instance->isValid())
    {
        uint32_t gpuCount(0);
		VkResult res = vkEnumeratePhysicalDevices(instance->getRaw(), &gpuCount, nullptr);
        if (res != VK_SUCCESS)
        {
            throw res;
        }

		_devices.resize(gpuCount);
		res = vkEnumeratePhysicalDevices(instance->getRaw(), &gpuCount, _devices.data());
        if (res != VK_SUCCESS)
        {
            throw res;
        }
    }
    else
    {
        throw nullptr;
    }
}

uint32_t vk::PhysicalDevices::getNumDevices(void) const
{
    return _devices.size();
}

vk::PhysicalDevice vk::PhysicalDevices::getDevice(const uint32_t index)
{
    assert(index < _devices.size());

    return vk::PhysicalDevice(this, index);
}

vk::PhysicalDevice::PhysicalDevice(PhysicalDevices* devices, const uint32_t index) : _devices(devices), _index(index)
{
}

vk::PhysicalDevice::VkQueueFamilyPropertiesVectorType vk::PhysicalDevice::getFamilyProperties(void) const
{
    vk::PhysicalDevice::VkQueueFamilyPropertiesVectorType familyProperties;

    uint32_t count(0);
    vkGetPhysicalDeviceQueueFamilyProperties(_devices->_devices[_index], &count, nullptr);

    familyProperties.resize(count);
    vkGetPhysicalDeviceQueueFamilyProperties(_devices->_devices[_index], &count, familyProperties.data());

    return familyProperties;
}

bool vk::PhysicalDevice::getPhysicalDeviceSurfaceSupportKHR(SurfaceKHRPtr surface, const uint32_t queueFamilyIndex) const
{
    VkBool32 supportPresent;
	VkResult res = vkGetPhysicalDeviceSurfaceSupportKHR(getRaw(), queueFamilyIndex, surface->getRaw(), &supportPresent);
    if(res != VK_SUCCESS)
    {
        throw res;
    }

    return supportPresent;
}

std::vector<VkSurfaceFormatKHR> vk::PhysicalDevice::getPhysicalDeviceSurfaceFormatsKHR(SurfaceKHRPtr surface) const
{
    uint32_t numFormats(0);
    VkResult res = vkGetPhysicalDeviceSurfaceFormatsKHR(getRaw(), surface->getRaw(), &numFormats, nullptr);
    if(res != VK_SUCCESS)
    {
        throw res;
    }

    std::vector<VkSurfaceFormatKHR> resultList;
    resultList.resize(numFormats);
    res = vkGetPhysicalDeviceSurfaceFormatsKHR(getRaw(), surface->getRaw(), &numFormats, resultList.data());
    if(res != VK_SUCCESS)
    {
        throw res;
    }

    return resultList;
}

VkSurfaceCapabilitiesKHR vk::PhysicalDevice::getPhysicalDeviceSurfaceCapabilitiesKHR(SurfaceKHRPtr surface) const
{
    VkSurfaceCapabilitiesKHR surfCapabilities;
    VkResult res = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(getRaw(), surface->getRaw(), &surfCapabilities);

    if(res != VK_SUCCESS)
    {
        throw res;
    }

    return surfCapabilities;
}

std::vector<VkPresentModeKHR> vk::PhysicalDevice::getPhysicalDeviceSurfacePresentModesKHR(SurfaceKHRPtr surface) const
{
    uint32_t numModes(0);
    VkResult res = vkGetPhysicalDeviceSurfacePresentModesKHR(getRaw(), surface->getRaw(), &numModes, nullptr);
    if(res != VK_SUCCESS)
    {
        throw res;
    }

    std::vector<VkPresentModeKHR> resultList;
    resultList.resize(numModes);
    res = vkGetPhysicalDeviceSurfacePresentModesKHR(getRaw(), surface->getRaw(), &numModes, resultList.data());
    if(res != VK_SUCCESS)
    {
        throw res;
    }

    return resultList;
}

const VkFormatProperties vk::PhysicalDevice::getPhysicalDeviceFormatProperties(const VkFormat format) const
{
    VkFormatProperties props;
    vkGetPhysicalDeviceFormatProperties(getRaw(), format, &props);

    return props;
}

bool vk::PhysicalDevice::memoryTypeFromProperties(uint32_t typeBits, VkFlags requirements_mask, uint32_t* typeIndex) const
{
    VkPhysicalDeviceMemoryProperties memoryProperties;
    vkGetPhysicalDeviceMemoryProperties(getRaw(), &memoryProperties);

    // Search memtypes to find first index with those properties
    for (uint32_t i = 0; i < memoryProperties.memoryTypeCount; i++) {
        if ((typeBits & 1) == 1) {
            // Type is available, does it match user properties?
            if ((memoryProperties.memoryTypes[i].propertyFlags & requirements_mask) == requirements_mask) {
                *typeIndex = i;
                return true;
            }
        }
        typeBits >>= 1;
    }
    // No memory types matched, return failure
    return false;
}
