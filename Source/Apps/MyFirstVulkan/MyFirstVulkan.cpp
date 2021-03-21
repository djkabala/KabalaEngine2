// MyFirstVulkan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <assert.h>

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

#include "cube_data.h"
struct Matrix44f
{
	float _values[16];

	Matrix44f()
	{
		//_values[0] = 1.0f;
		//_values[1] = 0.0f;
		//_values[2] = 0.0f;
		//_values[3] = 0.0f;

		//_values[4] = 0.0f;
		//_values[5] = 1.0f;
		//_values[6] = 0.0f;
		//_values[7] = 0.0f;

		//_values[8] = 0.0f;
		//_values[9] = 0.0f;
		//_values[10] = 1.0f;
		//_values[11] = 0.0f;

		//_values[12] = 0.0f;
		//_values[13] = 0.0f;
		//_values[14] = 0.0f;
		//_values[15] = 1.0f;

		_values[0] = 2.15933800f;
		_values[1] = 0.279807597f;
		_values[2] = 0.432366610f;
		_values[3] = 0.431934237f;

		_values[4] = 0.00000000f;
		_values[5] = 2.33173013f;
		_values[6] = -0.259419948f;
		_values[7] = -0.259160519f;

		_values[8]  = -1.07966900f;
		_values[9]  = 0.559615195f;
		_values[10] = 0.864733219f;
		_values[11] = 0.863868475f;

		_values[12] = 0.00000000f;
		_values[13] = 0.00000000f;
		_values[14] = 11.4873247f;
		_values[15] = 11.5758381f;
	}
};

struct MainVulkanObjects
{
	vk::InstancePtr _instance;
	vk::DevicePtr   _device;
	vk::SwapchainKHRPtr _swapChain;
	std::vector<vk::ImageViewPtr> _swapImageViews;
	vk::ImagePtr _depthImage;
	vk::ImageViewPtr _depthImageView;

	vk::PipelineLayoutPtr _pipelineLayout;
	vk::BufferPtr _vertexBuffer;
	vk::DescriptorSetPtr _descriptorSet;

    vk::QueuePtr _graphicsQueue;
    vk::QueuePtr _presentQueue;

    std::vector<vk::VertexInputBindingDescriptionPtr> _vertexInputBindings;
    std::vector<vk::VertexInputAttributeDescriptionPtr> _vertexInputAttribs;
};

vk::DevicePtr createDevice(const vk::PhysicalDevice&  physicalDevice, uint32_t queueFamilyIndex);
vk::SwapchainKHRPtr createSwapChain(const vk::PhysicalDevice& physicalDevice, vk::SurfaceKHRPtr surface, vk::DevicePtr device, const uint32_t graphicsQueueFamilyIndex, const uint32_t presentQueueFamilyIndex, MainVulkanObjects& mainVulkanObjects);

vk::BufferPtr createMVPBuffer(vk::DevicePtr  device, vk::PhysicalDevice&  physicalDevice, const Matrix44f& matrix);

vk::PipelineLayoutPtr createPipelineLayout(vk::DevicePtr  device);
vk::DescriptorSetPtr createDescriptorSet(vk::DevicePtr  device, const std::vector<vk::DescriptorSetLayoutPtr>& dsetLayouts, const std::vector<vk::DescriptorBufferInfoPtr>& descriptorBufferInfos);

vk::ImagePtr createDepthBuffer(vk::DevicePtr  device, vk::PhysicalDevice&  physicalDevice, vk::SwapchainKHRPtr swapchain);
vk::ImageViewPtr createDepthImageView(vk::DevicePtr  device, vk::ImagePtr  depthImage);

vk::RenderPassPtr createRenderPass(vk::DevicePtr  device, vk::SwapchainKHRPtr swapchain, vk::ImagePtr depthImageView);

std::vector<vk::PipelineShaderStageCreateInfoPtr> createShaders(vk::DevicePtr  device);

std::vector<vk::FramebufferPtr> createFramebuffers(vk::DevicePtr  device, vk::RenderPassPtr renderPass, vk::SwapchainKHRPtr swapchain, const MainVulkanObjects & mainVulkanObjects, vk::CommandBufferPtr commandBuffer);

vk::BufferPtr createVertexBuffer(vk::DevicePtr device, const vk::PhysicalDevice& physicalDevice, vk::SwapchainKHRPtr swapchain, vk::RenderPassPtr renderpass, std::vector<vk::FramebufferPtr>& frameBuffers, vk::CommandBufferPtr commandBuffer, MainVulkanObjects& mainVulkanObjects);

vk::GraphicsPipelinePtr createGraphicsPipeline(vk::DevicePtr device, vk::RenderPassPtr rendrePass, std::vector<vk::PipelineShaderStageCreateInfoPtr>& shaderStages, MainVulkanObjects& mainVulkanObjects);

void presentDraw(vk::DevicePtr device,
    vk::SwapchainKHRPtr swapchain,
    vk::RenderPassPtr renderpass,
    std::vector<vk::FramebufferPtr>& frameBuffers,
    vk::CommandBufferPtr commandBuffer,
    vk::GraphicsPipelinePtr graphicsPipeline,
    MainVulkanObjects& mainVulkanObjects);

