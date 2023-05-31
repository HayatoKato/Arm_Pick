// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aruco_interface:srv/AxisCommand.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACE__SRV__DETAIL__AXIS_COMMAND__STRUCT_HPP_
#define ARUCO_INTERFACE__SRV__DETAIL__AXIS_COMMAND__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__aruco_interface__srv__AxisCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__aruco_interface__srv__AxisCommand_Request __declspec(deprecated)
#endif

namespace aruco_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AxisCommand_Request_
{
  using Type = AxisCommand_Request_<ContainerAllocator>;

  explicit AxisCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ar0x = 0l;
      this->ar0y = 0l;
      this->ar1x = 0l;
      this->ar1y = 0l;
      this->ar2x = 0l;
      this->ar2y = 0l;
      this->ar3x = 0l;
      this->ar3y = 0l;
      this->xmin = 0l;
      this->ymin = 0l;
      this->xmax = 0l;
      this->ymax = 0l;
    }
  }

  explicit AxisCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ar0x = 0l;
      this->ar0y = 0l;
      this->ar1x = 0l;
      this->ar1y = 0l;
      this->ar2x = 0l;
      this->ar2y = 0l;
      this->ar3x = 0l;
      this->ar3y = 0l;
      this->xmin = 0l;
      this->ymin = 0l;
      this->xmax = 0l;
      this->ymax = 0l;
    }
  }

  // field types and members
  using _ar0x_type =
    int32_t;
  _ar0x_type ar0x;
  using _ar0y_type =
    int32_t;
  _ar0y_type ar0y;
  using _ar1x_type =
    int32_t;
  _ar1x_type ar1x;
  using _ar1y_type =
    int32_t;
  _ar1y_type ar1y;
  using _ar2x_type =
    int32_t;
  _ar2x_type ar2x;
  using _ar2y_type =
    int32_t;
  _ar2y_type ar2y;
  using _ar3x_type =
    int32_t;
  _ar3x_type ar3x;
  using _ar3y_type =
    int32_t;
  _ar3y_type ar3y;
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
  Type & set__ar0x(
    const int32_t & _arg)
  {
    this->ar0x = _arg;
    return *this;
  }
  Type & set__ar0y(
    const int32_t & _arg)
  {
    this->ar0y = _arg;
    return *this;
  }
  Type & set__ar1x(
    const int32_t & _arg)
  {
    this->ar1x = _arg;
    return *this;
  }
  Type & set__ar1y(
    const int32_t & _arg)
  {
    this->ar1y = _arg;
    return *this;
  }
  Type & set__ar2x(
    const int32_t & _arg)
  {
    this->ar2x = _arg;
    return *this;
  }
  Type & set__ar2y(
    const int32_t & _arg)
  {
    this->ar2y = _arg;
    return *this;
  }
  Type & set__ar3x(
    const int32_t & _arg)
  {
    this->ar3x = _arg;
    return *this;
  }
  Type & set__ar3y(
    const int32_t & _arg)
  {
    this->ar3y = _arg;
    return *this;
  }
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
    aruco_interface::srv::AxisCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const aruco_interface::srv::AxisCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aruco_interface::srv::AxisCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aruco_interface::srv::AxisCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::AxisCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::AxisCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::AxisCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::AxisCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aruco_interface::srv::AxisCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aruco_interface::srv::AxisCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aruco_interface__srv__AxisCommand_Request
    std::shared_ptr<aruco_interface::srv::AxisCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aruco_interface__srv__AxisCommand_Request
    std::shared_ptr<aruco_interface::srv::AxisCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AxisCommand_Request_ & other) const
  {
    if (this->ar0x != other.ar0x) {
      return false;
    }
    if (this->ar0y != other.ar0y) {
      return false;
    }
    if (this->ar1x != other.ar1x) {
      return false;
    }
    if (this->ar1y != other.ar1y) {
      return false;
    }
    if (this->ar2x != other.ar2x) {
      return false;
    }
    if (this->ar2y != other.ar2y) {
      return false;
    }
    if (this->ar3x != other.ar3x) {
      return false;
    }
    if (this->ar3y != other.ar3y) {
      return false;
    }
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
  bool operator!=(const AxisCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AxisCommand_Request_

// alias to use template instance with default allocator
using AxisCommand_Request =
  aruco_interface::srv::AxisCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aruco_interface


#ifndef _WIN32
# define DEPRECATED__aruco_interface__srv__AxisCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__aruco_interface__srv__AxisCommand_Response __declspec(deprecated)
#endif

namespace aruco_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AxisCommand_Response_
{
  using Type = AxisCommand_Response_<ContainerAllocator>;

  explicit AxisCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->colax = 0.0f;
      this->colay = 0.0f;
    }
  }

  explicit AxisCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    aruco_interface::srv::AxisCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const aruco_interface::srv::AxisCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aruco_interface::srv::AxisCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aruco_interface::srv::AxisCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::AxisCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::AxisCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aruco_interface::srv::AxisCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aruco_interface::srv::AxisCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aruco_interface::srv::AxisCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aruco_interface::srv::AxisCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aruco_interface__srv__AxisCommand_Response
    std::shared_ptr<aruco_interface::srv::AxisCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aruco_interface__srv__AxisCommand_Response
    std::shared_ptr<aruco_interface::srv::AxisCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AxisCommand_Response_ & other) const
  {
    if (this->colax != other.colax) {
      return false;
    }
    if (this->colay != other.colay) {
      return false;
    }
    return true;
  }
  bool operator!=(const AxisCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AxisCommand_Response_

// alias to use template instance with default allocator
using AxisCommand_Response =
  aruco_interface::srv::AxisCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aruco_interface

namespace aruco_interface
{

namespace srv
{

struct AxisCommand
{
  using Request = aruco_interface::srv::AxisCommand_Request;
  using Response = aruco_interface::srv::AxisCommand_Response;
};

}  // namespace srv

}  // namespace aruco_interface

#endif  // ARUCO_INTERFACE__SRV__DETAIL__AXIS_COMMAND__STRUCT_HPP_
