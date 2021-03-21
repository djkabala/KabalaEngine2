#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkSemaphore.h"
#include "vkSwapchainKHR.h"

namespace vk
{

class PresentInfoKHR
{
public:
	PresentInfoKHR(const std::vector<SemaphorePtr>&       pWaitSemaphores,
                   const std::vector<SwapchainKHRPtr>&    pSwapchains,
                   const std::vector<uint32_t>&           pImageIndices,
                   const std::vector<VkResult>&           pResults);

    VkPresentInfoKHR* getRaw(void)
    {
        return &_info;
    }

    const VkPresentInfoKHR* getRaw(void) const
    {
        return &_info;
    }

protected:
	VkPresentInfoKHR _info;

    std::vector<VkSemaphore>      _waitSemaphores;
    std::vector<VkSwapchainKHR>   _swapchains;
    std::vector<uint32_t>         _imageIndices;
    std::vector<VkResult>         _results;
};

typedef std::shared_ptr<PresentInfoKHR> PresentInfoKHRPtr; 

};