int main(int argc, char* argv[])
{
    {
		MainVulkanObjects mainVulkanObjects;

        std::vector<VkLayerProperties> supportedLayers(vk::Instance::GetSupportedLayers());
        std::vector<VkExtensionProperties> supportedExtensions(vk::Instance::GetSupportedExtensions(""));

        vk::ApplicationInfoPtr    appInfo(new vk::ApplicationInfo("My First Vulkan App", 0x1, "My First Vulkan Engine", 0x1, VK_API_VERSION_1_0));
        std::vector<const char*> enabledExtensions;
		enabledExtensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
#ifdef WIN32
		enabledExtensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
#endif
        std::vector<const char*> enabledLayers;
        enabledLayers.push_back("VK_LAYER_KHRONOS_validation");
        vk::InstanceCreateInfoPtr instInfo(new vk::InstanceCreateInfo(0x0, appInfo, enabledExtensions, enabledLayers));

        vk::InstancePtr instance(new vk::Instance(instInfo));
		mainVulkanObjects._instance = instance;

        vk::PhysicalDevices physicalDevices(instance);

        if (physicalDevices.getNumDevices() > 0)
        {
			vk::PhysicalDevice  physicalDevice(physicalDevices.getDevice(0));
            vk::PhysicalDevice::VkQueueFamilyPropertiesVectorType familyProperties = physicalDevice.getFamilyProperties();


			//Window
			vk::WindowPtr window = vk::Window::Create(std::wstring(L"My First Vulkan Window Class"), std::wstring(L"My First Vulkan"), 0, 0, 500, 500);


			//Surface
			vk::SurfaceCreateInfoPtr surfaceCreateInfo = vk::SurfaceCreateInfo::Create(window);
			vk::SurfaceKHRPtr surface(new vk::SurfaceKHR(instance, surfaceCreateInfo, nullptr));

			//Find a device that supports graphics and present
			bool found(false);
            uint32_t queueFamilyIndex(0xFFFFFFFF);
			uint32_t graphicsQueueFamilyIndex(0xFFFFFFFF);
			uint32_t presentQueueFamilyIndex(0xFFFFFFFF);
			for (uint32_t i(0) ; i<familyProperties.size() ; ++i)
            {
				if ((familyProperties[i].queueFlags & VK_QUEUE_GRAPHICS_BIT ) &&
					physicalDevice.getPhysicalDeviceSurfaceSupportKHR(surface, i))
                {
					queueFamilyIndex = i;
					graphicsQueueFamilyIndex = i;
					presentQueueFamilyIndex = i;
					found = true;
					break;
				}
			}

            if (found)
            {
				//Create device
				vk::DevicePtr device = createDevice(physicalDevice, queueFamilyIndex);
				mainVulkanObjects._device = device;

				//Get the queues
                mainVulkanObjects._graphicsQueue = device->getDeviceQueue(graphicsQueueFamilyIndex, 0);
                mainVulkanObjects._presentQueue = device->getDeviceQueue(presentQueueFamilyIndex, 0);

				//Create swap chain
				vk::SwapchainKHRPtr swapchain = createSwapChain(physicalDevice, surface, device, graphicsQueueFamilyIndex, presentQueueFamilyIndex, mainVulkanObjects);

				//Create depth image
				mainVulkanObjects._depthImage = createDepthBuffer(device, physicalDevice, swapchain);
                mainVulkanObjects._depthImageView = createDepthImageView(device, mainVulkanObjects._depthImage);

				/* Create a command pool to allocate our command buffer from */
				vk::CommandPoolCreateInfoPtr cmdPoolInfo(new vk::CommandPoolCreateInfo(0x0, queueFamilyIndex));

				vk::CommandPoolPtr cmdPool(new vk::CommandPool(device, cmdPoolInfo, nullptr));

				/* Create the command buffer from the command pool */
				vk::CommandBufferAllocateInfoPtr cmdBufferInfo(new vk::CommandBufferAllocateInfo(cmdPool, VK_COMMAND_BUFFER_LEVEL_PRIMARY, 1));

				vk::CommandBufferPtr commandBuffer(new vk::CommandBuffer(device, cmdBufferInfo));

                //Create Mvp buffer, pipeline layout, and descriptor set
                Matrix44f mvpMatrix;
                vk::BufferPtr mvpBuffer = createMVPBuffer(device, physicalDevice, mvpMatrix);

                mainVulkanObjects._pipelineLayout = createPipelineLayout(device);

                //vk::DescriptorImageInfoPtr textureSamplerBufferInfo(new vk::DescriptorImageInfo(mvpBuffer, 0, sizeof(mvpMatrix)));
                //std::vector<vk::DescriptorImageInfoPtr> imageInfos;
                //imageInfos.push_back(textureSamplerBufferInfo);

                vk::DescriptorBufferInfoPtr mvpBufferInfo(new vk::DescriptorBufferInfo(mvpBuffer, 0, sizeof(mvpMatrix)));
                std::vector<vk::DescriptorBufferInfoPtr> descBufferViews;
                descBufferViews.push_back(mvpBufferInfo);
                mainVulkanObjects._descriptorSet = createDescriptorSet(device, mainVulkanObjects._pipelineLayout->getDescriptorSetLayouts(), descBufferViews);

				vk::RenderPassPtr renderPass = createRenderPass(device, swapchain, mainVulkanObjects._depthImage);

				std::vector<vk::PipelineShaderStageCreateInfoPtr> shaderStages(createShaders(device));

                //Begin command buffer
                {
                    vk::CommandBufferBeginInfoPtr beginInfo(new vk::CommandBufferBeginInfo(0, nullptr));

                    commandBuffer->begin(beginInfo);
                }

				std::vector<vk::FramebufferPtr> framebuffers = createFramebuffers(device, renderPass, swapchain, mainVulkanObjects, commandBuffer);

                mainVulkanObjects._vertexBuffer = createVertexBuffer(device, physicalDevice, swapchain, renderPass, framebuffers, commandBuffer, mainVulkanObjects);

                vk::GraphicsPipelinePtr graphicsPipeline = createGraphicsPipeline(device, renderPass, shaderStages, mainVulkanObjects);

                presentDraw(device, swapchain, renderPass, framebuffers, commandBuffer, graphicsPipeline, mainVulkanObjects);

                //End command buffer
                //{
                //    commandBuffer->end();
                //}
                ////Execute queue
                //{
                //    /* Queue the command buffer for execution */
                //    vk::FenceCreateInfoPtr fenceInfo(new vk::FenceCreateInfo(0x0));
                //    vk::FencePtr drawFence(new vk::Fence(device, fenceInfo, nullptr));

                //    std::vector<VkPipelineStageFlags> pipeStageFlags;
                //    pipeStageFlags.push_back(VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT);

                //    std::vector<vk::SemaphorePtr> emptySemaphores;
                //    std::vector<vk::CommandBufferPtr> commandBuffers;
                //    commandBuffers.push_back(commandBuffer);

                //    vk::SubmitInfoPtr submitInfo(new vk::SubmitInfo(emptySemaphores, pipeStageFlags, commandBuffers, emptySemaphores));

                //    mainVulkanObjects._graphicsQueue->queueSubmit(submitInfo, drawFence);

                //    /* Amount of time, in nanoseconds, to wait for a command buffer to complete */
                //    uint64_t cmdBufferFenceTimeout = 100000000;
                //    VkResult res;
                //    do {
                //        res = device->waitForFence(drawFence, VK_TRUE, cmdBufferFenceTimeout);
                //    } while (res == VK_TIMEOUT);
                //}
            }
        }
    }

    return 0;
}

