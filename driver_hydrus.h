/*
  Based on: https://github.com/wmbusmeters/wmbusmeters/blob/master/src/driver_hydrus.cc
  Copyright (C) 2017-2023 Fredrik Öhrström (gpl-3.0-or-later)
*/

#pragma once

#include "driver.h"

#include <vector>
#include <string>

struct Hydrus: Driver
{
  Hydrus(std::string key = "") : Driver(std::string("hydrus"), key) {};
  virtual esphome::optional<std::map<std::string, double>> get_values(std::vector<unsigned char> &telegram) override {
    std::map<std::string, double> ret_val{};

    add_to_map(ret_val, "total_water_m3", this->get_0C13(telegram));
    add_to_map(ret_val, "total_water_m3", this->get_0C14(telegram));

    if (ret_val.size() > 0) {
      return ret_val;
    }
    else {
      return {};
    }
  };

private:
};