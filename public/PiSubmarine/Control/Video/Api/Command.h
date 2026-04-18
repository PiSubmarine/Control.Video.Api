#pragma once

#include <variant>

#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Control::Video::Api
{
    enum class StreamProfile
    {
        LowLatency,
        Standard,
        HighQuality
    };

    struct Disabled
    {
        [[nodiscard]] constexpr bool operator==(const Disabled&) const = default;
    };

    struct AutoFocus
    {
        [[nodiscard]] constexpr bool operator==(const AutoFocus&) const = default;
    };

    struct ManualFocus
    {
        NormalizedFraction Position{0};

        [[nodiscard]] constexpr bool operator==(const ManualFocus&) const = default;
    };

    using FocusMode = std::variant<AutoFocus, ManualFocus>;

    struct Enabled
    {
        StreamProfile Profile;
        FocusMode Focus;

        [[nodiscard]] constexpr bool operator==(const Enabled&) const = default;
    };

    class Command
    {
    public:
        using State = std::variant<Disabled, Enabled>;

        [[nodiscard]] static constexpr Command Disable() noexcept
        {
            return Command(Disabled{});
        }

        [[nodiscard]] static constexpr Command Enable(
            const StreamProfile profile,
            const FocusMode& focus) noexcept
        {
            return Command(Enabled{profile, focus});
        }

        [[nodiscard]] constexpr bool IsEnabled() const noexcept
        {
            return std::holds_alternative<Enabled>(m_State);
        }

        [[nodiscard]] constexpr const State& GetState() const noexcept
        {
            return m_State;
        }

        [[nodiscard]] constexpr const Enabled* TryGetEnabled() const noexcept
        {
            return std::get_if<Enabled>(&m_State);
        }

        [[nodiscard]] constexpr bool operator==(const Command&) const = default;

    private:
        constexpr explicit Command(const State& state) noexcept
            : m_State(state)
        {
        }

        State m_State;
    };
}
