#include <ostream>
#include <gtest/gtest.h>
#include "KeyCode.hpp"
#include "ButtonStatus.hpp"
#include "Config.hpp"

using namespace org_pqrs_Karabiner;
Config config;

std::ostream& operator<<(std::ostream& os, const EventType& v) { return os << v.get(); }
std::ostream& operator<<(std::ostream& os, const KeyboardType& v) { return os << v.get(); }
std::ostream& operator<<(std::ostream& os, const ModifierFlag& v) { return os << v.getRawBits(); }
std::ostream& operator<<(std::ostream& os, const Flags& v) { return os << v.get(); }
std::ostream& operator<<(std::ostream& os, const KeyCode& v) { return os << v.get(); }
std::ostream& operator<<(std::ostream& os, const ConsumerKeyCode& v) { return os << v.get(); }
std::ostream& operator<<(std::ostream& os, const PointingButton& v) { return os << v.get(); }
std::ostream& operator<<(std::ostream& os, const Buttons& v) { return os << v.get(); }

TEST(ButtonStatus, all) {
  ASSERT_TRUE(ButtonStatus::initialize());

  EXPECT_EQ(Buttons(), ButtonStatus::makeButtons());

  // ------------------------------------------------------------
  // set
  {
    ButtonStatus::set(PointingButton(1 << 3), true);
    EXPECT_EQ(Buttons((1 << 3)), ButtonStatus::makeButtons());

    ButtonStatus::set(PointingButton(1 << 11), false);
    EXPECT_EQ(Buttons((1 << 3)), ButtonStatus::makeButtons());

    ButtonStatus::set(PointingButton(1 << 11), true);
    EXPECT_EQ(Buttons((1 << 3)), ButtonStatus::makeButtons());

    ButtonStatus::set(PointingButton(1 << 11), true);
    EXPECT_EQ(Buttons((1 << 3) | (1 << 11)), ButtonStatus::makeButtons());

    ButtonStatus::set(PointingButton(1 << 3), false);
    EXPECT_EQ(Buttons((1 << 11)), ButtonStatus::makeButtons());

    ButtonStatus::set(PointingButton(1 << 1), true);
    EXPECT_EQ(Buttons((1 << 1) | (1 << 11)), ButtonStatus::makeButtons());
  }

  // ------------------------------------------------------------
  // increase & decrease
  ButtonStatus::increase(Buttons(1 << 9));
  EXPECT_EQ(Buttons((1 << 1) | (1 << 9) | (1 << 11)), ButtonStatus::makeButtons());

  ButtonStatus::decrease(Buttons((1 << 4) | (1 << 8)));
  EXPECT_EQ(Buttons((1 << 1) | (1 << 9) | (1 << 11)), ButtonStatus::makeButtons());

  // ------------------------------------------------------------
  // reset
  ButtonStatus::reset();
  EXPECT_EQ(Buttons(), ButtonStatus::makeButtons());

  // ------------------------------------------------------------
  // lock
  ButtonStatus::lock_increase(Buttons((1 << 1) | (1 << 3)));
  ButtonStatus::increase(Buttons(1 << 5));
  EXPECT_EQ(Buttons((1 << 1) | (1 << 3) | (1 << 5)), ButtonStatus::makeButtons());
  ButtonStatus::reset();
  EXPECT_EQ(Buttons((1 << 1) | (1 << 3)), ButtonStatus::makeButtons());
  ButtonStatus::lock_clear();
  EXPECT_EQ(Buttons(), ButtonStatus::makeButtons());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
