// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rexrov_interfaces:msg/GateDetection.idl
// generated code does not contain a copyright notice

#ifndef REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__FUNCTIONS_H_
#define REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rexrov_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rexrov_interfaces/msg/detail/gate_detection__struct.h"

/// Initialize msg/GateDetection message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rexrov_interfaces__msg__GateDetection
 * )) before or use
 * rexrov_interfaces__msg__GateDetection__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
bool
rexrov_interfaces__msg__GateDetection__init(rexrov_interfaces__msg__GateDetection * msg);

/// Finalize msg/GateDetection message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
void
rexrov_interfaces__msg__GateDetection__fini(rexrov_interfaces__msg__GateDetection * msg);

/// Create msg/GateDetection message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rexrov_interfaces__msg__GateDetection__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
rexrov_interfaces__msg__GateDetection *
rexrov_interfaces__msg__GateDetection__create();

/// Destroy msg/GateDetection message.
/**
 * It calls
 * rexrov_interfaces__msg__GateDetection__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
void
rexrov_interfaces__msg__GateDetection__destroy(rexrov_interfaces__msg__GateDetection * msg);

/// Check for msg/GateDetection message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
bool
rexrov_interfaces__msg__GateDetection__are_equal(const rexrov_interfaces__msg__GateDetection * lhs, const rexrov_interfaces__msg__GateDetection * rhs);

/// Copy a msg/GateDetection message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
bool
rexrov_interfaces__msg__GateDetection__copy(
  const rexrov_interfaces__msg__GateDetection * input,
  rexrov_interfaces__msg__GateDetection * output);

/// Initialize array of msg/GateDetection messages.
/**
 * It allocates the memory for the number of elements and calls
 * rexrov_interfaces__msg__GateDetection__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
bool
rexrov_interfaces__msg__GateDetection__Sequence__init(rexrov_interfaces__msg__GateDetection__Sequence * array, size_t size);

/// Finalize array of msg/GateDetection messages.
/**
 * It calls
 * rexrov_interfaces__msg__GateDetection__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
void
rexrov_interfaces__msg__GateDetection__Sequence__fini(rexrov_interfaces__msg__GateDetection__Sequence * array);

/// Create array of msg/GateDetection messages.
/**
 * It allocates the memory for the array and calls
 * rexrov_interfaces__msg__GateDetection__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
rexrov_interfaces__msg__GateDetection__Sequence *
rexrov_interfaces__msg__GateDetection__Sequence__create(size_t size);

/// Destroy array of msg/GateDetection messages.
/**
 * It calls
 * rexrov_interfaces__msg__GateDetection__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
void
rexrov_interfaces__msg__GateDetection__Sequence__destroy(rexrov_interfaces__msg__GateDetection__Sequence * array);

/// Check for msg/GateDetection message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
bool
rexrov_interfaces__msg__GateDetection__Sequence__are_equal(const rexrov_interfaces__msg__GateDetection__Sequence * lhs, const rexrov_interfaces__msg__GateDetection__Sequence * rhs);

/// Copy an array of msg/GateDetection messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rexrov_interfaces
bool
rexrov_interfaces__msg__GateDetection__Sequence__copy(
  const rexrov_interfaces__msg__GateDetection__Sequence * input,
  rexrov_interfaces__msg__GateDetection__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // REXROV_INTERFACES__MSG__DETAIL__GATE_DETECTION__FUNCTIONS_H_
