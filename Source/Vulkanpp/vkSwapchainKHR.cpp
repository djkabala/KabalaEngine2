#include "vkSwapchainKHR.h"
#include <assert.h>

vk::SwapchainKHR::SwapchainKHR(SurfaceKHRPtr surface, DevicePtr device, SwapchainCreateInfoKHRPtr info, const VkAllocationCallbacks* pAllocator) : _swapchain(nullptr), _device(device), _createInfo(info), _allocator(pAllocator)
{
    assert(_createInfo->getSurface() == surface->getRaw());
     VkResult res = vkCreateSwapchainKHR(device->getRaw(), _createInfo->getRaw(), pAllocator, &_swapchain);
     if (res != VK_SUCCESS)
     {
         throw res;
     }
     _surface = surface;
}

vk::SwapchainKHR::~SwapchainKHR()
{
    if (_swapchain != nullptr)
    {
        vkDestroySwapchainKHR(_device->getRaw(), _swapchain, _allocator);
    }

}

uint32_t vk::SwapchainKHR::getSwapchainImageCount(void) const
{
    uint32_t numImages(0);
    VkResult res = vkGetSwapchainImagesKHR(_device->getRaw(), _swapchain, &numImages, nullptr);
    if(res != VK_SUCCESS)
    {
        throw res;
    }
    return numImages;
}

std::vector<VkImage> vk::SwapchainKHR::getSwapchainImagesKHR(void) const
{
    uint32_t numImages(0);
    VkResult res = vkGetSwapchainImagesKHR(_device->getRaw(), _swapchain, &numImages, nullptr);
    if(res != VK_SUCCESS)
    {
        throw res;
    }

    std::vector<VkImage> resultList;
    resultList.resize(numImages);
    res = vkGetSwapchainImagesKHR(_device->getRaw(), _swapchain, &numImages, resultList.data());
    if(res != VK_SUCCESS)
    {
        throw res;
    }

    return resultList;
}

void  vk::SwapchainKHR::acquireNextImage(uint64_t timeout, SemaphorePtr semaphore, FencePtr fence, uint32_t* pImageIndex)
{
    VkResult res = vkAcquireNextImageKHR(_device->getRaw(), _swapchain, timeout, ((semaphore == nullptr) ? nullptr : semaphore->getRaw()), ((fence == nullptr) ? nullptr : fence->getRaw()), pImageIndex);

    if(res != VK_SUCCESS)
    {
        throw res;
    }
}
