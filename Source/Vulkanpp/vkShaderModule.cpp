#include "vkShaderModule.h"

vk::ShaderModule::ShaderModule(DevicePtr device, ShaderModuleCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator) : _device(device), _allocator(pAllocator)
{
	VkResult res = vkCreateShaderModule(_device->getRaw(), createInfo->getRaw(), _allocator, &_module);
	
	if (res != VK_SUCCESS)
	{
		throw res;
	}
}

vk::ShaderModule::~ShaderModule()
{
	if (_module != nullptr)
	{
		vkDestroyShaderModule(_device->getRaw(), _module, _allocator);
	}
}
