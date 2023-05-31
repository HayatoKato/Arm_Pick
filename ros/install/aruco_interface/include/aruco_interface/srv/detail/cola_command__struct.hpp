// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aruco_interface:srv/ColaCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__COLA_COMMAND__STRUCT_HPP_
#define ARUCO_INTERFACE__SRV__DETAIL__COLA_COMMAND__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__aruco_interface__srv__ColaCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__aruco_interface__srv__ColaCommand_Request __declspec(deprecated)
#endif

namespace aruco_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ColaCommand_Request_
{
  using Type = ColaCommand_Request_<ContainerAllocator>;

  explicit ColaCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
    }
  }

  explicit ColaCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _command_type command;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aruco_interface::srv::ColaCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const aruco_interface::srv::ColaCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aruco_interface::srv::ColaCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aruco_interface::srv::ColaCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::ColaCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::ColaCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::ColaCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::ColaCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aruco_interface::srv::ColaCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aruco_interface::srv::ColaCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aruco_interface__srv__ColaCommand_Request
    std::shared_ptr<aruco_interface::srv::ColaCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aruco_interface__srv__ColaCommand_Request
    std::shared_ptr<aruco_interface::srv::ColaCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ColaCommand_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    return true;
  }
  bool operator!=(const ColaCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ColaCommand_Request_

// alias to use template instance with default allocator
using ColaCommand_Request =
  aruco_interface::srv::ColaCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aruco_interface


#ifndef _WIN32
# define DEPRECATED__aruco_interface__srv__ColaCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__aruco_interface__srv__ColaCommand_Response __declspec(deprecated)
#endif

namespace aruco_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ColaCommand_Response_
{
  using Type = ColaCommand_Response_<ContainerAllocator>;

  explicit ColaCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->xmin = 0l;
      this->ymin = 0l;
      this->xmax = 0l;
      this->ymax = 0l;
    }
  }

  explicit ColaCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->xmin = 0l;
      this->ymin = 0l;
      this->xmax = 0l;
      this->ymax = 0l;
    }
  }

  // field types and members
  using _xmin_type =
    int32_t;
  _xmin_type xmin;
  using _ymin_type =
    int32_t;
  _ymin_type ymin;
  using _xmax_type =
    int32_t;
  _xmax_type xmax;
  using _ymax_type =
    int32_t;
  _ymax_type ymax;

  // setters for named parameter idiom
  Type & set__xmin(
    const int32_t & _arg)
  {
    this->xmin = _arg;
    return *this;
  }
  Type & set__ymin(
    const int32_t & _arg)
  {
    this->ymin = _arg;
    return *this;
  }
  Type & set__xmax(
    const int32_t & _arg)
  {
    this->xmax = _arg;
    return *this;
  }
  Type & set__ymax(
    const int32_t & _arg)
  {
    this->ymax = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aruco_interface::srv::ColaCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const aruco_interface::srv::ColaCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aruco_interface::srv::ColaCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aruco_interface::srv::ColaCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::ColaCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::ColaCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::ColaCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::ColaCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aruco_interface::srv::ColaCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aruco_interface::srv::ColaCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aruco_interface__srv__ColaCommand_Response
    std::shared_ptr<aruco_interface::srv::ColaCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aruco_interface__srv__ColaCommand_Response
    std::shared_ptr<aruco_interface::srv::ColaCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ColaCommand_Response_ & other) const
  {
    if (this->xmin != other.xmin) {
      return false;
    }
    if (this->ymin != other.ymin) {
      return false;
    }
    if (this->xmax != other.xmax) {
      return false;
    }
    if (this->ymax != other.ymax) {
      return false;
    }
    return true;
  }
  bool operator!=(const ColaCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ColaCommand_Response_

// alias to use template instance with default allocator
using ColaCommand_Response =
  aruco_interface::srv::ColaCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aruco_interface

namespace aruco_interface
{

namespace srv
{

struct ColaCommand
{
  using Request = aruco_interface::srv::ColaCommand_Request;
  using Response = aruco_interface::srv::ColaCommand_Response;
};

}  // namespace srv

}  // namespace aruco_interface

#endif  // ARUCO_INTERFACE__SRV__DETAIL__COLA_COMMAND__STRUCT_HPP_
