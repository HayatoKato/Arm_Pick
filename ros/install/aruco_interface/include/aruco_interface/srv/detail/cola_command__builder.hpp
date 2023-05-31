// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aruco_interface:srv/ColaCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__COLA_COMMAND__BUILDER_HPP_
#define ARUCO_INTERFACE__SRV__DETAIL__COLA_COMMAND__BUILDER_HPP_

#include "aruco_interface/srv/detail/cola_command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace aruco_interface
{

namespace srv
{

namespace builder
{

class Init_ColaCommand_Request_command
{
public:
  Init_ColaCommand_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::aruco_interface::srv::ColaCommand_Request command(::aruco_interface::srv::ColaCommand_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aruco_interface::srv::ColaCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aruco_interface::srv::ColaCommand_Request>()
{
  return aruco_interface::srv::builder::Init_ColaCommand_Request_command();
}

}  // namespace aruco_interface


namespace aruco_interface
{

namespace srv
{

namespace builder
{

class Init_ColaCommand_Response_ymax
{
public:
  explicit Init_ColaCommand_Response_ymax(::aruco_interface::srv::ColaCommand_Response & msg)
  : msg_(msg)
  {}
  ::aruco_interface::srv::ColaCommand_Response ymax(::aruco_interface::srv::ColaCommand_Response::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aruco_interface::srv::ColaCommand_Response msg_;
};

class Init_ColaCommand_Response_xmax
{
public:
  explicit Init_ColaCommand_Response_xmax(::aruco_interface::srv::ColaCommand_Response & msg)
  : msg_(msg)
  {}
  Init_ColaCommand_Response_ymax xmax(::aruco_interface::srv::ColaCommand_Response::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_ColaCommand_Response_ymax(msg_);
  }

private:
  ::aruco_interface::srv::ColaCommand_Response msg_;
};

class Init_ColaCommand_Response_ymin
{
public:
  explicit Init_ColaCommand_Response_ymin(::aruco_interface::srv::ColaCommand_Response & msg)
  : msg_(msg)
  {}
  Init_ColaCommand_Response_xmax ymin(::aruco_interface::srv::ColaCommand_Response::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_ColaCommand_Response_xmax(msg_);
  }

private:
  ::aruco_interface::srv::ColaCommand_Response msg_;
};

class Init_ColaCommand_Response_xmin
{
public:
  Init_ColaCommand_Response_xmin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ColaCommand_Response_ymin xmin(::aruco_interface::srv::ColaCommand_Response::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_ColaCommand_Response_ymin(msg_);
  }

private:
  ::aruco_interface::srv::ColaCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aruco_interface::srv::ColaCommand_Response>()
{
  return aruco_interface::srv::builder::Init_ColaCommand_Response_xmin();
}

}  // namespace aruco_interface

#endif  // ARUCO_INTERFACE__SRV__DETAIL__COLA_COMMAND__BUILDER_HPP_
