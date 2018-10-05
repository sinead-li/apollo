/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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

#ifndef MODULES_CANBUS_VEHICLE_LEXUS_PROTOCOL_HEADLIGHT_CMD_118_H_
#define MODULES_CANBUS_VEHICLE_LEXUS_PROTOCOL_HEADLIGHT_CMD_118_H_

#include "modules/canbus/proto/chassis_detail.pb.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace lexus {

class Headlightcmd118 : public ::apollo::drivers::canbus::ProtocolData<
                            ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Headlightcmd118();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'name': 'IGNORE_OVERRIDES', 'offset': 0.0,
  // 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range':
  // '[0|1]', 'bit': 1, 'type': 'bool', 'order': 'motorola', 'physical_unit':
  // ''}
  Headlightcmd118* set_ignore_overrides(bool ignore_overrides);

  // config detail: {'name': 'ENABLE', 'offset': 0.0, 'precision': 1.0, 'len':
  // 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 0, 'type':
  // 'bool', 'order': 'motorola', 'physical_unit': ''}
  Headlightcmd118* set_enable(bool enable);

  // config detail: {'name': 'CLEAR_OVERRIDE', 'offset': 0.0, 'precision': 1.0,
  // 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 2,
  // 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  Headlightcmd118* set_clear_override(bool clear_override);

  // config detail: {'name': 'CLEAR_FAULTS', 'offset': 0.0, 'precision': 1.0,
  // 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 3,
  // 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  Headlightcmd118* set_clear_faults(bool clear_faults);

  // config detail: {'name': 'HEADLIGHT_CMD', 'enum': {0:
  // 'HEADLIGHT_CMD_HEADLIGHTS_OFF', 1: 'HEADLIGHT_CMD_LOW_BEAMS', 2:
  // 'HEADLIGHT_CMD_HIGH_BEAMS'}, 'precision': 1.0, 'len': 8, 'is_signed_var':
  // False, 'offset': 0.0, 'physical_range': '[0|2]', 'bit': 15, 'type': 'enum',
  // 'order': 'motorola', 'physical_unit': ''}
  Headlightcmd118* set_headlight_cmd(
      Headlight_cmd_118::Headlight_cmdType headlight_cmd);

 private:
  // config detail: {'name': 'IGNORE_OVERRIDES', 'offset': 0.0,
  // 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range':
  // '[0|1]', 'bit': 1, 'type': 'bool', 'order': 'motorola', 'physical_unit':
  // ''}
  void set_p_ignore_overrides(uint8_t* data, bool ignore_overrides);

  // config detail: {'name': 'ENABLE', 'offset': 0.0, 'precision': 1.0, 'len':
  // 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 0, 'type':
  // 'bool', 'order': 'motorola', 'physical_unit': ''}
  void set_p_enable(uint8_t* data, bool enable);

  // config detail: {'name': 'CLEAR_OVERRIDE', 'offset': 0.0, 'precision': 1.0,
  // 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 2,
  // 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  void set_p_clear_override(uint8_t* data, bool clear_override);

  // config detail: {'name': 'CLEAR_FAULTS', 'offset': 0.0, 'precision': 1.0,
  // 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 3,
  // 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  void set_p_clear_faults(uint8_t* data, bool clear_faults);

  // config detail: {'name': 'HEADLIGHT_CMD', 'enum': {0:
  // 'HEADLIGHT_CMD_HEADLIGHTS_OFF', 1: 'HEADLIGHT_CMD_LOW_BEAMS', 2:
  // 'HEADLIGHT_CMD_HIGH_BEAMS'}, 'precision': 1.0, 'len': 8, 'is_signed_var':
  // False, 'offset': 0.0, 'physical_range': '[0|2]', 'bit': 15, 'type': 'enum',
  // 'order': 'motorola', 'physical_unit': ''}
  void set_p_headlight_cmd(uint8_t* data,
                           Headlight_cmd_118::Headlight_cmdType headlight_cmd);

 private:
  bool ignore_overrides_;
  bool enable_;
  bool clear_override_;
  bool clear_faults_;
  Headlight_cmd_118::Headlight_cmdType headlight_cmd_;
};

}  // namespace lexus
}  // namespace canbus
}  // namespace apollo

#endif  // MODULES_CANBUS_VEHICL_LEXUS_PROTOCOL_HEADLIGHT_CMD_118_H_
