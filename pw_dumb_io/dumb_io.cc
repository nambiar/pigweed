// Copyright 2019 The Pigweed Authors
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy
// of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations
// under the License.

#include "pw_dumb_io/dumb_io.h"

namespace pw::dumb_io {

StatusWithSize GetBytes(span<std::byte> dest) {
  for (size_t i = 0; i < dest.size_bytes(); ++i) {
    Status result = GetByte(&dest[i]);
    if (!result.ok()) {
      return StatusWithSize(result, i);
    }
  }
  return StatusWithSize(dest.size_bytes());
}

StatusWithSize PutBytes(span<const std::byte> src) {
  for (size_t i = 0; i < src.size_bytes(); ++i) {
    Status result = PutByte(src[i]);
    if (!result.ok()) {
      return StatusWithSize(result, i);
    }
  }
  return StatusWithSize(src.size_bytes());
}

}  // namespace pw::dumb_io
