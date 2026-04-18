#include <gtest/gtest.h>

#include <type_traits>

#include "PiSubmarine/Control/Video/Api/IController.h"

namespace PiSubmarine::Control::Video::Api
{
    TEST(IControllerTest, HasVirtualDestructor)
    {
        static_assert(std::has_virtual_destructor_v<IController>);
        SUCCEED();
    }
}
