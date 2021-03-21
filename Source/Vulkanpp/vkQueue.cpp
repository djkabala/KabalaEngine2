#include "vkQueue.h"
#include <assert.h>

vk::Queue::Queue(VkQueue queue) : _queue(queue)
{

}
void vk::Queue::queueSubmit(const std::vector<VkSubmitInfo> submits, FencePtr cmdFence)
{
    VkResult res = vkQueueSubmit(_queue, submits.size(), ((submits.size() == 0) ? nullptr : submits.data()), cmdFence->getRaw());

    if (res != VK_SUCCESS)
    {
        throw res;
    }

}

void vk::Queue::queueSubmit(SubmitInfoPtr submit, FencePtr cmdFence)
{
    assert(submit != nullptr);

    VkResult res = vkQueueSubmit(_queue, 1, submit->getRaw(), (cmdFence == nullptr) ? nullptr : cmdFence->getRaw());

    if (res != VK_SUCCESS)
    {
        throw res;
    }
}

void vk::Queue::queuePresentKHR(PresentInfoKHRPtr presentInfo)
{
    VkResult res = vkQueuePresentKHR(_queue, presentInfo->getRaw());

    if (res != VK_SUCCESS)
    {
        throw res;
    }
}
