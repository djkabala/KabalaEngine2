#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class ApplicationInfo
{
public:
    ApplicationInfo(const char* name, const uint32_t appVersion, const char* engineName, const uint32_t engineVersion, const uint32_t apiVersion);

    VkApplicationInfo* getRaw(void)
    {
        return &_info;
    }

    const VkApplicationInfo* getRaw(void) const
    {
        return &_info;
    }

    inline const char*    getApplicationName   (void) const  { return _info.pApplicationName; }
    inline const uint32_t getApplicationVersion(void) const  { return _info.applicationVersion; }
    inline const char*    getEngineName        (void) const  { return _info.pEngineName; }
    inline const uint32_t getEngineVersion     (void) const  { return _info.engineVersion; }
    inline const uint32_t getApiVersion        (void) const  { return _info.apiVersion; }

    ApplicationInfo() = delete;
    ApplicationInfo(const ApplicationInfo&) = delete;
    ApplicationInfo(const ApplicationInfo&&) = delete;
    const ApplicationInfo& operator=(const ApplicationInfo&) = delete;

protected:
    VkApplicationInfo _info;
};

typedef std::shared_ptr<ApplicationInfo> ApplicationInfoPtr; 

};

