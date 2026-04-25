// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rexrov_interfaces:msg/GateDetection.idl
// generated code does not contain a copyright notice

#ifndef REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__STRUCT_HPP_
#define REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rexrov_interfaces__msg__GateDetection __attribute__((deprecated))
#else
# define DEPRECATED__rexrov_interfaces__msg__GateDetection __declspec(deprecated)
#endif

namespace rexrov_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GateDetection_
{
  using Type = GateDetection_<ContainerAllocator>;

  explicit GateDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->error_x = 0.0f;
      this->distance = 0.0f;
      this->pixel_x = 0l;
      this->pixel_y = 0l;
    }
  }

  explicit GateDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->error_x = 0.0f;
      this->distance = 0.0f;
      this->pixel_x = 0l;
      this->pixel_y = 0l;
    }
  }

  // field types and members
  using _detected_type =
    bool;
  _detected_type detected;
  using _error_x_type =
    float;
  _error_x_type error_x;
  using _distance_type =
    float;
  _distance_type distance;
  using _pixel_x_type =
    int32_t;
  _pixel_x_type pixel_x;
  using _pixel_y_type =
    int32_t;
  _pixel_y_type pixel_y;

  // setters for named parameter idiom
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }
  Type & set__error_x(
    const float & _arg)
  {
    this->error_x = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__pixel_x(
    const int32_t & _arg)
  {
    this->pixel_x = _arg;
    return *this;
  }
  Type & set__pixel_y(
    const int32_t & _arg)
  {
    this->pixel_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rexrov_interfaces::msg::GateDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const rexrov_interfaces::msg::GateDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rexrov_interfaces::msg::GateDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rexrov_interfaces::msg::GateDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rexrov_interfaces::msg::GateDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rexrov_interfaces::msg::GateDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rexrov_interfaces::msg::GateDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rexrov_interfaces::msg::GateDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rexrov_interfaces::msg::GateDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rexrov_interfaces::msg::GateDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rexrov_interfaces__msg__GateDetection
    std::shared_ptr<rexrov_interfaces::msg::GateDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rexrov_interfaces__msg__GateDetection
    std::shared_ptr<rexrov_interfaces::msg::GateDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GateDetection_ & other) const
  {
    if (this->detected != other.detected) {
      return false;
    }
    if (this->error_x != other.error_x) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->pixel_x != other.pixel_x) {
      return false;
    }
    if (this->pixel_y != other.pixel_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const GateDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GateDetection_

// alias to use template instance with default allocator
using GateDetection =
  rexrov_interfaces::msg::GateDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rexrov_interfaces

#endif  // REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__STRUCT_HPP_
