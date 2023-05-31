// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aruco_interface:srv/ArucoCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__ARUCO_COMMAND__BUILDER_HPP_
#define ARUCO_INTERFACE__SRV__DETAIL__ARUCO_COMMAND__BUILDER_HPP_

#include "aruco_interface/srv/detail/aruco_command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace aruco_interface
{

namespace srv
{

namespace builder
{

class Init_ArucoCommand_Request_command
{
public:
  Init_ArucoCommand_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::aruco_interface::srv::ArucoCommand_Request command(::aruco_interface::srv::ArucoCommand_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aruco_interface::srv::ArucoCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aruco_interface::srv::ArucoCommand_Request>()
{
  return aruco_interface::srv::builder::Init_ArucoCommand_Request_command();
}

}  // namespace aruco_interface


namespace aruco_interface
{

namespace srv
{

namespace builder
{

class Init_ArucoCommand_Response_ar3y
{
public:
  explicit Init_ArucoCommand_Response_ar3y(::aruco_interface::srv::ArucoCommand_Response & msg)
  : msg_(msg)
  {}
  ::aruco_interface::srv::ArucoCommand_Response ar3y(::aruco_interface::srv::ArucoCommand_Response::_ar3y_type arg)
  {
    msg_.ar3y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aruco_interface::srv::ArucoCommand_Response msg_;
};

class Init_ArucoCommand_Response_ar3x
{
public:
  explicit Init_ArucoCommand_Response_ar3x(::aruco_interface::srv::ArucoCommand_Response & msg)
  : msg_(msg)
  {}
  Init_ArucoCommand_Response_ar3y ar3x(::aruco_interface::srv::ArucoCommand_Response::_ar3x_type arg)
  {
    msg_.ar3x = std::move(arg);
    return Init_ArucoCommand_Response_ar3y(msg_);
  }

private:
  ::aruco_interface::srv::ArucoCommand_Response msg_;
};

class Init_ArucoCommand_Response_ar2y
{
public:
  explicit Init_ArucoCommand_Response_ar2y(::aruco_interface::srv::ArucoCommand_Response & msg)
  : msg_(msg)
  {}
  Init_ArucoCommand_Response_ar3x ar2y(::aruco_interface::srv::ArucoCommand_Response::_ar2y_type arg)
  {
    msg_.ar2y = std::move(arg);
    return Init_ArucoCommand_Response_ar3x(msg_);
  }

private:
  ::aruco_interface::srv::ArucoCommand_Response msg_;
};

class Init_ArucoCommand_Response_ar2x
{
public:
  explicit Init_ArucoCommand_Response_ar2x(::aruco_interface::srv::ArucoCommand_Response & msg)
  : msg_(msg)
  {}
  Init_ArucoCommand_Response_ar2y ar2x(::aruco_interface::srv::ArucoCommand_Response::_ar2x_type arg)
  {
    msg_.ar2x = std::move(arg);
    return Init_ArucoCommand_Response_ar2y(msg_);
  }

private:
  ::aruco_interface::srv::ArucoCommand_Response msg_;
};

class Init_ArucoCommand_Response_ar1y
{
public:
  explicit Init_ArucoCommand_Response_ar1y(::aruco_interface::srv::ArucoCommand_Response & msg)
  : msg_(msg)
  {}
  Init_ArucoCommand_Response_ar2x ar1y(::aruco_interface::srv::ArucoCommand_Response::_ar1y_type arg)
  {
    msg_.ar1y = std::move(arg);
    return Init_ArucoCommand_Response_ar2x(msg_);
  }

private:
  ::aruco_interface::srv::ArucoCommand_Response msg_;
};

class Init_ArucoCommand_Response_ar1x
{
public:
  explicit Init_ArucoCommand_Response_ar1x(::aruco_interface::srv::ArucoCommand_Response & msg)
  : msg_(msg)
  {}
  Init_ArucoCommand_Response_ar1y ar1x(::aruco_interface::srv::ArucoCommand_Response::_ar1x_type arg)
  {
    msg_.ar1x = std::move(arg);
    return Init_ArucoCommand_Response_ar1y(msg_);
  }

private:
  ::aruco_interface::srv::ArucoCommand_Response msg_;
};

class Init_ArucoCommand_Response_ar0y
{
public:
  explicit Init_ArucoCommand_Response_ar0y(::aruco_interface::srv::ArucoCommand_Response & msg)
  : msg_(msg)
  {}
  Init_ArucoCommand_Response_ar1x ar0y(::aruco_interface::srv::ArucoCommand_Response::_ar0y_type arg)
  {
    msg_.ar0y = std::move(arg);
    return Init_ArucoCommand_Response_ar1x(msg_);
  }

private:
  ::aruco_interface::srv::ArucoCommand_Response msg_;
};

class Init_ArucoCommand_Response_ar0x
{
public:
  Init_ArucoCommand_Response_ar0x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArucoCommand_Response_ar0y ar0x(::aruco_interface::srv::ArucoCommand_Response::_ar0x_type arg)
  {
    msg_.ar0x = std::move(arg);
    return Init_ArucoCommand_Response_ar0y(msg_);
  }

private:
  ::aruco_interface::srv::ArucoCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aruco_interface::srv::ArucoCommand_Response>()
{
  return aruco_interface::srv::builder::Init_ArucoCommand_Response_ar0x();
}

}  // namespace aruco_interface

#endif  // ARUCO_INTERFACE__SRV__DETAIL__ARUCO_COMMAND__BUILDER_HPP_
