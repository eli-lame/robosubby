// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rexrov_interfaces:msg/GateDetection.idl
// generated code does not contain a copyright notice
#include "rexrov_interfaces/msg/detail/gate_detection__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rexrov_interfaces/msg/detail/gate_detection__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rexrov_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rexrov_interfaces
cdr_serialize(
  const rexrov_interfaces::msg::GateDetection & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: detected
  cdr << (ros_message.detected ? true : false);
  // Member: error_x
  cdr << ros_message.error_x;
  // Member: distance
  cdr << ros_message.distance;
  // Member: pixel_x
  cdr << ros_message.pixel_x;
  // Member: pixel_y
  cdr << ros_message.pixel_y;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rexrov_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rexrov_interfaces::msg::GateDetection & ros_message)
{
  // Member: detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.detected = tmp ? true : false;
  }

  // Member: error_x
  cdr >> ros_message.error_x;

  // Member: distance
  cdr >> ros_message.distance;

  // Member: pixel_x
  cdr >> ros_message.pixel_x;

  // Member: pixel_y
  cdr >> ros_message.pixel_y;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rexrov_interfaces
get_serialized_size(
  const rexrov_interfaces::msg::GateDetection & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: detected
  {
    size_t item_size = sizeof(ros_message.detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: error_x
  {
    size_t item_size = sizeof(ros_message.error_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: distance
  {
    size_t item_size = sizeof(ros_message.distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pixel_x
  {
    size_t item_size = sizeof(ros_message.pixel_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pixel_y
  {
    size_t item_size = sizeof(ros_message.pixel_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rexrov_interfaces
max_serialized_size_GateDetection(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: detected
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: error_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pixel_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pixel_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _GateDetection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rexrov_interfaces::msg::GateDetection *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GateDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rexrov_interfaces::msg::GateDetection *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GateDetection__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rexrov_interfaces::msg::GateDetection *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GateDetection__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_GateDetection(full_bounded, 0);
}

static message_type_support_callbacks_t _GateDetection__callbacks = {
  "rexrov_interfaces::msg",
  "GateDetection",
  _GateDetection__cdr_serialize,
  _GateDetection__cdr_deserialize,
  _GateDetection__get_serialized_size,
  _GateDetection__max_serialized_size
};

static rosidl_message_type_support_t _GateDetection__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GateDetection__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rexrov_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rexrov_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<rexrov_interfaces::msg::GateDetection>()
{
  return &rexrov_interfaces::msg::typesupport_fastrtps_cpp::_GateDetection__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rexrov_interfaces, msg, GateDetection)() {
  return &rexrov_interfaces::msg::typesupport_fastrtps_cpp::_GateDetection__handle;
}

#ifdef __cplusplus
}
#endif
