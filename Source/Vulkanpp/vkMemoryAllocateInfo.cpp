#include "vkMemoryAllocateInfo.h"

vk::MemoryAllocateInfo::MemoryAllocateInfo(VkDeviceSize allocationSize, uint32_t memoryTypeIndex)
{
    _info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    _info.pNext = NULL;
    _info.allocationSize = allocationSize;
    _info.memoryTypeIndex = memoryTypeIndex;
}
