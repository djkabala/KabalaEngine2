#include "vkSampler.h"
vk::Sampler::Sampler(DevicePtr device, SamplerCreateInfoPtr info, const VkAllocationCallbacks* allocator) : _sampler(nullptr), _device(device), _allocator(allocator)
{
     VkResult res = vkCreateSampler(_device->getRaw(), info->getRaw(), _allocator, &_sampler);
     if (res != VK_SUCCESS)
     {
         throw res;
     }
}

vk::Sampler::~Sampler()
{
    if (_sampler != nullptr)
    {
        vkDestroySampler(_device->getRaw(), _sampler, _allocator);
    }
}
