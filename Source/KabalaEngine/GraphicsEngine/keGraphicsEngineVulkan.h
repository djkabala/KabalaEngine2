#pragma once
#include "keGraphicsEngine.h"

#include <Vulkanpp/vkInstance.h>
#include <Vulkanpp/vkDevice.h>
#include <Vulkanpp/vkDeviceQueueCreateInfo.h>
#include <Vulkanpp/vkCommandPoolCreateInfo.h>
#include <Vulkanpp/vkCommandPool.h>
#include <Vulkanpp/vkCommandBufferAllocateInfo.h>
#include <Vulkanpp/vkCommandBuffer.h>
#include <Vulkanpp/vkWindow.h>
#include <Vulkanpp/vkSurfaceCreateInfo.h>
#include <Vulkanpp/vkSurfaceKHR.h>
#include <Vulkanpp/vkSwapchainCreateInfoKHR.h>
#include <Vulkanpp/vkSwapchainKHR.h>
#include <Vulkanpp/vkImageView.h>
#include <Vulkanpp/vkImage.h>
#include <Vulkanpp/vkBuffer.h>
#include <Vulkanpp/vkDescriptorSetLayout.h>
#include <Vulkanpp/vkPipelineLayout.h>
#include <Vulkanpp/vkDescriptorSet.h>
#include <Vulkanpp/vkDescriptorImageInfo.h>
#include <Vulkanpp/vkWriteDescriptorSet.h>

#include <Vulkanpp/vkSubpassDescription.h>
#include <Vulkanpp/vkSubpassDependency.h>
#include <Vulkanpp/vkAttachmentDescription.h>
#include <Vulkanpp/vkRenderPass.h>

#include <Vulkanpp/vkShaderModule.h>
#include <Vulkanpp/vkPipelineShaderStageCreateInfo.h>

#include <Vulkanpp/vkFramebuffer.h>
#include <Vulkanpp/vkSubmitInfo.h>
#include <Vulkanpp/vkQueue.h>

#include <Vulkanpp/vkVertexInputBindingDescription.h>
#include <Vulkanpp/vkVertexInputAttributeDescription.h>
#include <Vulkanpp/vkRenderPassBeginInfo.h>

#include <Vulkanpp/vkGraphicsPipeline.h>

#include <Vulkanpp/vkPresentInfoKHR.h>

namespace ke
{

class GraphicsEngineVulkan : public GraphicsEngine 
{
public:
protected:
	vk::InstancePtr _instance;
	vk::DevicePtr   _device;
	vk::SwapchainKHRPtr _swapChain;
	std::vector<vk::ImageViewPtr> _swapImageViews;

};

typedef std::shared_ptr<GraphicsEngineVulkan> GraphicsEngineVulkanPtr;

};