vk::SwapchainKHRPtr createSwapChain(const vk::PhysicalDevice& physicalDevice, vk::SurfaceKHRPtr surface, vk::DevicePtr device, const uint32_t graphicsQueueFamilyIndex, const uint32_t presentQueueFamilyIndex, MainVulkanObjects& mainVulkanObjects)
{
	std::vector<VkSurfaceFormatKHR> surfaceFormats = physicalDevice.getPhysicalDeviceSurfaceFormatsKHR(surface);
	// If the format list includes just one entry of VK_FORMAT_UNDEFINED,
	// the surface has no preferred format.  Otherwise, at least one
	// supported format will be returned.
	VkFormat chosenColorFormat;
	if (surfaceFormats.size() == 1 && surfaceFormats[0].format == VK_FORMAT_UNDEFINED)
	{
		chosenColorFormat = VK_FORMAT_B8G8R8A8_UNORM;
	}
	else
	{
		assert(surfaceFormats.size() >= 1);
		chosenColorFormat = surfaceFormats[0].format;
	}

	VkSurfaceCapabilitiesKHR surfaceCapabilities(physicalDevice.getPhysicalDeviceSurfaceCapabilitiesKHR(surface));

	std::vector<VkPresentModeKHR> presentModes = physicalDevice.getPhysicalDeviceSurfacePresentModesKHR(surface);

	VkExtent2D swapchainExtent;
	// width and height are either both 0xFFFFFFFF, or both not 0xFFFFFFFF.
	if (surfaceCapabilities.currentExtent.width == 0xFFFFFFFF) {
		// If the surface size is undefined
	}
	else
	{
		// If the surface size is defined, the swap chain size must match
		swapchainExtent = surfaceCapabilities.currentExtent;
	}

	// The FIFO present mode is guaranteed by the spec to be supported
	VkPresentModeKHR swapchainPresentMode = VK_PRESENT_MODE_FIFO_KHR;
	// Determine the number of VkImage's to use in the swap chain.
	// We need to acquire only 1 presentable image at at time.
	// Asking for minImageCount images ensures that we can acquire
	// 1 presentable image as long as we present it before attempting
	// to acquire another.
	uint32_t desiredNumberOfSwapChainImages = surfaceCapabilities.minImageCount;

	VkSurfaceTransformFlagBitsKHR preTransform;
	if (surfaceCapabilities.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR)
	{
		preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
	}
	else
	{
		preTransform = surfaceCapabilities.currentTransform;
	}

	// Find a supported composite alpha mode - one of these is guaranteed to be set
	VkCompositeAlphaFlagBitsKHR compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	VkCompositeAlphaFlagBitsKHR compositeAlphaFlags[4] = {
		VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
		VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR,
		VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR,
		VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR,
	};
	for (uint32_t i = 0; i < sizeof(compositeAlphaFlags) / sizeof(compositeAlphaFlags[0]); i++)
	{
		if (surfaceCapabilities.supportedCompositeAlpha & compositeAlphaFlags[i])
		{
			compositeAlpha = compositeAlphaFlags[i];
			break;
		}
	}

	std::vector<uint32_t>     queueFamilyIndices;
	VkSharingMode imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
	uint32_t queueFamilyIndexCount = 1;
    if (graphicsQueueFamilyIndex != presentQueueFamilyIndex) {
        // If the graphics and present queues are from different queue families,
        // we either have to explicitly transfer ownership of images between
        // the queues, or we have to create the swapchain with imageSharingMode
        // as VK_SHARING_MODE_CONCURRENT
        imageSharingMode = VK_SHARING_MODE_CONCURRENT;
        queueFamilyIndexCount = 2;
		queueFamilyIndices = {graphicsQueueFamilyIndex, presentQueueFamilyIndex};
    }

	vk::SwapchainCreateInfoKHRPtr swapChainCreateInfo(new vk::SwapchainCreateInfoKHR(0x0,
			surface,
			desiredNumberOfSwapChainImages,
			chosenColorFormat,
			VK_COLORSPACE_SRGB_NONLINEAR_KHR,
			swapchainExtent,
			queueFamilyIndexCount,
			VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
			imageSharingMode,
			queueFamilyIndices,
			preTransform,
			compositeAlpha,
			swapchainPresentMode,
			true,
			VK_NULL_HANDLE));

	vk::SwapchainKHRPtr swapchain(new vk::SwapchainKHR(surface, device, swapChainCreateInfo, nullptr));

	std::vector<VkImage> swapImages(swapchain->getSwapchainImagesKHR());
	VkComponentMapping componentMapping;
	VkImageSubresourceRange subresourceRange;
	componentMapping.r = VK_COMPONENT_SWIZZLE_R;
	componentMapping.g = VK_COMPONENT_SWIZZLE_G;
	componentMapping.b = VK_COMPONENT_SWIZZLE_B;
	componentMapping.a = VK_COMPONENT_SWIZZLE_A;
	subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	subresourceRange.baseMipLevel = 0;
	subresourceRange.levelCount = 1;
	subresourceRange.baseArrayLayer = 0;
	subresourceRange.layerCount = 1;

	std::vector<vk::ImageViewPtr> swapImageViews;
	swapImageViews.reserve(swapImages.size());
	for (uint32_t i(0) ; i<swapImages.size() ; ++i)
	{
		vk::ImageViewCreateInfoPtr imageViewCreateInfo(new vk::ImageViewCreateInfo(0x0, swapImages[i], VK_IMAGE_VIEW_TYPE_2D, chosenColorFormat, componentMapping, subresourceRange));
		vk::ImageViewPtr imageView(new vk::ImageView(device, imageViewCreateInfo, nullptr));
		swapImageViews.push_back(imageView);
	}

	mainVulkanObjects._swapChain = swapchain;
	mainVulkanObjects._swapImageViews = swapImageViews;

	return swapchain;
}

vk::DevicePtr createDevice(const vk::PhysicalDevice&  physicalDevice, uint32_t queueFamilyIndex)
{
	vk::DeviceQueueCreateInfoPtr deviceQueueCreateInfo( new vk::DeviceQueueCreateInfo(0x0, queueFamilyIndex, {1.0f}));
	
	std::vector<const VkDeviceQueueCreateInfo*> queueCreateInfos;
	queueCreateInfos.push_back(deviceQueueCreateInfo->getRaw());
	std::vector<const char*> enabledLayerNames;
	std::vector<const char*> enabledExtensionNames;
	enabledExtensionNames.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
	vk::DeviceCreateInfoPtr deviceCreateInfo( new vk::DeviceCreateInfo(queueCreateInfos, enabledLayerNames, enabledExtensionNames, nullptr));

	vk::DevicePtr device(new vk::Device(physicalDevice, deviceCreateInfo, nullptr));

    return device;
}

vk::BufferPtr createMVPBuffer(vk::DevicePtr  device, vk::PhysicalDevice&  physicalDevice, const Matrix44f& matrix)
{
	std::vector<uint32_t> queueFamilyIndices;
	vk::BufferCreateInfoPtr createInfo(new vk::BufferCreateInfo(0x0, sizeof(matrix), VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_SHARING_MODE_EXCLUSIVE, queueFamilyIndices));

	vk::BufferPtr buffer(new vk::Buffer(device, createInfo, nullptr));

	VkMemoryRequirements memReqs = buffer->getBufferMemoryRequirements();
    uint32_t memTypeIndex;
    if (!physicalDevice.memoryTypeFromProperties(memReqs.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &memTypeIndex))
    {
        //Could not find appropriate memory type
        exit(-1);
    }

    vk::MemoryAllocateInfoPtr allocInfo(new vk::MemoryAllocateInfo(memReqs.size, memTypeIndex));
    buffer->allocate(allocInfo);

	uint8_t* data;
	buffer->map(0, memReqs.size, 0x0, reinterpret_cast<void**>(&data));

	//Copy
	memcpy(data, &matrix, sizeof(matrix));

	buffer->unmap();

	buffer->bind(0);

	return buffer;
}

