// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aruco_interface:srv/ColaCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__COLA_COMMAND__STRUCT_H_
#define ARUCO_INTERFACE__SRV__DETAIL__COLA_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/ColaCommand in the package aruco_interface.
typedef struct aruco_interface__srv__ColaCommand_Request
{
  rosidl_runtime_c__String command;
} aruco_interface__srv__ColaCommand_Request;

// Struct for a sequence of aruco_interface__srv__ColaCommand_Request.
typedef struct aruco_interface__srv__ColaCommand_Request__Sequence
{
  aruco_interface__srv__ColaCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aruco_interface__srv__ColaCommand_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ColaCommand in the package aruco_interface.
typedef struct aruco_interface__srv__ColaCommand_Response
{
  int32_t xmin;
  int32_t ymin;
  int32_t xmax;
  int32_t ymax;
} aruco_interface__srv__ColaCommand_Response;

// Struct for a sequence of aruco_interface__srv__ColaCommand_Response.
typedef struct aruco_interface__srv__ColaCommand_Response__Sequence
{
  aruco_interface__srv__ColaCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aruco_interface__srv__ColaCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARUCO_INTERFACE__SRV__DETAIL__COLA_COMMAND__STRUCT_H_
