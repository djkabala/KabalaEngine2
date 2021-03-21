#include "vkInstanceCreateInfo.h"

vk::InstanceCreateInfo::InstanceCreateInfo(ApplicationInfoPtr appInfo) : _appInfo(appInfo)
{
    // initialize the VkInstanceCreateInfo structure
    _info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = 0;
    if (_appInfo != nullptr)
    {
		_info.pApplicationInfo = _appInfo->getRaw();
    }
    else
    {
		_info.pApplicationInfo = nullptr;
    }
    _info.enabledExtensionCount = 0;
    _info.ppEnabledExtensionNames = NULL;
    _info.enabledLayerCount = 0;
    _info.ppEnabledLayerNames = NULL;

}

vk::InstanceCreateInfo::InstanceCreateInfo(const VkInstanceCreateFlags flags, ApplicationInfoPtr appInfo,
						std::vector<const char*>& enabledExtensionsNames,
						std::vector<const char*>& enabledLayerNames) : _appInfo(appInfo), _enabledExtensionsNames(enabledExtensionsNames), _enabledLayerNames(enabledLayerNames)
{
    // initialize the VkInstanceCreateInfo structure
    _info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = flags;
    if (_appInfo != nullptr)
    {
		_info.pApplicationInfo = _appInfo->getRaw();
    }
    else
    {
		_info.pApplicationInfo = nullptr;
    }
    _info.enabledExtensionCount = _enabledExtensionsNames.size();
    _info.ppEnabledExtensionNames = _enabledExtensionsNames.data();
    _info.enabledLayerCount = _enabledLayerNames.size();
    _info.ppEnabledLayerNames = _enabledLayerNames.data();

}
