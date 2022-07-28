// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from big_arm_interfaces:srv/JointsNow.idl
// generated code does not contain a copyright notice

#ifndef BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__STRUCT_H_
#define BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/JointsNow in the package big_arm_interfaces.
typedef struct big_arm_interfaces__srv__JointsNow_Request
{
  int64_t enable;
} big_arm_interfaces__srv__JointsNow_Request;

// Struct for a sequence of big_arm_interfaces__srv__JointsNow_Request.
typedef struct big_arm_interfaces__srv__JointsNow_Request__Sequence
{
  big_arm_interfaces__srv__JointsNow_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} big_arm_interfaces__srv__JointsNow_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/JointsNow in the package big_arm_interfaces.
typedef struct big_arm_interfaces__srv__JointsNow_Response
{
  bool success;
  double th1;
  double th2;
  double th3;
  double th4;
  double th5;
  double th6;
} big_arm_interfaces__srv__JointsNow_Response;

// Struct for a sequence of big_arm_interfaces__srv__JointsNow_Response.
typedef struct big_arm_interfaces__srv__JointsNow_Response__Sequence
{
  big_arm_interfaces__srv__JointsNow_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} big_arm_interfaces__srv__JointsNow_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__STRUCT_H_
