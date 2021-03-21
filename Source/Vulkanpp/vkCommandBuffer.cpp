#include "vkCommandBuffer.h"
#include <assert.h>

vk::CommandBuffer::CommandBuffer(DevicePtr device, CommandBufferAllocateInfoPtr info) : _device(device), _buffer(nullptr), _commandPool(info->getCommandPool())
{
    VkResult res = vkAllocateCommandBuffers(_device->getRaw(), info->getRaw(), &_buffer);

    if (res != VK_SUCCESS)
    {
        throw res;
    }
}

vk::CommandBuffer::~CommandBuffer()
{
    if (_buffer != nullptr)
    {
		vkFreeCommandBuffers(_device->getRaw(), _commandPool->getRaw(), 1, &_buffer);
    }
}

void vk::CommandBuffer::begin(CommandBufferBeginInfoPtr info)
{
    VkResult res = vkBeginCommandBuffer(_buffer, info->getRaw());

    if (res != VK_SUCCESS)
    {
        throw res;
    }
}

void vk::CommandBuffer::end()
{
    VkResult res = vkEndCommandBuffer(_buffer);

    if (res != VK_SUCCESS)
    {
        throw res;
    }
}

void vk::CommandBuffer::cmdBeginRenderPass(RenderPassBeginInfoPtr renderPassBegin, VkSubpassContents contents)
{
    vkCmdBeginRenderPass(_buffer, renderPassBegin->getRaw(), contents);
}

void vk::CommandBuffer::cmdBindVertexBuffers(uint32_t             firstBinding,
                                              const std::vector<VkBuffer>&                pBuffers,
                                              const std::vector<VkDeviceSize>&            pOffsets)
{
    assert(pBuffers.size() > 0);
    assert(pBuffers.size() == pOffsets.size());
    vkCmdBindVertexBuffers(_buffer,
                           firstBinding,             /* Start Binding */
                           pBuffers.size(),                       /* Binding Count */
                           pBuffers.data(), /* pBuffers */
                           pOffsets.data());                /* pOffsets */
}

void vk::CommandBuffer::cmdBindVertexBuffer(uint32_t                 firstBinding,
                                            BufferPtr               buffer,
                                            VkDeviceSize            offset)
{
    VkBuffer bufferRaw(buffer->getRaw());
    vkCmdBindVertexBuffers(_buffer,
                           firstBinding,
                           1,
                           &bufferRaw,
                           &offset);
}

void vk::CommandBuffer::cmdEndRenderPass()
{
    vkCmdEndRenderPass(_buffer);
}

void vk::CommandBuffer::cmdBindPipeline(VkPipelineBindPoint pipelineBindPoint,
    GraphicsPipelinePtr pipeline)
{
    vkCmdBindPipeline(_buffer, pipelineBindPoint, pipeline->getRaw());

}

void vk::CommandBuffer::cmdBindDescriptorSets(VkPipelineBindPoint                         pipelineBindPoint,
    PipelineLayoutPtr                           layout,
    uint32_t                                    firstSet,
    DescriptorSetPtr                            descriptorSets,
    const std::vector<uint32_t>& dynamicOffsets)
{
    const std::vector<VkDescriptorSet>& descriptorSetsRaw(descriptorSets->getRaw());
    
    vkCmdBindDescriptorSets(_buffer,
                            pipelineBindPoint,
                            layout->getRaw(),
                            firstSet,
                            descriptorSetsRaw.size(),
                            (descriptorSetsRaw.size() == 0) ? nullptr : descriptorSetsRaw.data(),
                            dynamicOffsets.size(),
                            (dynamicOffsets.size() == 0) ? nullptr : dynamicOffsets.data());
}

void vk::CommandBuffer::cmdDraw(uint32_t vertexCount,
                                uint32_t instanceCount,
                                uint32_t firstVertex,
                                uint32_t firstInstance)
{
    vkCmdDraw(_buffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void vk::CommandBuffer::cmdSetViewport(uint32_t                       firstViewport,
    const std::vector<VkViewport>& viewports)
{
    vkCmdSetViewport(_buffer, firstViewport, viewports.size(), (viewports.size() == 0) ? nullptr : viewports.data());
}

void vk::CommandBuffer::cmdSetScissor(uint32_t                       firstViewport,
    const std::vector<VkRect2D>& scissors)
{
    vkCmdSetScissor(_buffer, firstViewport, scissors.size(), (scissors.size() == 0) ? nullptr : scissors.data());
}


