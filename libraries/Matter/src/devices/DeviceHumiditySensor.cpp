/*
 * This file is part of the Silicon Labs Arduino Core
 *
 * The MIT License (MIT)
 *
 * Copyright 2023 Silicon Laboratories Inc. www.silabs.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "DeviceHumiditySensor.h"

DeviceHumiditySensor::DeviceHumiditySensor(const char* device_name,
                                           std::string location,
                                           uint16_t min,
                                           uint16_t max,
                                           uint16_t measured_value) :
  Device(device_name, location),
  min_value(min),
  max_value(max),
  measured_value(measured_value),
  device_changed_callback(nullptr)
{
  ;
}

uint16_t DeviceHumiditySensor::GetMeasuredValue()
{
  return this->measured_value;
}

void DeviceHumiditySensor::SetMeasuredValue(uint16_t measurement)
{
  if (measurement < this->min_value) {
    measurement = this->min_value;
  } else if (measurement > this->max_value) {
    measurement = this->max_value;
  }

  bool changed = this->measured_value != measurement;
  ChipLogProgress(DeviceLayer, "HumiditySensorDevice[%s]: new measurement='%u'", mName, measurement);
  this->measured_value = measurement;

  if (changed && this->device_changed_callback) {
    this->device_changed_callback(this, kChanged_MeasurementValue);
  }
}

void DeviceHumiditySensor::SetChangeCallback(DeviceCallback_fn device_changed_callback)
{
  this->device_changed_callback = device_changed_callback;
}

void DeviceHumiditySensor::HandleDeviceChange(Device* device, Device::Changed_t change_mask)
{
  if (this->device_changed_callback) {
    this->device_changed_callback(this, (DeviceHumiditySensor::Changed_t) change_mask);
  }
}

uint32_t DeviceHumiditySensor::GetHumiditySensorClusterFeatureMap()
{
  return this->humidity_sensor_cluster_feature_map;
}

uint16_t DeviceHumiditySensor::GetHumiditySensorClusterRevision()
{
  return this->humidity_sensor_cluster_revision;
}
