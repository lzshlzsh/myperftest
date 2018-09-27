/**
 * @file perf_container.cpp
 * @brief
 * @version 1.0
 * @date 09/27/2018 11:03:02 AM
 * @author sammieliu,sammieliu@tencent.com
 * @copyright Copyright 1998 - 2018 Tencent. All Rights Reserved.
 */
#include <stdlib.h>

#include <map>
#include <unordered_map>
#include <iostream>

#include "gtestx/gtestx.h"
#include "gflags/gflags.h"
#include "perf_common.h"
#include "boost/unordered_map.hpp"

namespace {

/**
 * @brief 
 * @class MapTest
 */
template <typename M>
class MapTest: public testing::Test
{
 public:
  /**
   * @brief
   */
  MapTest() = default;

  virtual void SetUp() override {
    for (auto i = 0u; i < FLAGS_container_size; ++i) {
      map_.emplace(i, i);
    }
  }

  virtual void TearDown() override {
  }
 protected:
  M map_;
 private:
};


using Implementations = testing::Types<
std::map<uint64_t, uint64_t>,
  std::unordered_map<uint64_t, uint64_t>,
  boost::unordered_map<uint64_t, uint64_t> >;

TYPED_TEST_CASE(MapTest, Implementations);

TYPED_TEST(MapTest, order) {
  auto const print_prob = 20.0 / FLAGS_container_size;
  for (auto const &it: this->map_) {
    if ((static_cast<double>(random())/RAND_MAX) <= print_prob) {
      std::cout << it.first << ' ' << it.second << std::endl;
    }
  }
}

TYPED_PERF_TEST(MapTest, find) {
  this->map_.find(random());
}

////////////////////////////////////////////////////////////////////////////////

} // namespace

