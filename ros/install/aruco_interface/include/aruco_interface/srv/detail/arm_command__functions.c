// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aruco_interface:srv/ArmCommand.idl
// generated code does not contain a copyright notice
#include "aruco_interface/srv/detail/arm_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
aruco_interface__srv__ArmCommand_Request__init(aruco_interface__srv__ArmCommand_Request * msg)
{
  if (!msg) {
    return false;
  }
  // colax
  // colay
  return true;
}

void
aruco_interface__srv__ArmCommand_Request__fini(aruco_interface__srv__ArmCommand_Request * msg)
{
  if (!msg) {
    return;
  }
  // colax
  // colay
}

bool
aruco_interface__srv__ArmCommand_Request__are_equal(const aruco_interface__srv__ArmCommand_Request * lhs, const aruco_interface__srv__ArmCommand_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // colax
  if (lhs->colax != rhs->colax) {
    return false;
  }
  // colay
  if (lhs->colay != rhs->colay) {
    return false;
  }
  return true;
}

bool
aruco_interface__srv__ArmCommand_Request__copy(
  const aruco_interface__srv__ArmCommand_Request * input,
  aruco_interface__srv__ArmCommand_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // colax
  output->colax = input->colax;
  // colay
  output->colay = input->colay;
  return true;
}

aruco_interface__srv__ArmCommand_Request *
aruco_interface__srv__ArmCommand_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArmCommand_Request * msg = (aruco_interface__srv__ArmCommand_Request *)allocator.allocate(sizeof(aruco_interface__srv__ArmCommand_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aruco_interface__srv__ArmCommand_Request));
  bool success = aruco_interface__srv__ArmCommand_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aruco_interface__srv__ArmCommand_Request__destroy(aruco_interface__srv__ArmCommand_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aruco_interface__srv__ArmCommand_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aruco_interface__srv__ArmCommand_Request__Sequence__init(aruco_interface__srv__ArmCommand_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArmCommand_Request * data = NULL;

  if (size) {
    data = (aruco_interface__srv__ArmCommand_Request *)allocator.zero_allocate(size, sizeof(aruco_interface__srv__ArmCommand_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aruco_interface__srv__ArmCommand_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aruco_interface__srv__ArmCommand_Request__fini(&data[i - 1]);
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
aruco_interface__srv__ArmCommand_Request__Sequence__fini(aruco_interface__srv__ArmCommand_Request__Sequence * array)
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
      aruco_interface__srv__ArmCommand_Request__fini(&array->data[i]);
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

aruco_interface__srv__ArmCommand_Request__Sequence *
aruco_interface__srv__ArmCommand_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArmCommand_Request__Sequence * array = (aruco_interface__srv__ArmCommand_Request__Sequence *)allocator.allocate(sizeof(aruco_interface__srv__ArmCommand_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aruco_interface__srv__ArmCommand_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aruco_interface__srv__ArmCommand_Request__Sequence__destroy(aruco_interface__srv__ArmCommand_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aruco_interface__srv__ArmCommand_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aruco_interface__srv__ArmCommand_Request__Sequence__are_equal(const aruco_interface__srv__ArmCommand_Request__Sequence * lhs, const aruco_interface__srv__ArmCommand_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aruco_interface__srv__ArmCommand_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aruco_interface__srv__ArmCommand_Request__Sequence__copy(
  const aruco_interface__srv__ArmCommand_Request__Sequence * input,
  aruco_interface__srv__ArmCommand_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aruco_interface__srv__ArmCommand_Request);
    aruco_interface__srv__ArmCommand_Request * data =
      (aruco_interface__srv__ArmCommand_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aruco_interface__srv__ArmCommand_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          aruco_interface__srv__ArmCommand_Request__fini(&data[i]);
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
    if (!aruco_interface__srv__ArmCommand_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
aruco_interface__srv__ArmCommand_Response__init(aruco_interface__srv__ArmCommand_Response * msg)
{
  if (!msg) {
    return false;
  }
  // catchcola
  return true;
}

void
aruco_interface__srv__ArmCommand_Response__fini(aruco_interface__srv__ArmCommand_Response * msg)
{
  if (!msg) {
    return;
  }
  // catchcola
}

bool
aruco_interface__srv__ArmCommand_Response__are_equal(const aruco_interface__srv__ArmCommand_Response * lhs, const aruco_interface__srv__ArmCommand_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // catchcola
  if (lhs->catchcola != rhs->catchcola) {
    return false;
  }
  return true;
}

bool
aruco_interface__srv__ArmCommand_Response__copy(
  const aruco_interface__srv__ArmCommand_Response * input,
  aruco_interface__srv__ArmCommand_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // catchcola
  output->catchcola = input->catchcola;
  return true;
}

aruco_interface__srv__ArmCommand_Response *
aruco_interface__srv__ArmCommand_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArmCommand_Response * msg = (aruco_interface__srv__ArmCommand_Response *)allocator.allocate(sizeof(aruco_interface__srv__ArmCommand_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aruco_interface__srv__ArmCommand_Response));
  bool success = aruco_interface__srv__ArmCommand_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aruco_interface__srv__ArmCommand_Response__destroy(aruco_interface__srv__ArmCommand_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aruco_interface__srv__ArmCommand_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aruco_interface__srv__ArmCommand_Response__Sequence__init(aruco_interface__srv__ArmCommand_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArmCommand_Response * data = NULL;

  if (size) {
    data = (aruco_interface__srv__ArmCommand_Response *)allocator.zero_allocate(size, sizeof(aruco_interface__srv__ArmCommand_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aruco_interface__srv__ArmCommand_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aruco_interface__srv__ArmCommand_Response__fini(&data[i - 1]);
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
aruco_interface__srv__ArmCommand_Response__Sequence__fini(aruco_interface__srv__ArmCommand_Response__Sequence * array)
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
      aruco_interface__srv__ArmCommand_Response__fini(&array->data[i]);
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

aruco_interface__srv__ArmCommand_Response__Sequence *
aruco_interface__srv__ArmCommand_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aruco_interface__srv__ArmCommand_Response__Sequence * array = (aruco_interface__srv__ArmCommand_Response__Sequence *)allocator.allocate(sizeof(aruco_interface__srv__ArmCommand_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aruco_interface__srv__ArmCommand_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aruco_interface__srv__ArmCommand_Response__Sequence__destroy(aruco_interface__srv__ArmCommand_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aruco_interface__srv__ArmCommand_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aruco_interface__srv__ArmCommand_Response__Sequence__are_equal(const aruco_interface__srv__ArmCommand_Response__Sequence * lhs, const aruco_interface__srv__ArmCommand_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aruco_interface__srv__ArmCommand_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aruco_interface__srv__ArmCommand_Response__Sequence__copy(
  const aruco_interface__srv__ArmCommand_Response__Sequence * input,
  aruco_interface__srv__ArmCommand_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aruco_interface__srv__ArmCommand_Response);
    aruco_interface__srv__ArmCommand_Response * data =
      (aruco_interface__srv__ArmCommand_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aruco_interface__srv__ArmCommand_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          aruco_interface__srv__ArmCommand_Response__fini(&data[i]);
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
    if (!aruco_interface__srv__ArmCommand_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