vk::PipelineLayoutPtr createPipelineLayout(vk::DevicePtr  device)
{
	std::vector<vk::DescriptorSetLayoutBindingPtr> bindings;

	vk::DescriptorSetLayoutBindingPtr vertBinding(new vk::DescriptorSetLayoutBinding(0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_VERTEX_BIT, nullptr));
	bindings.push_back(vertBinding);


	//vk::DescriptorSetLayoutBindingPtr fragBinding(new vk::DescriptorSetLayoutBinding(1, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1, VK_SHADER_STAGE_FRAGMENT_BIT, nullptr));
	//bindings.push_back(fragBinding);

	vk::DescriptorSetLayoutCreateInfoPtr dsetCreateInfo(new vk::DescriptorSetLayoutCreateInfo(0x0, bindings));

	vk::DescriptorSetLayoutPtr dsetLayout(new vk::DescriptorSetLayout(device, dsetCreateInfo, nullptr));

	std::vector<vk::DescriptorSetLayoutPtr> dsetLayouts;
	dsetLayouts.push_back(dsetLayout);
	
	std::vector<VkPushConstantRange> ranges;
	vk::PipelineLayoutCreateInfoPtr pipeLayoutCreateInfo(new vk::PipelineLayoutCreateInfo(0x0, dsetLayouts, ranges));
	vk::PipelineLayoutPtr pipelineLayout(new vk::PipelineLayout(device, pipeLayoutCreateInfo, nullptr));

	return pipelineLayout;
}

vk::DescriptorSetPtr createDescriptorSet(vk::DevicePtr  device, const std::vector<vk::DescriptorSetLayoutPtr>& dsetLayouts, const std::vector<vk::DescriptorBufferInfoPtr>& descriptorBufferInfos)
{
	std::vector<VkDescriptorPoolSize> poolSizes;
    VkDescriptorPoolSize uniformBufferPoolSize;
    uniformBufferPoolSize.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    uniformBufferPoolSize.descriptorCount = 1;
	poolSizes.push_back(uniformBufferPoolSize);

 //   VkDescriptorPoolSize imageSamplerPoolSize;
 //   imageSamplerPoolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
 //   imageSamplerPoolSize.descriptorCount = 1;
	//poolSizes.push_back(imageSamplerPoolSize);

    vk::DescriptorPoolCreateInfoPtr poolCreateInfo(new vk::DescriptorPoolCreateInfo(0x0, 1, poolSizes));

    vk::DescriptorPoolPtr descriptorPool(new vk::DescriptorPool(device, poolCreateInfo, nullptr));

    vk::DescriptorSetAllocateInfoPtr allocateInfo(new vk::DescriptorSetAllocateInfo(descriptorPool, dsetLayouts));

    vk::DescriptorSetPtr descriptorSet(new vk::DescriptorSet(device, allocateInfo));

    vk::WriteDescriptorSetPtr uniformBufferWriteSet(new vk::WriteDescriptorSet(descriptorSet, 0, 0, 0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, descriptorBufferInfos));

	uniformBufferWriteSet->updateDescriptorSets(device, nullptr);

    ;
    //vk::WriteDescriptorSetPtr imageSamplerWriteSet(new vk::WriteDescriptorSet(descriptorSet,//dstSet
    //                                                                          0,//dstSetIndex
    //                                                                          1,//dstBinding
    //                                                                          0,//dstArrayElement
    //                                                                          VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,//descriptorType
    //                                                                          imageInfos//bufferInfos
    //    ));


	return descriptorSet;
}

vk::RenderPassPtr createRenderPass(vk::DevicePtr  device, vk::SwapchainKHRPtr swapchain, vk::ImagePtr depthImage)
{
	//vk::SemaphoreCreateInfoPtr semCreateInfo(new vk::SemaphoreCreateInfo(0x0));

	//vk::SemaphorePtr aquireImageSemaphore(new vk::Semaphore(device, semCreateInfo, nullptr));

	//uint32_t imageIndex(0);
	//swapchain->acquireNextImage(uint64_t(0xFFFFFFFF), aquireImageSemaphore, nullptr, &imageIndex);

    vk::AttachmentDescriptionPtr colorAttachmentDesc(new vk::AttachmentDescription(0x0,
		swapchain->getInfo()->getImageFormat(),
		depthImage->getInfo()->getSamples(),
		VK_ATTACHMENT_LOAD_OP_CLEAR,
		VK_ATTACHMENT_STORE_OP_STORE,
		VK_ATTACHMENT_LOAD_OP_DONT_CARE,
		VK_ATTACHMENT_STORE_OP_DONT_CARE,
		VK_IMAGE_LAYOUT_UNDEFINED,
		VK_IMAGE_LAYOUT_PRESENT_SRC_KHR));

    vk::AttachmentDescriptionPtr depthAttachmentDesc(new vk::AttachmentDescription(0x0, depthImage->getInfo()->getFormat(), depthImage->getInfo()->getSamples(), VK_ATTACHMENT_LOAD_OP_CLEAR, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_ATTACHMENT_LOAD_OP_DONT_CARE, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL));

    vk::AttachmentReferencePtr colorReference(new vk::AttachmentReference(0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL));
	std::vector<vk::AttachmentReferencePtr> colorReferences;
	colorReferences.push_back(colorReference);

    vk::AttachmentReferencePtr depthReference(new vk::AttachmentReference(1, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL));

    vk::SubpassDescriptionPtr subpass(new vk::SubpassDescription(0x0,
		VK_PIPELINE_BIND_POINT_GRAPHICS,
		std::vector<vk::AttachmentReferencePtr>(),
		colorReferences,
		std::vector<vk::AttachmentReferencePtr>(),
		depthReference,
		std::vector<uint32_t>()));

    // Subpass dependency to wait for wsi image acquired semaphore before starting layout transition
    vk::SubpassDependencyPtr subpassDependency(new vk::SubpassDependency(VK_SUBPASS_EXTERNAL, 0, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, 0, VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT, 0));


	std::vector<vk::AttachmentDescriptionPtr> attachments;
	attachments.push_back(colorAttachmentDesc);
	attachments.push_back(depthAttachmentDesc);

	std::vector<vk::SubpassDescriptionPtr> subpasses;
	subpasses.push_back(subpass);

	std::vector<vk::SubpassDependencyPtr> dependencies;
	dependencies.push_back(subpassDependency);

    vk::RenderPassCreateInfoPtr rpInfo(new vk::RenderPassCreateInfo(0x0, attachments, subpasses, dependencies));

    vk::RenderPassPtr renderPass(new vk::RenderPass(device, rpInfo, nullptr));

	return renderPass;
}

