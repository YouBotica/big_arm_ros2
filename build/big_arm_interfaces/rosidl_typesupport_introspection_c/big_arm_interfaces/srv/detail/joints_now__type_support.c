// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from big_arm_interfaces:srv/JointsNow.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "big_arm_interfaces/srv/detail/joints_now__rosidl_typesupport_introspection_c.h"
#include "big_arm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "big_arm_interfaces/srv/detail/joints_now__functions.h"
#include "big_arm_interfaces/srv/detail/joints_now__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  big_arm_interfaces__srv__JointsNow_Request__init(message_memory);
}

void JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_fini_function(void * message_memory)
{
  big_arm_interfaces__srv__JointsNow_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_message_member_array[1] = {
  {
    "enable",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Request, enable),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_message_members = {
  "big_arm_interfaces__srv",  // message namespace
  "JointsNow_Request",  // message name
  1,  // number of fields
  sizeof(big_arm_interfaces__srv__JointsNow_Request),
  JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_message_member_array,  // message members
  JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_message_type_support_handle = {
  0,
  &JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_big_arm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, big_arm_interfaces, srv, JointsNow_Request)() {
  if (!JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_message_type_support_handle.typesupport_identifier) {
    JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &JointsNow_Request__rosidl_typesupport_introspection_c__JointsNow_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "big_arm_interfaces/srv/detail/joints_now__rosidl_typesupport_introspection_c.h"
// already included above
// #include "big_arm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "big_arm_interfaces/srv/detail/joints_now__functions.h"
// already included above
// #include "big_arm_interfaces/srv/detail/joints_now__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  big_arm_interfaces__srv__JointsNow_Response__init(message_memory);
}

void JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_fini_function(void * message_memory)
{
  big_arm_interfaces__srv__JointsNow_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_message_member_array[11] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "th1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, th1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "th2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, th2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "th3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, th3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "th4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, th4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "th5",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, th5),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "th6",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, th6),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "g2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, g2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "g22",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, g22),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "g4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, g4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "g44",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(big_arm_interfaces__srv__JointsNow_Response, g44),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_message_members = {
  "big_arm_interfaces__srv",  // message namespace
  "JointsNow_Response",  // message name
  11,  // number of fields
  sizeof(big_arm_interfaces__srv__JointsNow_Response),
  JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_message_member_array,  // message members
  JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_message_type_support_handle = {
  0,
  &JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_big_arm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, big_arm_interfaces, srv, JointsNow_Response)() {
  if (!JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_message_type_support_handle.typesupport_identifier) {
    JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &JointsNow_Response__rosidl_typesupport_introspection_c__JointsNow_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "big_arm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "big_arm_interfaces/srv/detail/joints_now__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers big_arm_interfaces__srv__detail__joints_now__rosidl_typesupport_introspection_c__JointsNow_service_members = {
  "big_arm_interfaces__srv",  // service namespace
  "JointsNow",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // big_arm_interfaces__srv__detail__joints_now__rosidl_typesupport_introspection_c__JointsNow_Request_message_type_support_handle,
  NULL  // response message
  // big_arm_interfaces__srv__detail__joints_now__rosidl_typesupport_introspection_c__JointsNow_Response_message_type_support_handle
};

static rosidl_service_type_support_t big_arm_interfaces__srv__detail__joints_now__rosidl_typesupport_introspection_c__JointsNow_service_type_support_handle = {
  0,
  &big_arm_interfaces__srv__detail__joints_now__rosidl_typesupport_introspection_c__JointsNow_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, big_arm_interfaces, srv, JointsNow_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, big_arm_interfaces, srv, JointsNow_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_big_arm_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, big_arm_interfaces, srv, JointsNow)() {
  if (!big_arm_interfaces__srv__detail__joints_now__rosidl_typesupport_introspection_c__JointsNow_service_type_support_handle.typesupport_identifier) {
    big_arm_interfaces__srv__detail__joints_now__rosidl_typesupport_introspection_c__JointsNow_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)big_arm_interfaces__srv__detail__joints_now__rosidl_typesupport_introspection_c__JointsNow_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, big_arm_interfaces, srv, JointsNow_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, big_arm_interfaces, srv, JointsNow_Response)()->data;
  }

  return &big_arm_interfaces__srv__detail__joints_now__rosidl_typesupport_introspection_c__JointsNow_service_type_support_handle;
}
