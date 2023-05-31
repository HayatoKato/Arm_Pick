// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aruco_interface:srv/ArmCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__STRUCT_HPP_
#define ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__aruco_interface__srv__ArmCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__aruco_interface__srv__ArmCommand_Request __declspec(deprecated)
#endif

namespace aruco_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ArmCommand_Request_
{
  using Type = ArmCommand_Request_<ContainerAllocator>;

  explicit ArmCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->colax = 0.0f;
      this->colay = 0.0f;
    }
  }

  explicit ArmCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->colax = 0.0f;
      this->colay = 0.0f;
    }
  }

  // field types and members
  using _colax_type =
    float;
  _colax_type colax;
  using _colay_type =
    float;
  _colay_type colay;

  // setters for named parameter idiom
  Type & set__colax(
    const float & _arg)
  {
    this->colax = _arg;
    return *this;
  }
  Type & set__colay(
    const float & _arg)
  {
    this->colay = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aruco_interface::srv::ArmCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const aruco_interface::srv::ArmCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aruco_interface::srv::ArmCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aruco_interface::srv::ArmCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::ArmCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::ArmCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::ArmCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::ArmCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aruco_interface::srv::ArmCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aruco_interface::srv::ArmCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aruco_interface__srv__ArmCommand_Request
    std::shared_ptr<aruco_interface::srv::ArmCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aruco_interface__srv__ArmCommand_Request
    std::shared_ptr<aruco_interface::srv::ArmCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmCommand_Request_ & other) const
  {
    if (this->colax != other.colax) {
      return false;
    }
    if (this->colay != other.colay) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmCommand_Request_

// alias to use template instance with default allocator
using ArmCommand_Request =
  aruco_interface::srv::ArmCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aruco_interface


#ifndef _WIN32
# define DEPRECATED__aruco_interface__srv__ArmCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__aruco_interface__srv__ArmCommand_Response __declspec(deprecated)
#endif

namespace aruco_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ArmCommand_Response_
{
  using Type = ArmCommand_Response_<ContainerAllocator>;

  explicit ArmCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->catchcola = false;
    }
  }

  explicit ArmCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->catchcola = false;
    }
  }

  // field types and members
  using _catchcola_type =
    bool;
  _catchcola_type catchcola;

  // setters for named parameter idiom
  Type & set__catchcola(
    const bool & _arg)
  {
    this->catchcola = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aruco_interface::srv::ArmCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const aruco_interface::srv::ArmCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aruco_interface::srv::ArmCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aruco_interface::srv::ArmCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::ArmCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::ArmCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::ArmCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::ArmCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aruco_interface::srv::ArmCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aruco_interface::srv::ArmCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aruco_interface__srv__ArmCommand_Response
    std::shared_ptr<aruco_interface::srv::ArmCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aruco_interface__srv__ArmCommand_Response
    std::shared_ptr<aruco_interface::srv::ArmCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmCommand_Response_ & other) const
  {
    if (this->catchcola != other.catchcola) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmCommand_Response_

// alias to use template instance with default allocator
using ArmCommand_Response =
  aruco_interface::srv::ArmCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aruco_interface

namespace aruco_interface
{

namespace srv
{

struct ArmCommand
{
  using Request = aruco_interface::srv::ArmCommand_Request;
  using Response = aruco_interface::srv::ArmCommand_Response;
};

}  // namespace srv

}  // namespace aruco_interface

#endif  // ARUCO_INTERFACE__SRV__DETAIL__ARM_COMMAND__STRUCT_HPP_
