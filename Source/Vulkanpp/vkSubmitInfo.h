#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

#include "vkSemaphore.h"
#include "vkCommandBuffer.h"

namespace vk
{

class SubmitInfo
{
public:
	SubmitInfo(const std::vector<SemaphorePtr>&         pWaitSemaphores,
               const std::vector<VkPipelineStageFlags>& pWaitDstStageMask,
               const std::vector<CommandBufferPtr>&     pCommandBuffers,
               const std::vector<SemaphorePtr>&         pSignalSemaphores);

    VkSubmitInfo* getRaw(void)
    {
        return &_info;
    }

    const VkSubmitInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkSubmitInfo _info;
    std::vector<VkSemaphore>          _waitSemaphores;
    std::vector<VkPipelineStageFlags> _waitDstStageMask;
    std::vector<VkCommandBuffer>      _commandBuffers;
    std::vector<VkSemaphore>          _signalSemaphores;
};

typedef std::shared_ptr<SubmitInfo> SubmitInfoPtr; 

};

