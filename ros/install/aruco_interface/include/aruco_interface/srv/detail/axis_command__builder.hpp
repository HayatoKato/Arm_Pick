// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aruco_interface:srv/AxisCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__AXIS_COMMAND__BUILDER_HPP_
#define ARUCO_INTERFACE__SRV__DETAIL__AXIS_COMMAND__BUILDER_HPP_

#include "aruco_interface/srv/detail/axis_command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace aruco_interface
{

namespace srv
{

namespace builder
{

class Init_AxisCommand_Request_ymax
{
public:
  explicit Init_AxisCommand_Request_ymax(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  ::aruco_interface::srv::AxisCommand_Request ymax(::aruco_interface::srv::AxisCommand_Request::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_xmax
{
public:
  explicit Init_AxisCommand_Request_xmax(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  Init_AxisCommand_Request_ymax xmax(::aruco_interface::srv::AxisCommand_Request::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_AxisCommand_Request_ymax(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_ymin
{
public:
  explicit Init_AxisCommand_Request_ymin(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  Init_AxisCommand_Request_xmax ymin(::aruco_interface::srv::AxisCommand_Request::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_AxisCommand_Request_xmax(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_xmin
{
public:
  explicit Init_AxisCommand_Request_xmin(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  Init_AxisCommand_Request_ymin xmin(::aruco_interface::srv::AxisCommand_Request::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_AxisCommand_Request_ymin(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_ar3y
{
public:
  explicit Init_AxisCommand_Request_ar3y(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  Init_AxisCommand_Request_xmin ar3y(::aruco_interface::srv::AxisCommand_Request::_ar3y_type arg)
  {
    msg_.ar3y = std::move(arg);
    return Init_AxisCommand_Request_xmin(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_ar3x
{
public:
  explicit Init_AxisCommand_Request_ar3x(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  Init_AxisCommand_Request_ar3y ar3x(::aruco_interface::srv::AxisCommand_Request::_ar3x_type arg)
  {
    msg_.ar3x = std::move(arg);
    return Init_AxisCommand_Request_ar3y(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_ar2y
{
public:
  explicit Init_AxisCommand_Request_ar2y(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  Init_AxisCommand_Request_ar3x ar2y(::aruco_interface::srv::AxisCommand_Request::_ar2y_type arg)
  {
    msg_.ar2y = std::move(arg);
    return Init_AxisCommand_Request_ar3x(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_ar2x
{
public:
  explicit Init_AxisCommand_Request_ar2x(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  Init_AxisCommand_Request_ar2y ar2x(::aruco_interface::srv::AxisCommand_Request::_ar2x_type arg)
  {
    msg_.ar2x = std::move(arg);
    return Init_AxisCommand_Request_ar2y(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_ar1y
{
public:
  explicit Init_AxisCommand_Request_ar1y(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  Init_AxisCommand_Request_ar2x ar1y(::aruco_interface::srv::AxisCommand_Request::_ar1y_type arg)
  {
    msg_.ar1y = std::move(arg);
    return Init_AxisCommand_Request_ar2x(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_ar1x
{
public:
  explicit Init_AxisCommand_Request_ar1x(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  Init_AxisCommand_Request_ar1y ar1x(::aruco_interface::srv::AxisCommand_Request::_ar1x_type arg)
  {
    msg_.ar1x = std::move(arg);
    return Init_AxisCommand_Request_ar1y(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_ar0y
{
public:
  explicit Init_AxisCommand_Request_ar0y(::aruco_interface::srv::AxisCommand_Request & msg)
  : msg_(msg)
  {}
  Init_AxisCommand_Request_ar1x ar0y(::aruco_interface::srv::AxisCommand_Request::_ar0y_type arg)
  {
    msg_.ar0y = std::move(arg);
    return Init_AxisCommand_Request_ar1x(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

class Init_AxisCommand_Request_ar0x
{
public:
  Init_AxisCommand_Request_ar0x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AxisCommand_Request_ar0y ar0x(::aruco_interface::srv::AxisCommand_Request::_ar0x_type arg)
  {
    msg_.ar0x = std::move(arg);
    return Init_AxisCommand_Request_ar0y(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aruco_interface::srv::AxisCommand_Request>()
{
  return aruco_interface::srv::builder::Init_AxisCommand_Request_ar0x();
}

}  // namespace aruco_interface


namespace aruco_interface
{

namespace srv
{

namespace builder
{

class Init_AxisCommand_Response_colay
{
public:
  explicit Init_AxisCommand_Response_colay(::aruco_interface::srv::AxisCommand_Response & msg)
  : msg_(msg)
  {}
  ::aruco_interface::srv::AxisCommand_Response colay(::aruco_interface::srv::AxisCommand_Response::_colay_type arg)
  {
    msg_.colay = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Response msg_;
};

class Init_AxisCommand_Response_colax
{
public:
  Init_AxisCommand_Response_colax()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AxisCommand_Response_colay colax(::aruco_interface::srv::AxisCommand_Response::_colax_type arg)
  {
    msg_.colax = std::move(arg);
    return Init_AxisCommand_Response_colay(msg_);
  }

private:
  ::aruco_interface::srv::AxisCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aruco_interface::srv::AxisCommand_Response>()
{
  return aruco_interface::srv::builder::Init_AxisCommand_Response_colax();
}

}  // namespace aruco_interface

#endif  // ARUCO_INTERFACE__SRV__DETAIL__AXIS_COMMAND__BUILDER_HPP_