vk::ImagePtr createDepthBuffer(vk::DevicePtr  device, vk::PhysicalDevice&  physicalDevice, vk::SwapchainKHRPtr swapchain)
{
	//Depth
	const VkFormat depthFormat = VK_FORMAT_D16_UNORM;
	VkFormatProperties props = physicalDevice.getPhysicalDeviceFormatProperties(depthFormat);
	VkImageTiling            depthImageTiling;
	if (props.linearTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT)
	{
		depthImageTiling = VK_IMAGE_TILING_LINEAR;
	}
	else if (props.optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT)
	{
		depthImageTiling = VK_IMAGE_TILING_OPTIMAL;
	}
	else
	{
		/* Try other depth formats? */
		exit(-1);
	}

	VkExtent3D depthExtent;
	depthExtent.width = swapchain->getInfo()->getExtent().width;
	depthExtent.height = swapchain->getInfo()->getExtent().height;
	depthExtent.depth = 1;
	vk::ImageCreateInfoPtr depthImageInfo(new vk::ImageCreateInfo(VK_IMAGE_TYPE_2D,
		depthFormat,
		depthExtent,
		1,
		1,
		VK_SAMPLE_COUNT_1_BIT, //NUM_SAMPLES
		depthImageTiling,
		VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
		VK_SHARING_MODE_EXCLUSIVE,
		std::vector<uint32_t>(),
		VK_IMAGE_LAYOUT_UNDEFINED));

	vk::ImagePtr depthImage(new vk::Image(device, depthImageInfo, nullptr));

	//Allocate the GPU-side memory
	VkMemoryRequirements depthMemReqs = depthImage->getImageMemoryRequirements();
	uint32_t memTypeIndex;
	if (!physicalDevice.memoryTypeFromProperties(depthMemReqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, &memTypeIndex))
	{
		//Could not find appropriate memory type
		exit(-1);
	}
	vk::MemoryAllocateInfoPtr depthAllocInfo(new vk::MemoryAllocateInfo(depthMemReqs.size, memTypeIndex));
	depthImage->allocate(depthAllocInfo);

	//Bind the image memory
	depthImage->bind(0);

	return depthImage;
}

vk::ImageViewPtr createDepthImageView(vk::DevicePtr  device, vk::ImagePtr  depthImage)
{
	//Create an image view of the depth bufer
	VkComponentMapping components;
	VkImageSubresourceRange subresourceRange;
	components.r = VK_COMPONENT_SWIZZLE_R;
	components.g = VK_COMPONENT_SWIZZLE_G;
	components.b = VK_COMPONENT_SWIZZLE_B;
	components.a = VK_COMPONENT_SWIZZLE_A;
	subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
	subresourceRange.baseMipLevel = 0;
	subresourceRange.levelCount = 1;
	subresourceRange.baseArrayLayer = 0;
	subresourceRange.layerCount = 1;

	vk::ImageViewCreateInfoPtr depthViewCreateInfo(new vk::ImageViewCreateInfo(0x0, depthImage, VK_IMAGE_VIEW_TYPE_2D, depthImage->getInfo()->getFormat(), components, subresourceRange));
	vk::ImageViewPtr depthImageView(new vk::ImageView(device, depthViewCreateInfo, nullptr));

	return depthImageView;
}

std::vector<vk::PipelineShaderStageCreateInfoPtr> createShaders(vk::DevicePtr  device)
{
	std::vector<vk::PipelineShaderStageCreateInfoPtr> stages;

	//Vertex
	std::vector<uint32_t> vertCode = {
    0x07230203, 0x00010000, 0x0008000a, 0x00000020,
    0x00000000, 0x00020011, 0x00000001, 0x0006000b,
    0x00000001, 0x4c534c47, 0x6474732e, 0x3035342e,
    0x00000000, 0x0003000e, 0x00000000, 0x00000001,
    0x0009000f, 0x00000000, 0x00000004, 0x6e69616d,
    0x00000000, 0x00000009, 0x0000000b, 0x00000012,
    0x0000001c, 0x00030003, 0x00000002, 0x00000190,
    0x00090004, 0x415f4c47, 0x735f4252, 0x72617065,
    0x5f657461, 0x64616873, 0x6f5f7265, 0x63656a62,
    0x00007374, 0x00090004, 0x415f4c47, 0x735f4252,
    0x69646168, 0x6c5f676e, 0x75676e61, 0x5f656761,
    0x70303234, 0x006b6361, 0x00040005, 0x00000004,
    0x6e69616d, 0x00000000, 0x00050005, 0x00000009,
    0x4374756f, 0x726f6c6f, 0x00000000, 0x00040005,
    0x0000000b, 0x6f436e69, 0x00726f6c, 0x00060005,
    0x00000010, 0x505f6c67, 0x65567265, 0x78657472,
    0x00000000, 0x00060006, 0x00000010, 0x00000000,
    0x505f6c67, 0x7469736f, 0x006e6f69, 0x00070006,
    0x00000010, 0x00000001, 0x505f6c67, 0x746e696f,
    0x657a6953, 0x00000000, 0x00070006, 0x00000010,
    0x00000002, 0x435f6c67, 0x4470696c, 0x61747369,
    0x0065636e, 0x00030005, 0x00000012, 0x00000000,
    0x00050005, 0x00000016, 0x66667562, 0x61567265,
    0x0000736c, 0x00040006, 0x00000016, 0x00000000,
    0x0070766d, 0x00060005, 0x00000018, 0x7542796d,
    0x72656666, 0x736c6156, 0x00000000, 0x00030005,
    0x0000001c, 0x00736f70, 0x00040047, 0x00000009,
    0x0000001e, 0x00000000, 0x00040047, 0x0000000b,
    0x0000001e, 0x00000001, 0x00050048, 0x00000010,
    0x00000000, 0x0000000b, 0x00000000, 0x00050048,
    0x00000010, 0x00000001, 0x0000000b, 0x00000001,
    0x00050048, 0x00000010, 0x00000002, 0x0000000b,
    0x00000003, 0x00030047, 0x00000010, 0x00000002,
    0x00040048, 0x00000016, 0x00000000, 0x00000005,
    0x00050048, 0x00000016, 0x00000000, 0x00000023,
    0x00000000, 0x00050048, 0x00000016, 0x00000000,
    0x00000007, 0x00000010, 0x00030047, 0x00000016,
    0x00000002, 0x00040047, 0x00000018, 0x00000022,
    0x00000000, 0x00040047, 0x00000018, 0x00000021,
    0x00000000, 0x00040047, 0x0000001c, 0x0000001e,
    0x00000000, 0x00020013, 0x00000002, 0x00030021,
    0x00000003, 0x00000002, 0x00030016, 0x00000006,
    0x00000020, 0x00040017, 0x00000007, 0x00000006,
    0x00000004, 0x00040020, 0x00000008, 0x00000003,
    0x00000007, 0x0004003b, 0x00000008, 0x00000009,
    0x00000003, 0x00040020, 0x0000000a, 0x00000001,
    0x00000007, 0x0004003b, 0x0000000a, 0x0000000b,
    0x00000001, 0x00040015, 0x0000000d, 0x00000020,
    0x00000000, 0x0004002b, 0x0000000d, 0x0000000e,
    0x00000001, 0x0004001c, 0x0000000f, 0x00000006,
    0x0000000e, 0x0005001e, 0x00000010, 0x00000007,
    0x00000006, 0x0000000f, 0x00040020, 0x00000011,
    0x00000003, 0x00000010, 0x0004003b, 0x00000011,
    0x00000012, 0x00000003, 0x00040015, 0x00000013,
    0x00000020, 0x00000001, 0x0004002b, 0x00000013,
    0x00000014, 0x00000000, 0x00040018, 0x00000015,
    0x00000007, 0x00000004, 0x0003001e, 0x00000016,
    0x00000015, 0x00040020, 0x00000017, 0x00000002,
    0x00000016, 0x0004003b, 0x00000017, 0x00000018,
    0x00000002, 0x00040020, 0x00000019, 0x00000002,
    0x00000015, 0x0004003b, 0x0000000a, 0x0000001c,
    0x00000001, 0x00050036, 0x00000002, 0x00000004,
    0x00000000, 0x00000003, 0x000200f8, 0x00000005,
    0x0004003d, 0x00000007, 0x0000000c, 0x0000000b,
    0x0003003e, 0x00000009, 0x0000000c, 0x00050041,
    0x00000019, 0x0000001a, 0x00000018, 0x00000014,
    0x0004003d, 0x00000015, 0x0000001b, 0x0000001a,
    0x0004003d, 0x00000007, 0x0000001d, 0x0000001c,
    0x00050091, 0x00000007, 0x0000001e, 0x0000001b,
    0x0000001d, 0x00050041, 0x00000008, 0x0000001f,
    0x00000012, 0x00000014, 0x0003003e, 0x0000001f,
    0x0000001e, 0x000100fd, 0x00010038,
};

    vk::ShaderModuleCreateInfoPtr vertModuleCreateInfo(new vk::ShaderModuleCreateInfo(0x0, vertCode));
    vk::ShaderModulePtr vertModule(new vk::ShaderModule(device, vertModuleCreateInfo, nullptr));

	vk::PipelineShaderStageCreateInfoPtr vertPipelineShaderStageCreateInfo(new vk::PipelineShaderStageCreateInfo(0x0, VK_SHADER_STAGE_VERTEX_BIT, vertModule, "main", nullptr));
	stages.push_back(vertPipelineShaderStageCreateInfo);

	//Fragment
	std::vector<uint32_t> fragCode = {
        0x07230203, 0x00010000, 0x0008000a, 0x0000000d,
        0x00000000, 0x00020011, 0x00000001, 0x0006000b,
        0x00000001, 0x4c534c47, 0x6474732e, 0x3035342e,
        0x00000000, 0x0003000e, 0x00000000, 0x00000001,
        0x0007000f, 0x00000004, 0x00000004, 0x6e69616d,
        0x00000000, 0x00000009, 0x0000000b, 0x00030010,
        0x00000004, 0x00000007, 0x00030003, 0x00000002,
        0x00000190, 0x00090004, 0x415f4c47, 0x735f4252,
        0x72617065, 0x5f657461, 0x64616873, 0x6f5f7265,
        0x63656a62, 0x00007374, 0x00090004, 0x415f4c47,
        0x735f4252, 0x69646168, 0x6c5f676e, 0x75676e61,
        0x5f656761, 0x70303234, 0x006b6361, 0x00040005,
        0x00000004, 0x6e69616d, 0x00000000, 0x00050005,
        0x00000009, 0x4374756f, 0x726f6c6f, 0x00000000,
        0x00040005, 0x0000000b, 0x6f6c6f63, 0x00000072,
        0x00040047, 0x00000009, 0x0000001e, 0x00000000,
        0x00040047, 0x0000000b, 0x0000001e, 0x00000000,
        0x00020013, 0x00000002, 0x00030021, 0x00000003,
        0x00000002, 0x00030016, 0x00000006, 0x00000020,
        0x00040017, 0x00000007, 0x00000006, 0x00000004,
        0x00040020, 0x00000008, 0x00000003, 0x00000007,
        0x0004003b, 0x00000008, 0x00000009, 0x00000003,
        0x00040020, 0x0000000a, 0x00000001, 0x00000007,
        0x0004003b, 0x0000000a, 0x0000000b, 0x00000001,
        0x00050036, 0x00000002, 0x00000004, 0x00000000,
        0x00000003, 0x000200f8, 0x00000005, 0x0004003d,
        0x00000007, 0x0000000c, 0x0000000b, 0x0003003e,
        0x00000009, 0x0000000c, 0x000100fd, 0x00010038,
    };
    vk::ShaderModuleCreateInfoPtr fragModuleCreateInfo(new vk::ShaderModuleCreateInfo(0x0, fragCode));
    vk::ShaderModulePtr fragModule(new vk::ShaderModule(device, fragModuleCreateInfo, nullptr));

	vk::PipelineShaderStageCreateInfoPtr fragPipelineShaderStageCreateInfo(new vk::PipelineShaderStageCreateInfo(0x0, VK_SHADER_STAGE_FRAGMENT_BIT, fragModule, "main", nullptr));
	stages.push_back(fragPipelineShaderStageCreateInfo);

	return stages;
}

