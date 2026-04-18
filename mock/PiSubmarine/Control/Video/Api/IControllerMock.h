#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Control/Video/Api/IController.h"

namespace PiSubmarine::Control::Video::Api
{
    class IControllerMock : public IController
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), SetTarget, (const Command& target), (override));
    };
}
