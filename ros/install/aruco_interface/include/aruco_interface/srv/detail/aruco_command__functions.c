// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aruco_interface:srv/ArucoCommand.idl
// generated code does not contain a copyright notice
#include "aruco_interface/srv/detail/aruco_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `command`
#include "rosidl_runtime_c/string_functions.h"

bool
aruco_interface__srv__ArucoCommand_Request__init(aruco_interface__srv__ArucoCommand_Request * msg)
{
  if (!msg) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    aruco_interface__srv__ArucoCommand_Request__fini(msg);
    return false;
  }
  return true;
}

void
aruco_interface__srv__ArucoCommand_Request__fini(aruco_interface__srv__ArucoCommand_Request * msg)
{
  if (!msg) {
    return;
  }
  // command
  rosidl_runtime_c__String__fini(&msg->command);
}

bool
aruco_interface__srv__ArucoCommand_Request__are_equal(const aruco_interface__srv__ArucoCommand_Request * lhs, const aruco_interface__srv__ArucoCommand_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  return true;
}

bool
aruco_interface__srv__ArucoCommand_Request__copy(
  const aruco_interface__srv__ArucoCommand_Request * input,
  aruco_interface__srv__ArucoCommand_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  return true;
}

aruco_interface__srv__ArucoCommand_Request *
aruco_interface__srv__ArucoCommand_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArucoCommand_Request * msg = (aruco_interface__srv__ArucoCommand_Request *)allocator.allocate(sizeof(aruco_interface__srv__ArucoCommand_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aruco_interface__srv__ArucoCommand_Request));
  bool success = aruco_interface__srv__ArucoCommand_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aruco_interface__srv__ArucoCommand_Request__destroy(aruco_interface__srv__ArucoCommand_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aruco_interface__srv__ArucoCommand_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aruco_interface__srv__ArucoCommand_Request__Sequence__init(aruco_interface__srv__ArucoCommand_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArucoCommand_Request * data = NULL;

  if (size) {
    data = (aruco_interface__srv__ArucoCommand_Request *)allocator.zero_allocate(size, sizeof(aruco_interface__srv__ArucoCommand_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aruco_interface__srv__ArucoCommand_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aruco_interface__srv__ArucoCommand_Request__fini(&data[i - 1]);
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
aruco_interface__srv__ArucoCommand_Request__Sequence__fini(aruco_interface__srv__ArucoCommand_Request__Sequence * array)
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
      aruco_interface__srv__ArucoCommand_Request__fini(&array->data[i]);
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

aruco_interface__srv__ArucoCommand_Request__Sequence *
aruco_interface__srv__ArucoCommand_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArucoCommand_Request__Sequence * array = (aruco_interface__srv__ArucoCommand_Request__Sequence *)allocator.allocate(sizeof(aruco_interface__srv__ArucoCommand_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aruco_interface__srv__ArucoCommand_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aruco_interface__srv__ArucoCommand_Request__Sequence__destroy(aruco_interface__srv__ArucoCommand_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aruco_interface__srv__ArucoCommand_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aruco_interface__srv__ArucoCommand_Request__Sequence__are_equal(const aruco_interface__srv__ArucoCommand_Request__Sequence * lhs, const aruco_interface__srv__ArucoCommand_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aruco_interface__srv__ArucoCommand_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aruco_interface__srv__ArucoCommand_Request__Sequence__copy(
  const aruco_interface__srv__ArucoCommand_Request__Sequence * input,
  aruco_interface__srv__ArucoCommand_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aruco_interface__srv__ArucoCommand_Request);
    aruco_interface__srv__ArucoCommand_Request * data =
      (aruco_interface__srv__ArucoCommand_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aruco_interface__srv__ArucoCommand_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          aruco_interface__srv__ArucoCommand_Request__fini(&data[i]);
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
    if (!aruco_interface__srv__ArucoCommand_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
aruco_interface__srv__ArucoCommand_Response__init(aruco_interface__srv__ArucoCommand_Response * msg)
{
  if (!msg) {
    return false;
  }
  // ar0x
  // ar0y
  // ar1x
  // ar1y
  // ar2x
  // ar2y
  // ar3x
  // ar3y
  return true;
}

void
aruco_interface__srv__ArucoCommand_Response__fini(aruco_interface__srv__ArucoCommand_Response * msg)
{
  if (!msg) {
    return;
  }
  // ar0x
  // ar0y
  // ar1x
  // ar1y
  // ar2x
  // ar2y
  // ar3x
  // ar3y
}

bool
aruco_interface__srv__ArucoCommand_Response__are_equal(const aruco_interface__srv__ArucoCommand_Response * lhs, const aruco_interface__srv__ArucoCommand_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ar0x
  if (lhs->ar0x != rhs->ar0x) {
    return false;
  }
  // ar0y
  if (lhs->ar0y != rhs->ar0y) {
    return false;
  }
  // ar1x
  if (lhs->ar1x != rhs->ar1x) {
    return false;
  }
  // ar1y
  if (lhs->ar1y != rhs->ar1y) {
    return false;
  }
  // ar2x
  if (lhs->ar2x != rhs->ar2x) {
    return false;
  }
  // ar2y
  if (lhs->ar2y != rhs->ar2y) {
    return false;
  }
  // ar3x
  if (lhs->ar3x != rhs->ar3x) {
    return false;
  }
  // ar3y
  if (lhs->ar3y != rhs->ar3y) {
    return false;
  }
  return true;
}

bool
aruco_interface__srv__ArucoCommand_Response__copy(
  const aruco_interface__srv__ArucoCommand_Response * input,
  aruco_interface__srv__ArucoCommand_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // ar0x
  output->ar0x = input->ar0x;
  // ar0y
  output->ar0y = input->ar0y;
  // ar1x
  output->ar1x = input->ar1x;
  // ar1y
  output->ar1y = input->ar1y;
  // ar2x
  output->ar2x = input->ar2x;
  // ar2y
  output->ar2y = input->ar2y;
  // ar3x
  output->ar3x = input->ar3x;
  // ar3y
  output->ar3y = input->ar3y;
  return true;
}

aruco_interface__srv__ArucoCommand_Response *
aruco_interface__srv__ArucoCommand_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArucoCommand_Response * msg = (aruco_interface__srv__ArucoCommand_Response *)allocator.allocate(sizeof(aruco_interface__srv__ArucoCommand_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aruco_interface__srv__ArucoCommand_Response));
  bool success = aruco_interface__srv__ArucoCommand_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aruco_interface__srv__ArucoCommand_Response__destroy(aruco_interface__srv__ArucoCommand_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aruco_interface__srv__ArucoCommand_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aruco_interface__srv__ArucoCommand_Response__Sequence__init(aruco_interface__srv__ArucoCommand_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArucoCommand_Response * data = NULL;

  if (size) {
    data = (aruco_interface__srv__ArucoCommand_Response *)allocator.zero_allocate(size, sizeof(aruco_interface__srv__ArucoCommand_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aruco_interface__srv__ArucoCommand_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aruco_interface__srv__ArucoCommand_Response__fini(&data[i - 1]);
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
aruco_interface__srv__ArucoCommand_Response__Sequence__fini(aruco_interface__srv__ArucoCommand_Response__Sequence * array)
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
      aruco_interface__srv__ArucoCommand_Response__fini(&array->data[i]);
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

aruco_interface__srv__ArucoCommand_Response__Sequence *
aruco_interface__srv__ArucoCommand_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArucoCommand_Response__Sequence * array = (aruco_interface__srv__ArucoCommand_Response__Sequence *)allocator.allocate(sizeof(aruco_interface__srv__ArucoCommand_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aruco_interface__srv__ArucoCommand_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aruco_interface__srv__ArucoCommand_Response__Sequence__destroy(aruco_interface__srv__ArucoCommand_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aruco_interface__srv__ArucoCommand_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aruco_interface__srv__ArucoCommand_Response__Sequence__are_equal(const aruco_interface__srv__ArucoCommand_Response__Sequence * lhs, const aruco_interface__srv__ArucoCommand_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aruco_interface__srv__ArucoCommand_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aruco_interface__srv__ArucoCommand_Response__Sequence__copy(
  const aruco_interface__srv__ArucoCommand_Response__Sequence * input,
  aruco_interface__srv__ArucoCommand_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aruco_interface__srv__ArucoCommand_Response);
    aruco_interface__srv__ArucoCommand_Response * data =
      (aruco_interface__srv__ArucoCommand_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aruco_interface__srv__ArucoCommand_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          aruco_interface__srv__ArucoCommand_Response__fini(&data[i]);
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
    if (!aruco_interface__srv__ArucoCommand_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
