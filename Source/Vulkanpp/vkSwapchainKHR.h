#pragma once
#include <memory>
#include "vkDevice.h"
#include "vkSwapchainCreateInfoKHR.h"
#include "vkSurfaceKHR.h"
#include "vkSemaphore.h"
#include "vkFence.h"

namespace vk
{

class SwapchainKHR
{
public:
	SwapchainKHR(SurfaceKHRPtr surface, DevicePtr device, SwapchainCreateInfoKHRPtr pCreateInfo, const VkAllocationCallbacks* pAllocator);

	~SwapchainKHR();

    std::vector<VkImage> getSwapchainImagesKHR(void) const;
    uint32_t getSwapchainImageCount(void) const;

	inline SwapchainCreateInfoKHRPtr getInfo(void) { return _createInfo; }

	inline const SwapchainCreateInfoKHRPtr getInfo(void) const { return _createInfo; }

    VkSwapchainKHR getRaw(void)
    {
        return _swapchain;
    }

    const VkSwapchainKHR getRaw(void) const
    {
        return _swapchain;
    }

    SwapchainKHR() = delete;
    SwapchainKHR(const SwapchainKHR&) = delete;
    SwapchainKHR(const SwapchainKHR&&) = delete;
    const SwapchainKHR& operator=(const SwapchainKHR&) = delete;

    void acquireNextImage(uint64_t timeout, SemaphorePtr semaphore, FencePtr fence, uint32_t* pImageIndex);
protected:

	VkSwapchainKHR _swapchain;
	SwapchainCreateInfoKHRPtr _createInfo;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
	SurfaceKHRPtr _surface;
};

typedef std::shared_ptr<SwapchainKHR> SwapchainKHRPtr;

};

