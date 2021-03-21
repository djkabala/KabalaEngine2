#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>
#include "vkAttachmentDescription.h"
#include "vkSubpassDescription.h"
#include "vkSubpassDependency.h"

namespace vk
{

class RenderPassCreateInfo
{
public:
	RenderPassCreateInfo(VkRenderPassCreateFlags                      flags,
                         const std::vector<AttachmentDescriptionPtr>& pAttachments,
                         const std::vector<SubpassDescriptionPtr>&    pSubpasses,
                         const std::vector<SubpassDependencyPtr>&     pDependencies);

	inline VkRenderPassCreateInfo* getRaw(void) {return &_info;}

	inline const VkRenderPassCreateInfo* getRaw(void) const {return &_info;}
protected:
	VkRenderPassCreateInfo _info;

    std::vector<VkAttachmentDescription> _attachments;
    std::vector<VkSubpassDescription>    _subpasses;
    std::vector<VkSubpassDependency>     _dependencies;
};

typedef std::shared_ptr<RenderPassCreateInfo> RenderPassCreateInfoPtr; 
};


