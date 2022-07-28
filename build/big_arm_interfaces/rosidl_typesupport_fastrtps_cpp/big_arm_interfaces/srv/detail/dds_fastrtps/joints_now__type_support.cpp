// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from big_arm_interfaces:srv/JointsNow.idl
// generated code does not contain a copyright notice
#include "big_arm_interfaces/srv/detail/joints_now__rosidl_typesupport_fastrtps_cpp.hpp"
#include "big_arm_interfaces/srv/detail/joints_now__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace big_arm_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_big_arm_interfaces
cdr_serialize(
  const big_arm_interfaces::srv::JointsNow_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: enable
  cdr << ros_message.enable;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_big_arm_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  big_arm_interfaces::srv::JointsNow_Request & ros_message)
{
  // Member: enable
  cdr >> ros_message.enable;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_big_arm_interfaces
get_serialized_size(
  const big_arm_interfaces::srv::JointsNow_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: enable
  {
    size_t item_size = sizeof(ros_message.enable);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_big_arm_interfaces
max_serialized_size_JointsNow_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: enable
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _JointsNow_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const big_arm_interfaces::srv::JointsNow_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _JointsNow_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<big_arm_interfaces::srv::JointsNow_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _JointsNow_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const big_arm_interfaces::srv::JointsNow_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _JointsNow_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_JointsNow_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _JointsNow_Request__callbacks = {
  "big_arm_interfaces::srv",
  "JointsNow_Request",
  _JointsNow_Request__cdr_serialize,
  _JointsNow_Request__cdr_deserialize,
  _JointsNow_Request__get_serialized_size,
  _JointsNow_Request__max_serialized_size
};

static rosidl_message_type_support_t _JointsNow_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_JointsNow_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace big_arm_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_big_arm_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<big_arm_interfaces::srv::JointsNow_Request>()
{
  return &big_arm_interfaces::srv::typesupport_fastrtps_cpp::_JointsNow_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, big_arm_interfaces, srv, JointsNow_Request)() {
  return &big_arm_interfaces::srv::typesupport_fastrtps_cpp::_JointsNow_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace big_arm_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_big_arm_interfaces
cdr_serialize(
  const big_arm_interfaces::srv::JointsNow_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: success
  cdr << (ros_message.success ? true : false);
  // Member: th1
  cdr << ros_message.th1;
  // Member: th2
  cdr << ros_message.th2;
  // Member: th3
  cdr << ros_message.th3;
  // Member: th4
  cdr << ros_message.th4;
  // Member: th5
  cdr << ros_message.th5;
  // Member: th6
  cdr << ros_message.th6;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_big_arm_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  big_arm_interfaces::srv::JointsNow_Response & ros_message)
{
  // Member: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.success = tmp ? true : false;
  }

  // Member: th1
  cdr >> ros_message.th1;

  // Member: th2
  cdr >> ros_message.th2;

  // Member: th3
  cdr >> ros_message.th3;

  // Member: th4
  cdr >> ros_message.th4;

  // Member: th5
  cdr >> ros_message.th5;

  // Member: th6
  cdr >> ros_message.th6;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_big_arm_interfaces
get_serialized_size(
  const big_arm_interfaces::srv::JointsNow_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: success
  {
    size_t item_size = sizeof(ros_message.success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: th1
  {
    size_t item_size = sizeof(ros_message.th1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: th2
  {
    size_t item_size = sizeof(ros_message.th2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: th3
  {
    size_t item_size = sizeof(ros_message.th3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: th4
  {
    size_t item_size = sizeof(ros_message.th4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: th5
  {
    size_t item_size = sizeof(ros_message.th5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: th6
  {
    size_t item_size = sizeof(ros_message.th6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_big_arm_interfaces
max_serialized_size_JointsNow_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: th1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: th2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: th3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: th4
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: th5
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: th6
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _JointsNow_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const big_arm_interfaces::srv::JointsNow_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _JointsNow_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<big_arm_interfaces::srv::JointsNow_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _JointsNow_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const big_arm_interfaces::srv::JointsNow_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _JointsNow_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_JointsNow_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _JointsNow_Response__callbacks = {
  "big_arm_interfaces::srv",
  "JointsNow_Response",
  _JointsNow_Response__cdr_serialize,
  _JointsNow_Response__cdr_deserialize,
  _JointsNow_Response__get_serialized_size,
  _JointsNow_Response__max_serialized_size
};

static rosidl_message_type_support_t _JointsNow_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_JointsNow_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace big_arm_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_big_arm_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<big_arm_interfaces::srv::JointsNow_Response>()
{
  return &big_arm_interfaces::srv::typesupport_fastrtps_cpp::_JointsNow_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, big_arm_interfaces, srv, JointsNow_Response)() {
  return &big_arm_interfaces::srv::typesupport_fastrtps_cpp::_JointsNow_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace big_arm_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _JointsNow__callbacks = {
  "big_arm_interfaces::srv",
  "JointsNow",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, big_arm_interfaces, srv, JointsNow_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, big_arm_interfaces, srv, JointsNow_Response)(),
};

static rosidl_service_type_support_t _JointsNow__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_JointsNow__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace big_arm_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_big_arm_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<big_arm_interfaces::srv::JointsNow>()
{
  return &big_arm_interfaces::srv::typesupport_fastrtps_cpp::_JointsNow__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, big_arm_interfaces, srv, JointsNow)() {
  return &big_arm_interfaces::srv::typesupport_fastrtps_cpp::_JointsNow__handle;
}

#ifdef __cplusplus
}
#endif
