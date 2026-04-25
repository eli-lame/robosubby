// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rexrov_interfaces:msg/GateDetection.idl
// generated code does not contain a copyright notice

#ifndef REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__BUILDER_HPP_
#define REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__BUILDER_HPP_

#include "rexrov_interfaces/msg/detail/gate_detection__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rexrov_interfaces
{

namespace msg
{

namespace builder
{

class Init_GateDetection_pixel_y
{
public:
  explicit Init_GateDetection_pixel_y(::rexrov_interfaces::msg::GateDetection & msg)
  : msg_(msg)
  {}
  ::rexrov_interfaces::msg::GateDetection pixel_y(::rexrov_interfaces::msg::GateDetection::_pixel_y_type arg)
  {
    msg_.pixel_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rexrov_interfaces::msg::GateDetection msg_;
};

class Init_GateDetection_pixel_x
{
public:
  explicit Init_GateDetection_pixel_x(::rexrov_interfaces::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_pixel_y pixel_x(::rexrov_interfaces::msg::GateDetection::_pixel_x_type arg)
  {
    msg_.pixel_x = std::move(arg);
    return Init_GateDetection_pixel_y(msg_);
  }

private:
  ::rexrov_interfaces::msg::GateDetection msg_;
};

class Init_GateDetection_distance
{
public:
  explicit Init_GateDetection_distance(::rexrov_interfaces::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_pixel_x distance(::rexrov_interfaces::msg::GateDetection::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_GateDetection_pixel_x(msg_);
  }

private:
  ::rexrov_interfaces::msg::GateDetection msg_;
};

class Init_GateDetection_error_x
{
public:
  explicit Init_GateDetection_error_x(::rexrov_interfaces::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_distance error_x(::rexrov_interfaces::msg::GateDetection::_error_x_type arg)
  {
    msg_.error_x = std::move(arg);
    return Init_GateDetection_distance(msg_);
  }

private:
  ::rexrov_interfaces::msg::GateDetection msg_;
};

class Init_GateDetection_detected
{
public:
  Init_GateDetection_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GateDetection_error_x detected(::rexrov_interfaces::msg::GateDetection::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return Init_GateDetection_error_x(msg_);
  }

private:
  ::rexrov_interfaces::msg::GateDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rexrov_interfaces::msg::GateDetection>()
{
  return rexrov_interfaces::msg::builder::Init_GateDetection_detected();
}

}  // namespace rexrov_interfaces

#endif  // REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__BUILDER_HPP_