std::vector<vk::FramebufferPtr> createFramebuffers(vk::DevicePtr  device, vk::RenderPassPtr renderPass, vk::SwapchainKHRPtr swapchain, const MainVulkanObjects& mainVulkanObjects, vk::CommandBufferPtr commandBuffer)
{

	std::vector<vk::ImageViewPtr> attachments;
	attachments.resize(2);
	attachments[1] = mainVulkanObjects._depthImageView;


	const uint32_t numSwapImages(swapchain->getSwapchainImageCount());
	std::vector<vk::FramebufferPtr> frameBuffers;
	frameBuffers.reserve(numSwapImages);
    for (uint32_t i = 0; i < numSwapImages; i++)
	{
        attachments[0] = mainVulkanObjects._swapImageViews[i];

        vk::FramebufferCreateInfoPtr fbInfo(new vk::FramebufferCreateInfo(0x0, renderPass, attachments, swapchain->getInfo()->getExtent().width, swapchain->getInfo()->getExtent().height, 1));

		vk::FramebufferPtr frameBuffer(new vk::Framebuffer(device, fbInfo, nullptr));

        frameBuffers.push_back(frameBuffer);
    }



	return frameBuffers;
}

vk::BufferPtr createVertexBuffer(vk::DevicePtr device, const vk::PhysicalDevice& physicalDevice, vk::SwapchainKHRPtr swapchain, vk::RenderPassPtr renderpass, std::vector<vk::FramebufferPtr>& frameBuffers, vk::CommandBufferPtr commandBuffer, MainVulkanObjects& mainVulkanObjects)
{
    vk::BufferCreateInfoPtr bufInfo(new vk::BufferCreateInfo(0x0, sizeof(g_vb_solid_face_colors_Data), VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_SHARING_MODE_EXCLUSIVE, std::vector<uint32_t>()));
	vk::BufferPtr vertexBuffer(new vk::Buffer(device, bufInfo, nullptr));

    VkMemoryRequirements vertBufferMemReqs = vertexBuffer->getBufferMemoryRequirements();

	uint32_t memTypeIndex;
	if (!physicalDevice.memoryTypeFromProperties(vertBufferMemReqs.memoryTypeBits, (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT), &memTypeIndex))
	{
		//Could not find appropriate memory type
        assert(false && "No mappable, coherent memory");
		exit(-1);
	}

    vk::MemoryAllocateInfoPtr allocInfo(new vk::MemoryAllocateInfo(vertBufferMemReqs.size, memTypeIndex));

	vertexBuffer->allocate(allocInfo);

    uint8_t *pData;
	vertexBuffer->map(0, vertBufferMemReqs.size, 0x0, (void **)&pData);


    memcpy(pData, g_vb_solid_face_colors_Data, sizeof(g_vb_solid_face_colors_Data));

	vertexBuffer->unmap();

	vertexBuffer->bind(0);

    /* We won't use these here, but we will need this info when creating the
     * pipeline */
    mainVulkanObjects._vertexInputBindings.push_back(vk::VertexInputBindingDescriptionPtr(new vk::VertexInputBindingDescription(0, sizeof(g_vb_solid_face_colors_Data[0]), VK_VERTEX_INPUT_RATE_VERTEX)));

	mainVulkanObjects._vertexInputAttribs.push_back(vk::VertexInputAttributeDescriptionPtr(new vk::VertexInputAttributeDescription(0, 0, VK_FORMAT_R32G32B32A32_SFLOAT, 0)));
	mainVulkanObjects._vertexInputAttribs.push_back(vk::VertexInputAttributeDescriptionPtr(new vk::VertexInputAttributeDescription(1, 0, VK_FORMAT_R32G32B32A32_SFLOAT, 16)));

    const VkDeviceSize offsets[1] = {0};

    /* We cannot bind the vertex buffer until we begin a renderpass */
    std::vector<VkClearValue> clearValues;
	VkClearValue clearColor;
	clearColor.color.float32[0] = 0.2f;
    clearColor.color.float32[1] = 0.2f;
    clearColor.color.float32[2] = 0.2f;
    clearColor.color.float32[3] = 0.2f;
	clearValues.push_back(clearColor);

	VkClearValue clearDepth;
    clearDepth.depthStencil.depth = 1.0f;
    clearDepth.depthStencil.stencil = 0;
	clearValues.push_back(clearDepth);

    //vk::SemaphoreCreateInfoPtr imageAcquiredSemaphoreCreateInfo(new vk::SemaphoreCreateInfo(0x0));
    //vk::SemaphorePtr imageAcquiredSemaphore(new vk::Semaphore(device, imageAcquiredSemaphoreCreateInfo,nullptr));

    // Get the index of the next available swapchain image:
	//uint32_t imageIndex(0);
	//swapchain->acquireNextImage(UINT64_MAX, imageAcquiredSemaphore, VK_NULL_HANDLE, &imageIndex);

    // TODO: Deal with the VK_SUBOPTIMAL_KHR and VK_ERROR_OUT_OF_DATE_KHR
    // return codes
    //assert(res == VK_SUCCESS);

	//VkRect2D renderArea;
 //   renderArea.offset.x = 0;
 //   renderArea.offset.y = 0;
 //   renderArea.extent.width = swapchain->getInfo()->getExtent().width;
 //   renderArea.extent.height = swapchain->getInfo()->getExtent().height;
 //   vk::RenderPassBeginInfoPtr rpBegin(new vk::RenderPassBeginInfo(renderpass, frameBuffers[imageIndex], renderArea, clearValues));

	//commandBuffer->cmdBeginRenderPass(rpBegin, VK_SUBPASS_CONTENTS_INLINE);

	//commandBuffer->cmdBindVertexBuffer(0, vertexBuffer, 0);

	//commandBuffer->cmdEndRenderPass();

	return vertexBuffer;
}

