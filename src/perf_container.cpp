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
#include <set>
#include <unordered_set>

#include "gtestx/gtestx.h"
#include "gflags/gflags.h"
#include "perf_common.h"
#include "boost/unordered_map.hpp"
#include "boost/unordered_set.hpp"

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
    next_ = FLAGS_container_size;
  }

  virtual void TearDown() override {
  }
 protected:
  M map_;
  int next_;
 private:
};


using MapTestImplementations = testing::Types<
std::map<uint64_t, uint64_t>,
  std::unordered_map<uint64_t, uint64_t>,
  boost::unordered_map<uint64_t, uint64_t> >;

TYPED_TEST_CASE(MapTest, MapTestImplementations);

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

TYPED_PERF_TEST(MapTest, update) {
  this->map_.erase(this->map_.begin());
  this->map_.emplace(this->next_, this->next_);
  this->next_++;
}

////////////////////////////////////////////////////////////////////////////////
/**
 * @brief 
 * @class SetTest
 */
template <typename M>
class SetTest: public testing::Test
{
 public:
  /**
   * @brief
   */
  SetTest() = default;

  virtual void SetUp() override {
    for (auto i = 0u; i < FLAGS_container_size; ++i) {
      set_.emplace(i);
    }
    next_ = FLAGS_container_size;
  }

  virtual void TearDown() override {
  }
 protected:
  M set_;
  int next_;
 private:
};


using SetTestImplementations = testing::Types<
std::set<uint64_t>,
  std::unordered_set<uint64_t>,
  boost::unordered_set<uint64_t> >;

TYPED_TEST_CASE(SetTest, SetTestImplementations);

TYPED_TEST(SetTest, order) {
  auto const print_prob = 20.0 / FLAGS_container_size;
  for (auto const &it: this->set_) {
    if ((static_cast<double>(random())/RAND_MAX) <= print_prob) {
      std::cout << it << std::endl;
    }
  }
}

TYPED_PERF_TEST(SetTest, find) {
  this->set_.find(random());
}

TYPED_PERF_TEST(SetTest, update) {
  this->set_.erase(this->set_.begin());
  this->set_.emplace(this->next_++);
}


} // namespace

