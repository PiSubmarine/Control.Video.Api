#include <gtest/gtest.h>

#include "PiSubmarine/Control/Video/Api/IControllerMock.h"

namespace PiSubmarine::Control::Video::Api
{
    TEST(IControllerMockTest, SupportsSettingVideoTarget)
    {
        IControllerMock controller;
        const auto target = Command::Enable(StreamProfile::Standard, AutoFocus{});

        EXPECT_CALL(controller, SetTarget(target))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        EXPECT_TRUE(controller.SetTarget(target).has_value());
    }
}
