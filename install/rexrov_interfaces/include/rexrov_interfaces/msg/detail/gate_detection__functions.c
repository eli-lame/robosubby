// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rexrov_interfaces:msg/GateDetection.idl
// generated code does not contain a copyright notice
#include "rexrov_interfaces/msg/detail/gate_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rexrov_interfaces__msg__GateDetection__init(rexrov_interfaces__msg__GateDetection * msg)
{
  if (!msg) {
    return false;
  }
  // detected
  // error_x
  // distance
  // pixel_x
  // pixel_y
  return true;
}

void
rexrov_interfaces__msg__GateDetection__fini(rexrov_interfaces__msg__GateDetection * msg)
{
  if (!msg) {
    return;
  }
  // detected
  // error_x
  // distance
  // pixel_x
  // pixel_y
}

bool
rexrov_interfaces__msg__GateDetection__are_equal(const rexrov_interfaces__msg__GateDetection * lhs, const rexrov_interfaces__msg__GateDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // detected
  if (lhs->detected != rhs->detected) {
    return false;
  }
  // error_x
  if (lhs->error_x != rhs->error_x) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  // pixel_x
  if (lhs->pixel_x != rhs->pixel_x) {
    return false;
  }
  // pixel_y
  if (lhs->pixel_y != rhs->pixel_y) {
    return false;
  }
  return true;
}

bool
rexrov_interfaces__msg__GateDetection__copy(
  const rexrov_interfaces__msg__GateDetection * input,
  rexrov_interfaces__msg__GateDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // detected
  output->detected = input->detected;
  // error_x
  output->error_x = input->error_x;
  // distance
  output->distance = input->distance;
  // pixel_x
  output->pixel_x = input->pixel_x;
  // pixel_y
  output->pixel_y = input->pixel_y;
  return true;
}

rexrov_interfaces__msg__GateDetection *
rexrov_interfaces__msg__GateDetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rexrov_interfaces__msg__GateDetection * msg = (rexrov_interfaces__msg__GateDetection *)allocator.allocate(sizeof(rexrov_interfaces__msg__GateDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rexrov_interfaces__msg__GateDetection));
  bool success = rexrov_interfaces__msg__GateDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rexrov_interfaces__msg__GateDetection__destroy(rexrov_interfaces__msg__GateDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rexrov_interfaces__msg__GateDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rexrov_interfaces__msg__GateDetection__Sequence__init(rexrov_interfaces__msg__GateDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rexrov_interfaces__msg__GateDetection * data = NULL;

  if (size) {
    data = (rexrov_interfaces__msg__GateDetection *)allocator.zero_allocate(size, sizeof(rexrov_interfaces__msg__GateDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rexrov_interfaces__msg__GateDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rexrov_interfaces__msg__GateDetection__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rexrov_interfaces__msg__GateDetection__Sequence__fini(rexrov_interfaces__msg__GateDetection__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rexrov_interfaces__msg__GateDetection__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rexrov_interfaces__msg__GateDetection__Sequence *
rexrov_interfaces__msg__GateDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rexrov_interfaces__msg__GateDetection__Sequence * array = (rexrov_interfaces__msg__GateDetection__Sequence *)allocator.allocate(sizeof(rexrov_interfaces__msg__GateDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rexrov_interfaces__msg__GateDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rexrov_interfaces__msg__GateDetection__Sequence__destroy(rexrov_interfaces__msg__GateDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rexrov_interfaces__msg__GateDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rexrov_interfaces__msg__GateDetection__Sequence__are_equal(const rexrov_interfaces__msg__GateDetection__Sequence * lhs, const rexrov_interfaces__msg__GateDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rexrov_interfaces__msg__GateDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rexrov_interfaces__msg__GateDetection__Sequence__copy(
  const rexrov_interfaces__msg__GateDetection__Sequence * input,
  rexrov_interfaces__msg__GateDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rexrov_interfaces__msg__GateDetection);
    rexrov_interfaces__msg__GateDetection * data =
      (rexrov_interfaces__msg__GateDetection *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rexrov_interfaces__msg__GateDetection__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rexrov_interfaces__msg__GateDetection__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rexrov_interfaces__msg__GateDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
