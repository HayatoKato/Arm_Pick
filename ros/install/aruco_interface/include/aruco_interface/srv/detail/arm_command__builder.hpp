// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aruco_interface:srv/ArmCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__BUILDER_HPP_
#define ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__BUILDER_HPP_

#include "aruco_interface/srv/detail/arm_command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace aruco_interface
{

namespace srv
{

namespace builder
{

class Init_ArmCommand_Request_colay
{
public:
  explicit Init_ArmCommand_Request_colay(::aruco_interface::srv::ArmCommand_Request & msg)
  : msg_(msg)
  {}
  ::aruco_interface::srv::ArmCommand_Request colay(::aruco_interface::srv::ArmCommand_Request::_colay_type arg)
  {
    msg_.colay = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aruco_interface::srv::ArmCommand_Request msg_;
};

class Init_ArmCommand_Request_colax
{
public:
  Init_ArmCommand_Request_colax()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmCommand_Request_colay colax(::aruco_interface::srv::ArmCommand_Request::_colax_type arg)
  {
    msg_.colax = std::move(arg);
    return Init_ArmCommand_Request_colay(msg_);
  }

private:
  ::aruco_interface::srv::ArmCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aruco_interface::srv::ArmCommand_Request>()
{
  return aruco_interface::srv::builder::Init_ArmCommand_Request_colax();
}

}  // namespace aruco_interface


namespace aruco_interface
{

namespace srv
{

namespace builder
{

class Init_ArmCommand_Response_catchcola
{
public:
  Init_ArmCommand_Response_catchcola()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::aruco_interface::srv::ArmCommand_Response catchcola(::aruco_interface::srv::ArmCommand_Response::_catchcola_type arg)
  {
    msg_.catchcola = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aruco_interface::srv::ArmCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aruco_interface::srv::ArmCommand_Response>()
{
  return aruco_interface::srv::builder::Init_ArmCommand_Response_catchcola();
}

}  // namespace aruco_interface

#endif  // ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__BUILDER_HPP_
