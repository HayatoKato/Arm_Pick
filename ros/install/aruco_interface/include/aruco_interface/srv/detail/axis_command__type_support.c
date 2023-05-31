// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from aruco_interface:srv/AxisCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "aruco_interface/srv/detail/axis_command__rosidl_typesupport_introspection_c.h"
#include "aruco_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "aruco_interface/srv/detail/axis_command__functions.h"
#include "aruco_interface/srv/detail/axis_command__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aruco_interface__srv__AxisCommand_Request__init(message_memory);
}

void AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_fini_function(void * message_memory)
{
  aruco_interface__srv__AxisCommand_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_message_member_array[12] = {
  {
    "ar0x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, ar0x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ar0y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, ar0y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ar1x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, ar1x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ar1y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, ar1y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ar2x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, ar2x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ar2y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, ar2y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ar3x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, ar3x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ar3y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, ar3y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xmin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, xmin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, ymin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xmax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, xmax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Request, ymax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_message_members = {
  "aruco_interface__srv",  // message namespace
  "AxisCommand_Request",  // message name
  12,  // number of fields
  sizeof(aruco_interface__srv__AxisCommand_Request),
  AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_message_member_array,  // message members
  AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_message_type_support_handle = {
  0,
  &AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aruco_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aruco_interface, srv, AxisCommand_Request)() {
  if (!AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_message_type_support_handle.typesupport_identifier) {
    AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &AxisCommand_Request__rosidl_typesupport_introspection_c__AxisCommand_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "aruco_interface/srv/detail/axis_command__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aruco_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aruco_interface/srv/detail/axis_command__functions.h"
// already included above
// #include "aruco_interface/srv/detail/axis_command__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aruco_interface__srv__AxisCommand_Response__init(message_memory);
}

void AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_fini_function(void * message_memory)
{
  aruco_interface__srv__AxisCommand_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_message_member_array[2] = {
  {
    "colax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Response, colax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "colay",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aruco_interface__srv__AxisCommand_Response, colay),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_message_members = {
  "aruco_interface__srv",  // message namespace
  "AxisCommand_Response",  // message name
  2,  // number of fields
  sizeof(aruco_interface__srv__AxisCommand_Response),
  AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_message_member_array,  // message members
  AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_message_type_support_handle = {
  0,
  &AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aruco_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aruco_interface, srv, AxisCommand_Response)() {
  if (!AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_message_type_support_handle.typesupport_identifier) {
    AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &AxisCommand_Response__rosidl_typesupport_introspection_c__AxisCommand_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "aruco_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "aruco_interface/srv/detail/axis_command__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers aruco_interface__srv__detail__axis_command__rosidl_typesupport_introspection_c__AxisCommand_service_members = {
  "aruco_interface__srv",  // service namespace
  "AxisCommand",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // aruco_interface__srv__detail__axis_command__rosidl_typesupport_introspection_c__AxisCommand_Request_message_type_support_handle,
  NULL  // response message
  // aruco_interface__srv__detail__axis_command__rosidl_typesupport_introspection_c__AxisCommand_Response_message_type_support_handle
};

static rosidl_service_type_support_t aruco_interface__srv__detail__axis_command__rosidl_typesupport_introspection_c__AxisCommand_service_type_support_handle = {
  0,
  &aruco_interface__srv__detail__axis_command__rosidl_typesupport_introspection_c__AxisCommand_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aruco_interface, srv, AxisCommand_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aruco_interface, srv, AxisCommand_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aruco_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aruco_interface, srv, AxisCommand)() {
  if (!aruco_interface__srv__detail__axis_command__rosidl_typesupport_introspection_c__AxisCommand_service_type_support_handle.typesupport_identifier) {
    aruco_interface__srv__detail__axis_command__rosidl_typesupport_introspection_c__AxisCommand_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)aruco_interface__srv__detail__axis_command__rosidl_typesupport_introspection_c__AxisCommand_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aruco_interface, srv, AxisCommand_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aruco_interface, srv, AxisCommand_Response)()->data;
  }

  return &aruco_interface__srv__detail__axis_command__rosidl_typesupport_introspection_c__AxisCommand_service_type_support_handle;
}
