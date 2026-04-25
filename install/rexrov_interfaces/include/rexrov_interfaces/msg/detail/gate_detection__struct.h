// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rexrov_interfaces:msg/GateDetection.idl
// generated code does not contain a copyright notice

#ifndef REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__STRUCT_H_
#define REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/GateDetection in the package rexrov_interfaces.
typedef struct rexrov_interfaces__msg__GateDetection
{
  bool detected;
  float error_x;
  float distance;
  int32_t pixel_x;
  int32_t pixel_y;
} rexrov_interfaces__msg__GateDetection;

// Struct for a sequence of rexrov_interfaces__msg__GateDetection.
typedef struct rexrov_interfaces__msg__GateDetection__Sequence
{
  rexrov_interfaces__msg__GateDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rexrov_interfaces__msg__GateDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__STRUCT_H_
