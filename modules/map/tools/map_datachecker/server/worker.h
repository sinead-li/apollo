/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#pragma once

#include <grpc++/grpc++.h>
#include <string>

namespace apollo {
namespace hdmap {

class Mapdatachecker {
 public:
  Mapdatachecker() {}
  ~Mapdatachecker() {}

  bool Init();
  bool Start();
  bool Stop();
  void Report();

 private:
  std::string grpc_address_;
};

}  // namespace hdmap
}  // namespace apollo