#pragma once


#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

#include "vkInstance.h"
#include "vkSurfaceKHR.h"

namespace vk
{
class PhysicalDevice;

class PhysicalDevices
{
public:
	PhysicalDevices(InstancePtr instance);

	uint32_t getNumDevices(void) const;

	PhysicalDevice getDevice(const uint32_t index);

protected:
	friend class PhysicalDevice;
	typedef std::vector<VkPhysicalDevice> VkPhysicalDeviceVectorType;
	VkPhysicalDeviceVectorType _devices;
};

typedef std::shared_ptr<PhysicalDevices> PhysicalDevicesPtr;

class PhysicalDevice
{
public:
	typedef std::vector<VkQueueFamilyProperties> VkQueueFamilyPropertiesVectorType;

	PhysicalDevice(PhysicalDevices* devices, const uint32_t index);

	VkQueueFamilyPropertiesVectorType getFamilyProperties(void) const;

	VkPhysicalDevice getRaw(void) { return (_devices->_devices[_index]); }

	const VkPhysicalDevice getRaw(void) const { return (_devices->_devices[_index]); }

	bool getPhysicalDeviceSurfaceSupportKHR(SurfaceKHRPtr surface, const uint32_t queueFamilyIndex) const;

	std::vector<VkSurfaceFormatKHR> getPhysicalDeviceSurfaceFormatsKHR(SurfaceKHRPtr surface) const;

    VkSurfaceCapabilitiesKHR getPhysicalDeviceSurfaceCapabilitiesKHR(SurfaceKHRPtr surface) const;

	std::vector<VkPresentModeKHR> getPhysicalDeviceSurfacePresentModesKHR(SurfaceKHRPtr surface) const;

    const VkFormatProperties getPhysicalDeviceFormatProperties(const VkFormat format) const;

    bool memoryTypeFromProperties(uint32_t typeBits, VkFlags requirements_mask, uint32_t* typeIndex) const;

protected:
	PhysicalDevices*   _devices;
	const uint32_t     _index;
};

};

