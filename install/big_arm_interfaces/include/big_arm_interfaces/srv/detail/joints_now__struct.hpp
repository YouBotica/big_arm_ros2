// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from big_arm_interfaces:srv/JointsNow.idl
// generated code does not contain a copyright notice

#ifndef BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__STRUCT_HPP_
#define BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__big_arm_interfaces__srv__JointsNow_Request __attribute__((deprecated))
#else
# define DEPRECATED__big_arm_interfaces__srv__JointsNow_Request __declspec(deprecated)
#endif

namespace big_arm_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct JointsNow_Request_
{
  using Type = JointsNow_Request_<ContainerAllocator>;

  explicit JointsNow_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enable = 0ll;
    }
  }

  explicit JointsNow_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enable = 0ll;
    }
  }

  // field types and members
  using _enable_type =
    int64_t;
  _enable_type enable;

  // setters for named parameter idiom
  Type & set__enable(
    const int64_t & _arg)
  {
    this->enable = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__big_arm_interfaces__srv__JointsNow_Request
    std::shared_ptr<big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__big_arm_interfaces__srv__JointsNow_Request
    std::shared_ptr<big_arm_interfaces::srv::JointsNow_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointsNow_Request_ & other) const
  {
    if (this->enable != other.enable) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointsNow_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointsNow_Request_

// alias to use template instance with default allocator
using JointsNow_Request =
  big_arm_interfaces::srv::JointsNow_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace big_arm_interfaces


#ifndef _WIN32
# define DEPRECATED__big_arm_interfaces__srv__JointsNow_Response __attribute__((deprecated))
#else
# define DEPRECATED__big_arm_interfaces__srv__JointsNow_Response __declspec(deprecated)
#endif

namespace big_arm_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct JointsNow_Response_
{
  using Type = JointsNow_Response_<ContainerAllocator>;

  explicit JointsNow_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->th1 = 0.0;
      this->th2 = 0.0;
      this->th3 = 0.0;
      this->th4 = 0.0;
      this->th5 = 0.0;
      this->th6 = 0.0;
    }
  }

  explicit JointsNow_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->th1 = 0.0;
      this->th2 = 0.0;
      this->th3 = 0.0;
      this->th4 = 0.0;
      this->th5 = 0.0;
      this->th6 = 0.0;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _th1_type =
    double;
  _th1_type th1;
  using _th2_type =
    double;
  _th2_type th2;
  using _th3_type =
    double;
  _th3_type th3;
  using _th4_type =
    double;
  _th4_type th4;
  using _th5_type =
    double;
  _th5_type th5;
  using _th6_type =
    double;
  _th6_type th6;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__th1(
    const double & _arg)
  {
    this->th1 = _arg;
    return *this;
  }
  Type & set__th2(
    const double & _arg)
  {
    this->th2 = _arg;
    return *this;
  }
  Type & set__th3(
    const double & _arg)
  {
    this->th3 = _arg;
    return *this;
  }
  Type & set__th4(
    const double & _arg)
  {
    this->th4 = _arg;
    return *this;
  }
  Type & set__th5(
    const double & _arg)
  {
    this->th5 = _arg;
    return *this;
  }
  Type & set__th6(
    const double & _arg)
  {
    this->th6 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__big_arm_interfaces__srv__JointsNow_Response
    std::shared_ptr<big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__big_arm_interfaces__srv__JointsNow_Response
    std::shared_ptr<big_arm_interfaces::srv::JointsNow_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointsNow_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->th1 != other.th1) {
      return false;
    }
    if (this->th2 != other.th2) {
      return false;
    }
    if (this->th3 != other.th3) {
      return false;
    }
    if (this->th4 != other.th4) {
      return false;
    }
    if (this->th5 != other.th5) {
      return false;
    }
    if (this->th6 != other.th6) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointsNow_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointsNow_Response_

// alias to use template instance with default allocator
using JointsNow_Response =
  big_arm_interfaces::srv::JointsNow_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace big_arm_interfaces

namespace big_arm_interfaces
{

namespace srv
{

struct JointsNow
{
  using Request = big_arm_interfaces::srv::JointsNow_Request;
  using Response = big_arm_interfaces::srv::JointsNow_Response;
};

}  // namespace srv

}  // namespace big_arm_interfaces

#endif  // BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__STRUCT_HPP_
