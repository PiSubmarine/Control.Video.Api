#include <gtest/gtest.h>

#include "PiSubmarine/Control/Video/Api/Command.h"

namespace PiSubmarine::Control::Video::Api
{
    TEST(CommandTest, DisableCreatesDisabledCommand)
    {
        constexpr auto command = Command::Disable();

        static_assert(!command.IsEnabled());
        EXPECT_FALSE(command.IsEnabled());
        EXPECT_TRUE(std::holds_alternative<Disabled>(command.GetState()));
    }

    TEST(CommandTest, EnableStoresProfileAndAutoFocus)
    {
        constexpr auto command = Command::Enable(StreamProfile::HighQuality, AutoFocus{});

        static_assert(command.IsEnabled());
        ASSERT_TRUE(command.IsEnabled());

        const auto* enabled = command.TryGetEnabled();
        ASSERT_NE(enabled, nullptr);
        EXPECT_EQ(enabled->Profile, StreamProfile::HighQuality);
        EXPECT_TRUE(std::holds_alternative<AutoFocus>(enabled->Focus));
    }

    TEST(CommandTest, EnableStoresProfileAndManualFocus)
    {
        constexpr auto command = Command::Enable(
            StreamProfile::LowLatency,
            ManualFocus{.Position = NormalizedFraction(0.35)});

        ASSERT_TRUE(command.IsEnabled());

        const auto* enabled = command.TryGetEnabled();
        ASSERT_NE(enabled, nullptr);
        EXPECT_EQ(enabled->Profile, StreamProfile::LowLatency);

        const auto* focus = std::get_if<ManualFocus>(&enabled->Focus);
        ASSERT_NE(focus, nullptr);
        EXPECT_EQ(focus->Position, NormalizedFraction(0.35));
    }
}
