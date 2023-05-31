// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aruco_interface:srv/ArmCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__STRUCT_H_
#define ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ArmCommand in the package aruco_interface.
typedef struct aruco_interface__srv__ArmCommand_Request
{
  float colax;
  float colay;
} aruco_interface__srv__ArmCommand_Request;

// Struct for a sequence of aruco_interface__srv__ArmCommand_Request.
typedef struct aruco_interface__srv__ArmCommand_Request__Sequence
{
  aruco_interface__srv__ArmCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aruco_interface__srv__ArmCommand_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ArmCommand in the package aruco_interface.
typedef struct aruco_interface__srv__ArmCommand_Response
{
  bool catchcola;
} aruco_interface__srv__ArmCommand_Response;

// Struct for a sequence of aruco_interface__srv__ArmCommand_Response.
typedef struct aruco_interface__srv__ArmCommand_Response__Sequence
{
  aruco_interface__srv__ArmCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aruco_interface__srv__ArmCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__STRUCT_H_
