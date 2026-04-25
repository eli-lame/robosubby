// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rexrov_interfaces:msg/GateDetection.idl
// generated code does not contain a copyright notice
#include "rexrov_interfaces/msg/detail/gate_detection__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rexrov_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rexrov_interfaces/msg/detail/gate_detection__struct.h"
#include "rexrov_interfaces/msg/detail/gate_detection__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GateDetection__ros_msg_type = rexrov_interfaces__msg__GateDetection;

static bool _GateDetection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GateDetection__ros_msg_type * ros_message = static_cast<const _GateDetection__ros_msg_type *>(untyped_ros_message);
  // Field name: detected
  {
    cdr << (ros_message->detected ? true : false);
  }

  // Field name: error_x
  {
    cdr << ros_message->error_x;
  }

  // Field name: distance
  {
    cdr << ros_message->distance;
  }

  // Field name: pixel_x
  {
    cdr << ros_message->pixel_x;
  }

  // Field name: pixel_y
  {
    cdr << ros_message->pixel_y;
  }

  return true;
}

static bool _GateDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GateDetection__ros_msg_type * ros_message = static_cast<_GateDetection__ros_msg_type *>(untyped_ros_message);
  // Field name: detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->detected = tmp ? true : false;
  }

  // Field name: error_x
  {
    cdr >> ros_message->error_x;
  }

  // Field name: distance
  {
    cdr >> ros_message->distance;
  }

  // Field name: pixel_x
  {
    cdr >> ros_message->pixel_x;
  }

  // Field name: pixel_y
  {
    cdr >> ros_message->pixel_y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rexrov_interfaces
size_t get_serialized_size_rexrov_interfaces__msg__GateDetection(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GateDetection__ros_msg_type * ros_message = static_cast<const _GateDetection__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name detected
  {
    size_t item_size = sizeof(ros_message->detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name error_x
  {
    size_t item_size = sizeof(ros_message->error_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name distance
  {
    size_t item_size = sizeof(ros_message->distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pixel_x
  {
    size_t item_size = sizeof(ros_message->pixel_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pixel_y
  {
    size_t item_size = sizeof(ros_message->pixel_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GateDetection__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rexrov_interfaces__msg__GateDetection(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rexrov_interfaces
size_t max_serialized_size_rexrov_interfaces__msg__GateDetection(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: detected
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: error_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pixel_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pixel_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _GateDetection__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rexrov_interfaces__msg__GateDetection(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_GateDetection = {
  "rexrov_interfaces::msg",
  "GateDetection",
  _GateDetection__cdr_serialize,
  _GateDetection__cdr_deserialize,
  _GateDetection__get_serialized_size,
  _GateDetection__max_serialized_size
};

static rosidl_message_type_support_t _GateDetection__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GateDetection,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rexrov_interfaces, msg, GateDetection)() {
  return &_GateDetection__type_support;
}

#if defined(__cplusplus)
}
#endif