vk::GraphicsPipelinePtr createGraphicsPipeline(vk::DevicePtr device, vk::RenderPassPtr rendrePass, std::vector<vk::PipelineShaderStageCreateInfoPtr>& shaderStages, MainVulkanObjects& mainVulkanObjects)
{
    /* VULKAN_KEY_START */
    std::vector<VkDynamicState> dynamicStateEnables;  // Viewport + Scissor
    dynamicStateEnables.push_back(VK_DYNAMIC_STATE_VIEWPORT);
    dynamicStateEnables.push_back(VK_DYNAMIC_STATE_SCISSOR);

    //The viewport and scissors are dynamic, so the viewports and scissors vectors sent to PipelineViewportStateCreateInfo are empty
    vk::PipelineViewportStateCreateInfoPtr vp(new vk::PipelineViewportStateCreateInfo(0x0,                      //flags
    1,                        //numViewports
    std::vector<VkViewport>(),//viewports
    1,                        //numSissors
    std::vector<VkRect2D>()   //scissors
    ));

    vk::PipelineDynamicStateCreateInfoPtr dynamicState(new vk::PipelineDynamicStateCreateInfo(0x0, dynamicStateEnables));

    vk::PipelineVertexInputStateCreateInfoPtr vi(new vk::PipelineVertexInputStateCreateInfo(0x0, mainVulkanObjects._vertexInputBindings, mainVulkanObjects._vertexInputAttribs));

    vk::PipelineInputAssemblyStateCreateInfoPtr ia(new vk::PipelineInputAssemblyStateCreateInfo(0x0, VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, VK_FALSE));

    vk::PipelineRasterizationStateCreateInfoPtr rs(new vk::PipelineRasterizationStateCreateInfo(0x0,                     //flags
        VK_FALSE,                //depthClampEnable
        VK_FALSE,                //rasterizerDiscardEnable
        VK_POLYGON_MODE_FILL,    //polygonMode
        VK_CULL_MODE_BACK_BIT,   //cullMode
        VK_FRONT_FACE_CLOCKWISE, //frontFace
        VK_FALSE,                //depthBiasEnable
        0,                       //depthBiasConstantFactor
        0,                       //depthBiasClamp
        0,                       //depthBiasSlopeFactor
        1.0f                     //lineWidth
    ));

    vk::PipelineColorBlendAttachmentStatePtr attState(new vk::PipelineColorBlendAttachmentState(VK_FALSE,            //blendEnable
        VK_BLEND_FACTOR_ZERO,//srcColorBlendFactor
        VK_BLEND_FACTOR_ZERO,//dstColorBlendFactor
        VK_BLEND_OP_ADD,     //colorBlendOp
        VK_BLEND_FACTOR_ZERO,//srcAlphaBlendFactor
        VK_BLEND_FACTOR_ZERO,//dstAlphaBlendFactor
        VK_BLEND_OP_ADD,     //alphaBlendOp
        0xf                  //colorWriteMask
    ));
    std::vector<vk::PipelineColorBlendAttachmentStatePtr> attStates;
    attStates.push_back(attState);

    float blendConstants[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    vk::PipelineColorBlendStateCreateInfoPtr cb(new vk::PipelineColorBlendStateCreateInfo(0x0,              //flags
        VK_FALSE,         //logicOpEnable
        VK_LOGIC_OP_NO_OP,//logicOp
        attStates,        //attachments
        blendConstants    //blendConstants
    ));


    VkStencilOpState stencilFront;
    VkStencilOpState stencilBack;
    stencilBack.failOp = VK_STENCIL_OP_KEEP;
    stencilBack.passOp = VK_STENCIL_OP_KEEP;
    stencilBack.compareOp = VK_COMPARE_OP_ALWAYS;
    stencilBack.compareMask = 0;
    stencilBack.reference = 0;
    stencilBack.depthFailOp = VK_STENCIL_OP_KEEP;
    stencilBack.writeMask = 0;
    stencilFront = stencilBack;
    vk::PipelineDepthStencilStateCreateInfoPtr ds(new vk::PipelineDepthStencilStateCreateInfo(0x0,                        //flags
        VK_TRUE,                    //depthTestEnable
        VK_TRUE,                    //depthWriteEnable
        VK_COMPARE_OP_LESS_OR_EQUAL,//depthCompareOp
        VK_FALSE,                   //depthBoundsTestEnable
        VK_FALSE,                   //stencilTestEnable
        stencilFront,               //front
        stencilBack,                //back
        0,                          //minDepthBounds
        0                           //maxDepthBounds
    ));

    vk::PipelineMultisampleStateCreateInfoPtr ms(new vk::PipelineMultisampleStateCreateInfo(0x0,        //flags
        mainVulkanObjects._depthImage->getInfo()->getSamples(),//rasterizationSamples
        VK_FALSE,   //sampleShadingEnable
        0.0f,       //minSampleShading
        nullptr,    //pSampleMask
        VK_FALSE,   //alphaToCoverageEnable
        VK_FALSE    //alphaToOneEnable
    ));

    vk::GraphicsPipelineCreateInfoPtr pipelineCreateInfo(new vk::GraphicsPipelineCreateInfo(0x0,//flags
        shaderStages,//pStages
        vi,//pVertexInputState
        ia,//pInputAssemblyState
        nullptr,//pTessellationState
        vp,//pViewportState
        rs,//pRasterizationState
        ms,//pMultisampleState
        ds,//pDepthStencilState
        cb,//pColorBlendState
        dynamicState,//pDynamicState
        mainVulkanObjects._pipelineLayout,//layout
        rendrePass,//renderPass
        0,//subpass
        VK_NULL_HANDLE,//basePipelineHandle
        0//basePipelineIndex
    ));

    vk::GraphicsPipelinePtr graphicsPipeline(new vk::GraphicsPipeline(device, VK_NULL_HANDLE, pipelineCreateInfo, nullptr));

    return graphicsPipeline;
}

void presentDraw(vk::DevicePtr device,
    vk::SwapchainKHRPtr swapchain,
    vk::RenderPassPtr renderpass,
    std::vector<vk::FramebufferPtr>& frameBuffers,
    vk::CommandBufferPtr commandBuffer,
    vk::GraphicsPipelinePtr graphicsPipeline,
    MainVulkanObjects& mainVulkanObjects)
{
    std::vector<VkClearValue> clearValues;
    clearValues.resize(2);
    clearValues[0].color.float32[0] = 0.2f;
    clearValues[0].color.float32[1] = 0.2f;
    clearValues[0].color.float32[2] = 0.2f;
    clearValues[0].color.float32[3] = 0.2f;
    clearValues[1].depthStencil.depth = 1.0f;
    clearValues[1].depthStencil.stencil = 0;

    vk::SemaphoreCreateInfoPtr imageAcquiredSemaphoreCreateInfo(new vk::SemaphoreCreateInfo(0x0));
    vk::SemaphorePtr imageAcquiredSemaphore(new vk::Semaphore(device, imageAcquiredSemaphoreCreateInfo, nullptr));


    // Get the index of the next available swapchain image:
	uint32_t swapAcquiredimageIndex(0);
	swapchain->acquireNextImage(UINT64_MAX, imageAcquiredSemaphore, VK_NULL_HANDLE, &swapAcquiredimageIndex);

	VkRect2D renderArea;
    renderArea.offset.x = 0;
    renderArea.offset.y = 0;
    renderArea.extent.width = swapchain->getInfo()->getExtent().width;
    renderArea.extent.height = swapchain->getInfo()->getExtent().height;
    vk::RenderPassBeginInfoPtr rpBegin(new vk::RenderPassBeginInfo(renderpass, frameBuffers[swapAcquiredimageIndex], renderArea, clearValues));

    commandBuffer->cmdBeginRenderPass(rpBegin, VK_SUBPASS_CONTENTS_INLINE);

    commandBuffer->cmdBindPipeline(VK_PIPELINE_BIND_POINT_GRAPHICS, graphicsPipeline);

    commandBuffer->cmdBindDescriptorSets(VK_PIPELINE_BIND_POINT_GRAPHICS, mainVulkanObjects._pipelineLayout, 0, mainVulkanObjects._descriptorSet, std::vector<uint32_t>());

	commandBuffer->cmdBindVertexBuffer(0, mainVulkanObjects._vertexBuffer, 0);

    std::vector<VkViewport> viewports;
    viewports.resize(1);
    viewports[0].height = (float)swapchain->getInfo()->getExtent().height;
    viewports[0].width = (float)swapchain->getInfo()->getExtent().width;
    viewports[0].minDepth = (float)0.0f;
    viewports[0].maxDepth = (float)1.0f;
    viewports[0].x = 0;
    viewports[0].y = 0;
    commandBuffer->cmdSetViewport(0, viewports);

    std::vector<VkRect2D> scissors;
    scissors.resize(1);
    scissors[0].extent.width = swapchain->getInfo()->getExtent().width;
    scissors[0].extent.height = swapchain->getInfo()->getExtent().height;
    scissors[0].offset.x = 0;
    scissors[0].offset.y = 0;
    commandBuffer->cmdSetScissor(0, scissors);

    commandBuffer->cmdDraw(12 * 3, 1, 0, 0);

    commandBuffer->cmdEndRenderPass();

    commandBuffer->end();

    vk::FenceCreateInfoPtr fenceInfo(new vk::FenceCreateInfo(0x0));
    vk::FencePtr drawFence(new vk::Fence(device, fenceInfo, nullptr));

    std::vector<VkPipelineStageFlags> pipeStageFlags;
    pipeStageFlags.push_back(VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT);

    std::vector<vk::SemaphorePtr> waitSemaphors;
    waitSemaphors.push_back(imageAcquiredSemaphore);

    std::vector<vk::CommandBufferPtr> cmdBufs;
    cmdBufs.push_back(commandBuffer);

    std::vector<vk::SemaphorePtr> emptySemaphors;
    vk::SubmitInfoPtr submitInfo(new vk::SubmitInfo(waitSemaphors, pipeStageFlags, cmdBufs, emptySemaphors));

    /* Queue the command buffer for execution */
    mainVulkanObjects._graphicsQueue->queueSubmit(submitInfo, drawFence);

    /* Now present the image in the window */

    std::vector<vk::SwapchainKHRPtr> swapchains;
    swapchains.push_back(swapchain);

    std::vector<uint32_t> imageIndices;
    imageIndices.push_back(swapAcquiredimageIndex);
    vk::PresentInfoKHRPtr presentInfo(new vk::PresentInfoKHR(emptySemaphors, swapchains, imageIndices, std::vector<VkResult>()));

    /* Make sure command buffer is finished before presenting */
    uint64_t cmdBufferFenceTimeout = 100000000;
    VkResult res;
    do {
        res = device->waitForFence(drawFence, VK_TRUE, cmdBufferFenceTimeout);
    } while (res == VK_TIMEOUT);

    mainVulkanObjects._presentQueue->queuePresentKHR(presentInfo);

    uint32_t seconds(10);
#ifdef WIN32
    Sleep(seconds * 1000);
#endif
}
