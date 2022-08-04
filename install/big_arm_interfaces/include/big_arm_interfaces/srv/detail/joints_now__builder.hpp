// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from big_arm_interfaces:srv/JointsNow.idl
// generated code does not contain a copyright notice

#ifndef BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__BUILDER_HPP_
#define BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__BUILDER_HPP_

#include "big_arm_interfaces/srv/detail/joints_now__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace big_arm_interfaces
{

namespace srv
{

namespace builder
{

class Init_JointsNow_Request_enable
{
public:
  Init_JointsNow_Request_enable()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::big_arm_interfaces::srv::JointsNow_Request enable(::big_arm_interfaces::srv::JointsNow_Request::_enable_type arg)
  {
    msg_.enable = std::move(arg);
    return std::move(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::big_arm_interfaces::srv::JointsNow_Request>()
{
  return big_arm_interfaces::srv::builder::Init_JointsNow_Request_enable();
}

}  // namespace big_arm_interfaces


namespace big_arm_interfaces
{

namespace srv
{

namespace builder
{

class Init_JointsNow_Response_g44
{
public:
  explicit Init_JointsNow_Response_g44(::big_arm_interfaces::srv::JointsNow_Response & msg)
  : msg_(msg)
  {}
  ::big_arm_interfaces::srv::JointsNow_Response g44(::big_arm_interfaces::srv::JointsNow_Response::_g44_type arg)
  {
    msg_.g44 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

class Init_JointsNow_Response_g4
{
public:
  explicit Init_JointsNow_Response_g4(::big_arm_interfaces::srv::JointsNow_Response & msg)
  : msg_(msg)
  {}
  Init_JointsNow_Response_g44 g4(::big_arm_interfaces::srv::JointsNow_Response::_g4_type arg)
  {
    msg_.g4 = std::move(arg);
    return Init_JointsNow_Response_g44(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

class Init_JointsNow_Response_g22
{
public:
  explicit Init_JointsNow_Response_g22(::big_arm_interfaces::srv::JointsNow_Response & msg)
  : msg_(msg)
  {}
  Init_JointsNow_Response_g4 g22(::big_arm_interfaces::srv::JointsNow_Response::_g22_type arg)
  {
    msg_.g22 = std::move(arg);
    return Init_JointsNow_Response_g4(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

class Init_JointsNow_Response_g2
{
public:
  explicit Init_JointsNow_Response_g2(::big_arm_interfaces::srv::JointsNow_Response & msg)
  : msg_(msg)
  {}
  Init_JointsNow_Response_g22 g2(::big_arm_interfaces::srv::JointsNow_Response::_g2_type arg)
  {
    msg_.g2 = std::move(arg);
    return Init_JointsNow_Response_g22(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

class Init_JointsNow_Response_th6
{
public:
  explicit Init_JointsNow_Response_th6(::big_arm_interfaces::srv::JointsNow_Response & msg)
  : msg_(msg)
  {}
  Init_JointsNow_Response_g2 th6(::big_arm_interfaces::srv::JointsNow_Response::_th6_type arg)
  {
    msg_.th6 = std::move(arg);
    return Init_JointsNow_Response_g2(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

class Init_JointsNow_Response_th5
{
public:
  explicit Init_JointsNow_Response_th5(::big_arm_interfaces::srv::JointsNow_Response & msg)
  : msg_(msg)
  {}
  Init_JointsNow_Response_th6 th5(::big_arm_interfaces::srv::JointsNow_Response::_th5_type arg)
  {
    msg_.th5 = std::move(arg);
    return Init_JointsNow_Response_th6(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

class Init_JointsNow_Response_th4
{
public:
  explicit Init_JointsNow_Response_th4(::big_arm_interfaces::srv::JointsNow_Response & msg)
  : msg_(msg)
  {}
  Init_JointsNow_Response_th5 th4(::big_arm_interfaces::srv::JointsNow_Response::_th4_type arg)
  {
    msg_.th4 = std::move(arg);
    return Init_JointsNow_Response_th5(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

class Init_JointsNow_Response_th3
{
public:
  explicit Init_JointsNow_Response_th3(::big_arm_interfaces::srv::JointsNow_Response & msg)
  : msg_(msg)
  {}
  Init_JointsNow_Response_th4 th3(::big_arm_interfaces::srv::JointsNow_Response::_th3_type arg)
  {
    msg_.th3 = std::move(arg);
    return Init_JointsNow_Response_th4(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

class Init_JointsNow_Response_th2
{
public:
  explicit Init_JointsNow_Response_th2(::big_arm_interfaces::srv::JointsNow_Response & msg)
  : msg_(msg)
  {}
  Init_JointsNow_Response_th3 th2(::big_arm_interfaces::srv::JointsNow_Response::_th2_type arg)
  {
    msg_.th2 = std::move(arg);
    return Init_JointsNow_Response_th3(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

class Init_JointsNow_Response_th1
{
public:
  explicit Init_JointsNow_Response_th1(::big_arm_interfaces::srv::JointsNow_Response & msg)
  : msg_(msg)
  {}
  Init_JointsNow_Response_th2 th1(::big_arm_interfaces::srv::JointsNow_Response::_th1_type arg)
  {
    msg_.th1 = std::move(arg);
    return Init_JointsNow_Response_th2(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

class Init_JointsNow_Response_success
{
public:
  Init_JointsNow_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointsNow_Response_th1 success(::big_arm_interfaces::srv::JointsNow_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_JointsNow_Response_th1(msg_);
  }

private:
  ::big_arm_interfaces::srv::JointsNow_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::big_arm_interfaces::srv::JointsNow_Response>()
{
  return big_arm_interfaces::srv::builder::Init_JointsNow_Response_success();
}

}  // namespace big_arm_interfaces

#endif  // BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__BUILDER_HPP_
