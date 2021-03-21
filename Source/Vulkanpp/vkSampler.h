#pragma once
#include "vkSamplerCreateInfo.h"
#include <memory>
#include "vkDevice.h"

namespace vk
{

class Sampler
{
public:
	Sampler(DevicePtr device, SamplerCreateInfoPtr pCreateInfo, const VkAllocationCallbacks* pAllocator);

	~Sampler();

	VkSampler getRaw(void) { return _sampler; }

	const VkSampler getRaw(void) const { return _sampler; }

protected:
	VkSampler _sampler;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<Sampler> SamplerPtr;

};


