#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include "vkDevice.h"
#include "vkCommandBufferAllocateInfo.h"
#include "vkCommandBufferBeginInfo.h"
#include "vkRenderPassBeginInfo.h"
#include "vkBuffer.h"
#include "vkGraphicsPipeline.h"
#include "vkDescriptorSet.h"

namespace vk
{

class CommandBuffer
{
public:
	CommandBuffer(DevicePtr device, CommandBufferAllocateInfoPtr info);

	~CommandBuffer();

    VkCommandBuffer getRaw(void)
    {
        return _buffer;
    }

    const VkCommandBuffer getRaw(void) const
    {
        return _buffer;
    }

    void begin(CommandBufferBeginInfoPtr info);

    void end(void);

    void cmdBeginRenderPass(RenderPassBeginInfoPtr renderPassBegin, VkSubpassContents contents);

    void cmdBindVertexBuffers(uint32_t                                    firstBinding,
                              const std::vector<VkBuffer>&                pBuffers,
                              const std::vector<VkDeviceSize>&            pOffsets);

    void cmdBindVertexBuffer(uint32_t                 firstBinding,
                             BufferPtr               buffers,
                             VkDeviceSize            offset);

    void cmdEndRenderPass();

    void cmdBindPipeline(VkPipelineBindPoint pipelineBindPoint,
                         GraphicsPipelinePtr pipeline);

    void cmdBindDescriptorSets(VkPipelineBindPoint                         pipelineBindPoint,
                               PipelineLayoutPtr                           layout,
                               uint32_t                                    firstSet,
                               DescriptorSetPtr                            descriptorSets,
                               const std::vector<uint32_t>&                dynamicOffsets);

    void cmdDraw(uint32_t vertexCount,
                 uint32_t instanceCount,
                 uint32_t firstVertex,
                 uint32_t firstInstance);

    void cmdSetViewport(uint32_t                       firstViewport,
                        const std::vector<VkViewport>& viewports);

    void cmdSetScissor(uint32_t                       firstViewport,
                       const std::vector<VkRect2D>&   scissors);

protected:
	VkCommandBuffer _buffer;
	DevicePtr _device;
	CommandPoolPtr _commandPool;
};

typedef std::shared_ptr<CommandBuffer> CommandBufferPtr; 

};

