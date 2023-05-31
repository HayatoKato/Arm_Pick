// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aruco_interface:srv/ArucoCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__ARUCO_COMMAND__STRUCT_H_
#define ARUCO_INTERFACE__SRV__DETAIL__ARUCO_COMMAND__STRUCT_H_

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

// Struct defined in srv/ArucoCommand in the package aruco_interface.
typedef struct aruco_interface__srv__ArucoCommand_Request
{
  rosidl_runtime_c__String command;
} aruco_interface__srv__ArucoCommand_Request;

// Struct for a sequence of aruco_interface__srv__ArucoCommand_Request.
typedef struct aruco_interface__srv__ArucoCommand_Request__Sequence
{
  aruco_interface__srv__ArucoCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aruco_interface__srv__ArucoCommand_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ArucoCommand in the package aruco_interface.
typedef struct aruco_interface__srv__ArucoCommand_Response
{
  int32_t ar0x;
  int32_t ar0y;
  int32_t ar1x;
  int32_t ar1y;
  int32_t ar2x;
  int32_t ar2y;
  int32_t ar3x;
  int32_t ar3y;
} aruco_interface__srv__ArucoCommand_Response;

// Struct for a sequence of aruco_interface__srv__ArucoCommand_Response.
typedef struct aruco_interface__srv__ArucoCommand_Response__Sequence
{
  aruco_interface__srv__ArucoCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aruco_interface__srv__ArucoCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARUCO_INTERFACE__SRV__DETAIL__ARUCO_COMMAND__STRUCT_H_
