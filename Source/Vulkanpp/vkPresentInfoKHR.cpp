#include "vkPresentInfoKHR.h"
#include <assert.h>
vk::PresentInfoKHR::PresentInfoKHR(const std::vector<SemaphorePtr>& waitSemaphores,
                                   const std::vector<SwapchainKHRPtr>& swapchains,
                                   const std::vector<uint32_t>& imageIndices,
                                   const std::vector<VkResult>& results) : _imageIndices(imageIndices), _results(results)
{
    assert(_imageIndices.size() == swapchains.size());
    assert(_results.size() == 0 || _results.size() == swapchains.size());

    _waitSemaphores.reserve(waitSemaphores.size());
    for (SemaphorePtr semaphore : waitSemaphores)
    {
        _waitSemaphores.push_back(semaphore->getRaw());
    }

    _swapchains.reserve(swapchains.size());
    for (SwapchainKHRPtr swapchain : swapchains)
    {
        _swapchains.push_back(swapchain->getRaw());
    }

    _info.sType              = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    _info.pNext              = nullptr;
    _info.swapchainCount     = _swapchains.size();
    _info.pSwapchains        = (_swapchains.size() == 0) ? nullptr : _swapchains.data();
    _info.pImageIndices      = (_imageIndices.size() == 0) ? nullptr : _imageIndices.data();
    _info.waitSemaphoreCount = _waitSemaphores.size();
    _info.pWaitSemaphores    = (_waitSemaphores.size() == 0) ? nullptr : _waitSemaphores.data();
    _info.pResults           = (_results.size() == 0) ? nullptr : _results.data();
}
