// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from big_arm_interfaces:srv/JointsNow.idl
// generated code does not contain a copyright notice

#ifndef BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__FUNCTIONS_H_
#define BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "big_arm_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "big_arm_interfaces/srv/detail/joints_now__struct.h"

/// Initialize srv/JointsNow message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * big_arm_interfaces__srv__JointsNow_Request
 * )) before or use
 * big_arm_interfaces__srv__JointsNow_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
bool
big_arm_interfaces__srv__JointsNow_Request__init(big_arm_interfaces__srv__JointsNow_Request * msg);

/// Finalize srv/JointsNow message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
void
big_arm_interfaces__srv__JointsNow_Request__fini(big_arm_interfaces__srv__JointsNow_Request * msg);

/// Create srv/JointsNow message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * big_arm_interfaces__srv__JointsNow_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
big_arm_interfaces__srv__JointsNow_Request *
big_arm_interfaces__srv__JointsNow_Request__create();

/// Destroy srv/JointsNow message.
/**
 * It calls
 * big_arm_interfaces__srv__JointsNow_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
void
big_arm_interfaces__srv__JointsNow_Request__destroy(big_arm_interfaces__srv__JointsNow_Request * msg);


/// Initialize array of srv/JointsNow messages.
/**
 * It allocates the memory for the number of elements and calls
 * big_arm_interfaces__srv__JointsNow_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
bool
big_arm_interfaces__srv__JointsNow_Request__Sequence__init(big_arm_interfaces__srv__JointsNow_Request__Sequence * array, size_t size);

/// Finalize array of srv/JointsNow messages.
/**
 * It calls
 * big_arm_interfaces__srv__JointsNow_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
void
big_arm_interfaces__srv__JointsNow_Request__Sequence__fini(big_arm_interfaces__srv__JointsNow_Request__Sequence * array);

/// Create array of srv/JointsNow messages.
/**
 * It allocates the memory for the array and calls
 * big_arm_interfaces__srv__JointsNow_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
big_arm_interfaces__srv__JointsNow_Request__Sequence *
big_arm_interfaces__srv__JointsNow_Request__Sequence__create(size_t size);

/// Destroy array of srv/JointsNow messages.
/**
 * It calls
 * big_arm_interfaces__srv__JointsNow_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
void
big_arm_interfaces__srv__JointsNow_Request__Sequence__destroy(big_arm_interfaces__srv__JointsNow_Request__Sequence * array);

/// Initialize srv/JointsNow message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * big_arm_interfaces__srv__JointsNow_Response
 * )) before or use
 * big_arm_interfaces__srv__JointsNow_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
bool
big_arm_interfaces__srv__JointsNow_Response__init(big_arm_interfaces__srv__JointsNow_Response * msg);

/// Finalize srv/JointsNow message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
void
big_arm_interfaces__srv__JointsNow_Response__fini(big_arm_interfaces__srv__JointsNow_Response * msg);

/// Create srv/JointsNow message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * big_arm_interfaces__srv__JointsNow_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
big_arm_interfaces__srv__JointsNow_Response *
big_arm_interfaces__srv__JointsNow_Response__create();

/// Destroy srv/JointsNow message.
/**
 * It calls
 * big_arm_interfaces__srv__JointsNow_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
void
big_arm_interfaces__srv__JointsNow_Response__destroy(big_arm_interfaces__srv__JointsNow_Response * msg);


/// Initialize array of srv/JointsNow messages.
/**
 * It allocates the memory for the number of elements and calls
 * big_arm_interfaces__srv__JointsNow_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
bool
big_arm_interfaces__srv__JointsNow_Response__Sequence__init(big_arm_interfaces__srv__JointsNow_Response__Sequence * array, size_t size);

/// Finalize array of srv/JointsNow messages.
/**
 * It calls
 * big_arm_interfaces__srv__JointsNow_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
void
big_arm_interfaces__srv__JointsNow_Response__Sequence__fini(big_arm_interfaces__srv__JointsNow_Response__Sequence * array);

/// Create array of srv/JointsNow messages.
/**
 * It allocates the memory for the array and calls
 * big_arm_interfaces__srv__JointsNow_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
big_arm_interfaces__srv__JointsNow_Response__Sequence *
big_arm_interfaces__srv__JointsNow_Response__Sequence__create(size_t size);

/// Destroy array of srv/JointsNow messages.
/**
 * It calls
 * big_arm_interfaces__srv__JointsNow_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_big_arm_interfaces
void
big_arm_interfaces__srv__JointsNow_Response__Sequence__destroy(big_arm_interfaces__srv__JointsNow_Response__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // BIG_ARM_INTERFACES__SRV__DETAIL__JOINTS_NOW__FUNCTIONS_H_
