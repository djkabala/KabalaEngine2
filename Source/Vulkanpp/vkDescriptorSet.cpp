#include "vkDescriptorSet.h"

vk::DescriptorSet::DescriptorSet(DevicePtr device, DescriptorSetAllocateInfoPtr allocateInfo ) :
    _allocateInfo(allocateInfo), _device(device)
{
    _sets.resize(allocateInfo->getDescriptorSetCount());
     VkResult res = vkAllocateDescriptorSets(_device->getRaw(), _allocateInfo->getRaw(), _sets.data());
     if (res != VK_SUCCESS)
     {
         throw res;
     }
}
