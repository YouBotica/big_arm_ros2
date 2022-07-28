// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from big_arm_interfaces:srv/JointsNow.idl
// generated code does not contain a copyright notice

#ifndef BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__TRAITS_HPP_
#define BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__TRAITS_HPP_

#include "big_arm_interfaces/srv/detail/joints_now__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<big_arm_interfaces::srv::JointsNow_Request>()
{
  return "big_arm_interfaces::srv::JointsNow_Request";
}

template<>
inline const char * name<big_arm_interfaces::srv::JointsNow_Request>()
{
  return "big_arm_interfaces/srv/JointsNow_Request";
}

template<>
struct has_fixed_size<big_arm_interfaces::srv::JointsNow_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<big_arm_interfaces::srv::JointsNow_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<big_arm_interfaces::srv::JointsNow_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<big_arm_interfaces::srv::JointsNow_Response>()
{
  return "big_arm_interfaces::srv::JointsNow_Response";
}

template<>
inline const char * name<big_arm_interfaces::srv::JointsNow_Response>()
{
  return "big_arm_interfaces/srv/JointsNow_Response";
}

template<>
struct has_fixed_size<big_arm_interfaces::srv::JointsNow_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<big_arm_interfaces::srv::JointsNow_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<big_arm_interfaces::srv::JointsNow_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<big_arm_interfaces::srv::JointsNow>()
{
  return "big_arm_interfaces::srv::JointsNow";
}

template<>
inline const char * name<big_arm_interfaces::srv::JointsNow>()
{
  return "big_arm_interfaces/srv/JointsNow";
}

template<>
struct has_fixed_size<big_arm_interfaces::srv::JointsNow>
  : std::integral_constant<
    bool,
    has_fixed_size<big_arm_interfaces::srv::JointsNow_Request>::value &&
    has_fixed_size<big_arm_interfaces::srv::JointsNow_Response>::value
  >
{
};

template<>
struct has_bounded_size<big_arm_interfaces::srv::JointsNow>
  : std::integral_constant<
    bool,
    has_bounded_size<big_arm_interfaces::srv::JointsNow_Request>::value &&
    has_bounded_size<big_arm_interfaces::srv::JointsNow_Response>::value
  >
{
};

template<>
struct is_service<big_arm_interfaces::srv::JointsNow>
  : std::true_type
{
};

template<>
struct is_service_request<big_arm_interfaces::srv::JointsNow_Request>
  : std::true_type
{
};

template<>
struct is_service_response<big_arm_interfaces::srv::JointsNow_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__TRAITS_HPP_
