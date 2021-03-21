#include "vkSubmitInfo.h"
#include <assert.h>

vk::SubmitInfo::SubmitInfo(const std::vector<SemaphorePtr>& pWaitSemaphores,
    const std::vector<VkPipelineStageFlags>& pWaitDstStageMask,
    const std::vector<CommandBufferPtr>& pCommandBuffers,
    const std::vector<SemaphorePtr>& pSignalSemaphores) : _waitDstStageMask(pWaitDstStageMask)
{
    _waitSemaphores.reserve(pWaitSemaphores.size());
    for (SemaphorePtr semaphore : pWaitSemaphores)
    {
        _waitSemaphores.push_back(semaphore->getRaw());
    }

    _commandBuffers.reserve(pCommandBuffers.size());
    for (CommandBufferPtr cmdBuffer : pCommandBuffers)
    {
        _commandBuffers.push_back(cmdBuffer->getRaw());
    }

    _signalSemaphores.reserve(pSignalSemaphores.size());
    for (SemaphorePtr semaphore : pSignalSemaphores)
    {
        _signalSemaphores.push_back(semaphore->getRaw());
    }

    _info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    _info.pNext                = NULL;

    _info.waitSemaphoreCount   = _waitSemaphores.size();
    _info.pWaitSemaphores      = ((_waitSemaphores.size() == 0) ? nullptr : _waitSemaphores.data());
    _info.pWaitDstStageMask    = ((_waitDstStageMask.size() == 0) ? nullptr : _waitDstStageMask.data());
    _info.commandBufferCount   = _commandBuffers.size();
    _info.pCommandBuffers      = ((_commandBuffers.size() == 0) ? nullptr : _commandBuffers.data());
    _info.signalSemaphoreCount = _signalSemaphores.size();
    _info.pSignalSemaphores    = ((_signalSemaphores.size() == 0) ? nullptr : _signalSemaphores.data());
}
