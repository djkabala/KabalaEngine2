#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

#include "vkSubmitInfo.h"
#include "vkFence.h"
#include "vkPresentInfoKHR.h"

namespace vk
{

class Queue
{
public:

	inline VkQueue* getRaw(void) {return &_queue;}

	inline const VkQueue* getRaw(void) const {return &_queue;}


    void queueSubmit(SubmitInfoPtr submit, FencePtr cmdFence);

    void queueSubmit(const std::vector<VkSubmitInfo> submits, FencePtr cmdFence);

    void queuePresentKHR(PresentInfoKHRPtr presentInfo);

    Queue() = delete;
    Queue(const Queue&) = delete;
    Queue(const Queue&&) = delete;
    const Queue& operator=(const Queue&) = delete;
protected:
    friend class Device;

	Queue(VkQueue queue);

	VkQueue _queue;

};

typedef std::shared_ptr<Queue> QueuePtr; 
};

