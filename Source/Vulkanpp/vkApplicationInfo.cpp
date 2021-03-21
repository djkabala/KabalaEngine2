#include "vkApplicationInfo.h"

vk::ApplicationInfo::ApplicationInfo(const char* appName, const uint32_t appVersion, const char* engineName, const uint32_t engineVersion, const uint32_t apiVersion)
{
    _info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    _info.pNext = NULL;
    _info.pApplicationName = appName;
    _info.applicationVersion = appVersion;
    _info.pEngineName = engineName;
    _info.engineVersion = engineVersion;
    _info.apiVersion = apiVersion;
}
