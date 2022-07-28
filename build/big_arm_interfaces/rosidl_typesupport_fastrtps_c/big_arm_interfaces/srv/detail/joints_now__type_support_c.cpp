// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from big_arm_interfaces:srv/JointsNow.idl
// generated code does not contain a copyright notice
#include "big_arm_interfaces/srv/detail/joints_now__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "big_arm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "big_arm_interfaces/srv/detail/joints_now__struct.h"
#include "big_arm_interfaces/srv/detail/joints_now__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _JointsNow_Request__ros_msg_type = big_arm_interfaces__srv__JointsNow_Request;

static bool _JointsNow_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _JointsNow_Request__ros_msg_type * ros_message = static_cast<const _JointsNow_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: enable
  {
    cdr << ros_message->enable;
  }

  return true;
}

static bool _JointsNow_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _JointsNow_Request__ros_msg_type * ros_message = static_cast<_JointsNow_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: enable
  {
    cdr >> ros_message->enable;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_big_arm_interfaces
size_t get_serialized_size_big_arm_interfaces__srv__JointsNow_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _JointsNow_Request__ros_msg_type * ros_message = static_cast<const _JointsNow_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name enable
  {
    size_t item_size = sizeof(ros_message->enable);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _JointsNow_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_big_arm_interfaces__srv__JointsNow_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_big_arm_interfaces
size_t max_serialized_size_big_arm_interfaces__srv__JointsNow_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: enable
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _JointsNow_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_big_arm_interfaces__srv__JointsNow_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_JointsNow_Request = {
  "big_arm_interfaces::srv",
  "JointsNow_Request",
  _JointsNow_Request__cdr_serialize,
  _JointsNow_Request__cdr_deserialize,
  _JointsNow_Request__get_serialized_size,
  _JointsNow_Request__max_serialized_size
};

static rosidl_message_type_support_t _JointsNow_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_JointsNow_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, big_arm_interfaces, srv, JointsNow_Request)() {
  return &_JointsNow_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "big_arm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "big_arm_interfaces/srv/detail/joints_now__struct.h"
// already included above
// #include "big_arm_interfaces/srv/detail/joints_now__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _JointsNow_Response__ros_msg_type = big_arm_interfaces__srv__JointsNow_Response;

static bool _JointsNow_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _JointsNow_Response__ros_msg_type * ros_message = static_cast<const _JointsNow_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  // Field name: th1
  {
    cdr << ros_message->th1;
  }

  // Field name: th2
  {
    cdr << ros_message->th2;
  }

  // Field name: th3
  {
    cdr << ros_message->th3;
  }

  // Field name: th4
  {
    cdr << ros_message->th4;
  }

  // Field name: th5
  {
    cdr << ros_message->th5;
  }

  // Field name: th6
  {
    cdr << ros_message->th6;
  }

  return true;
}

static bool _JointsNow_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _JointsNow_Response__ros_msg_type * ros_message = static_cast<_JointsNow_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  // Field name: th1
  {
    cdr >> ros_message->th1;
  }

  // Field name: th2
  {
    cdr >> ros_message->th2;
  }

  // Field name: th3
  {
    cdr >> ros_message->th3;
  }

  // Field name: th4
  {
    cdr >> ros_message->th4;
  }

  // Field name: th5
  {
    cdr >> ros_message->th5;
  }

  // Field name: th6
  {
    cdr >> ros_message->th6;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_big_arm_interfaces
size_t get_serialized_size_big_arm_interfaces__srv__JointsNow_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _JointsNow_Response__ros_msg_type * ros_message = static_cast<const _JointsNow_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name th1
  {
    size_t item_size = sizeof(ros_message->th1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name th2
  {
    size_t item_size = sizeof(ros_message->th2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name th3
  {
    size_t item_size = sizeof(ros_message->th3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name th4
  {
    size_t item_size = sizeof(ros_message->th4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name th5
  {
    size_t item_size = sizeof(ros_message->th5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name th6
  {
    size_t item_size = sizeof(ros_message->th6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _JointsNow_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_big_arm_interfaces__srv__JointsNow_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_big_arm_interfaces
size_t max_serialized_size_big_arm_interfaces__srv__JointsNow_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: th1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: th2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: th3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: th4
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: th5
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: th6
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _JointsNow_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_big_arm_interfaces__srv__JointsNow_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_JointsNow_Response = {
  "big_arm_interfaces::srv",
  "JointsNow_Response",
  _JointsNow_Response__cdr_serialize,
  _JointsNow_Response__cdr_deserialize,
  _JointsNow_Response__get_serialized_size,
  _JointsNow_Response__max_serialized_size
};

static rosidl_message_type_support_t _JointsNow_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_JointsNow_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, big_arm_interfaces, srv, JointsNow_Response)() {
  return &_JointsNow_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "big_arm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "big_arm_interfaces/srv/joints_now.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t JointsNow__callbacks = {
  "big_arm_interfaces::srv",
  "JointsNow",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, big_arm_interfaces, srv, JointsNow_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, big_arm_interfaces, srv, JointsNow_Response)(),
};

static rosidl_service_type_support_t JointsNow__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &JointsNow__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, big_arm_interfaces, srv, JointsNow)() {
  return &JointsNow__handle;
}

#if defined(__cplusplus)
}
#endif
