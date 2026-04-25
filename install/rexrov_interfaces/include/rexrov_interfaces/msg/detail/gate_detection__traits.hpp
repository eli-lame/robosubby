// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rexrov_interfaces:msg/GateDetection.idl
// generated code does not contain a copyright notice

#ifndef REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__TRAITS_HPP_
#define REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__TRAITS_HPP_

#include "rexrov_interfaces/msg/detail/gate_detection__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rexrov_interfaces::msg::GateDetection>()
{
  return "rexrov_interfaces::msg::GateDetection";
}

template<>
inline const char * name<rexrov_interfaces::msg::GateDetection>()
{
  return "rexrov_interfaces/msg/GateDetection";
}

template<>
struct has_fixed_size<rexrov_interfaces::msg::GateDetection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rexrov_interfaces::msg::GateDetection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rexrov_interfaces::msg::GateDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__TRAITS_HPP_
