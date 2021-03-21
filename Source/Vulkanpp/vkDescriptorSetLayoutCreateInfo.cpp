#include "vkDescriptorSetLayoutCreateInfo.h"
vk::DescriptorSetLayoutCreateInfo::DescriptorSetLayoutCreateInfo(VkDescriptorSetLayoutCreateFlags       flags,
                                  const std::vector<DescriptorSetLayoutBindingPtr>&    bindings)
{
    for (DescriptorSetLayoutBindingPtr binding : bindings)
    {
        _bindings.push_back(binding->getRaw());
    }
    _info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = flags;
    _info.bindingCount = _bindings.size();
    _info.pBindings = (_bindings.size() == 0) ? nullptr : _bindings.data();
}
