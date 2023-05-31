// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aruco_interface:srv/ArmCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__TRAITS_HPP_
#define ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__TRAITS_HPP_

#include "aruco_interface/srv/detail/arm_command__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aruco_interface::srv::ArmCommand_Request>()
{
  return "aruco_interface::srv::ArmCommand_Request";
}

template<>
inline const char * name<aruco_interface::srv::ArmCommand_Request>()
{
  return "aruco_interface/srv/ArmCommand_Request";
}

template<>
struct has_fixed_size<aruco_interface::srv::ArmCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<aruco_interface::srv::ArmCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<aruco_interface::srv::ArmCommand_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aruco_interface::srv::ArmCommand_Response>()
{
  return "aruco_interface::srv::ArmCommand_Response";
}

template<>
inline const char * name<aruco_interface::srv::ArmCommand_Response>()
{
  return "aruco_interface/srv/ArmCommand_Response";
}

template<>
struct has_fixed_size<aruco_interface::srv::ArmCommand_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<aruco_interface::srv::ArmCommand_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<aruco_interface::srv::ArmCommand_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aruco_interface::srv::ArmCommand>()
{
  return "aruco_interface::srv::ArmCommand";
}

template<>
inline const char * name<aruco_interface::srv::ArmCommand>()
{
  return "aruco_interface/srv/ArmCommand";
}

template<>
struct has_fixed_size<aruco_interface::srv::ArmCommand>
  : std::integral_constant<
    bool,
    has_fixed_size<aruco_interface::srv::ArmCommand_Request>::value &&
    has_fixed_size<aruco_interface::srv::ArmCommand_Response>::value
  >
{
};

template<>
struct has_bounded_size<aruco_interface::srv::ArmCommand>
  : std::integral_constant<
    bool,
    has_bounded_size<aruco_interface::srv::ArmCommand_Request>::value &&
    has_bounded_size<aruco_interface::srv::ArmCommand_Response>::value
  >
{
};

template<>
struct is_service<aruco_interface::srv::ArmCommand>
  : std::true_type
{
};

template<>
struct is_service_request<aruco_interface::srv::ArmCommand_Request>
  : std::true_type
{
};

template<>
struct is_service_response<aruco_interface::srv::ArmCommand_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__TRAITS_HPP_
