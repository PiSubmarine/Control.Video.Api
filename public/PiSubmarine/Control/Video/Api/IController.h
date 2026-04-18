#pragma once

#include "PiSubmarine/Control/Video/Api/Command.h"
#include "PiSubmarine/Error/Api/Result.h"

namespace PiSubmarine::Control::Video::Api
{
    class IController
    {
    public:
        virtual ~IController() = default;

        [[nodiscard]] virtual Error::Api::Result<void> SetTarget(const Command& target) = 0;
    };
}
