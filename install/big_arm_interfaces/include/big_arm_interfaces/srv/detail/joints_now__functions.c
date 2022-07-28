// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from big_arm_interfaces:srv/JointsNow.idl
// generated code does not contain a copyright notice
#include "big_arm_interfaces/srv/detail/joints_now__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
big_arm_interfaces__srv__JointsNow_Request__init(big_arm_interfaces__srv__JointsNow_Request * msg)
{
  if (!msg) {
    return false;
  }
  // enable
  return true;
}

void
big_arm_interfaces__srv__JointsNow_Request__fini(big_arm_interfaces__srv__JointsNow_Request * msg)
{
  if (!msg) {
    return;
  }
  // enable
}

big_arm_interfaces__srv__JointsNow_Request *
big_arm_interfaces__srv__JointsNow_Request__create()
{
  big_arm_interfaces__srv__JointsNow_Request * msg = (big_arm_interfaces__srv__JointsNow_Request *)malloc(sizeof(big_arm_interfaces__srv__JointsNow_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(big_arm_interfaces__srv__JointsNow_Request));
  bool success = big_arm_interfaces__srv__JointsNow_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
big_arm_interfaces__srv__JointsNow_Request__destroy(big_arm_interfaces__srv__JointsNow_Request * msg)
{
  if (msg) {
    big_arm_interfaces__srv__JointsNow_Request__fini(msg);
  }
  free(msg);
}


bool
big_arm_interfaces__srv__JointsNow_Request__Sequence__init(big_arm_interfaces__srv__JointsNow_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  big_arm_interfaces__srv__JointsNow_Request * data = NULL;
  if (size) {
    data = (big_arm_interfaces__srv__JointsNow_Request *)calloc(size, sizeof(big_arm_interfaces__srv__JointsNow_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = big_arm_interfaces__srv__JointsNow_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        big_arm_interfaces__srv__JointsNow_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
big_arm_interfaces__srv__JointsNow_Request__Sequence__fini(big_arm_interfaces__srv__JointsNow_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      big_arm_interfaces__srv__JointsNow_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

big_arm_interfaces__srv__JointsNow_Request__Sequence *
big_arm_interfaces__srv__JointsNow_Request__Sequence__create(size_t size)
{
  big_arm_interfaces__srv__JointsNow_Request__Sequence * array = (big_arm_interfaces__srv__JointsNow_Request__Sequence *)malloc(sizeof(big_arm_interfaces__srv__JointsNow_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = big_arm_interfaces__srv__JointsNow_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
big_arm_interfaces__srv__JointsNow_Request__Sequence__destroy(big_arm_interfaces__srv__JointsNow_Request__Sequence * array)
{
  if (array) {
    big_arm_interfaces__srv__JointsNow_Request__Sequence__fini(array);
  }
  free(array);
}


bool
big_arm_interfaces__srv__JointsNow_Response__init(big_arm_interfaces__srv__JointsNow_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // th1
  // th2
  // th3
  // th4
  // th5
  // th6
  return true;
}

void
big_arm_interfaces__srv__JointsNow_Response__fini(big_arm_interfaces__srv__JointsNow_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // th1
  // th2
  // th3
  // th4
  // th5
  // th6
}

big_arm_interfaces__srv__JointsNow_Response *
big_arm_interfaces__srv__JointsNow_Response__create()
{
  big_arm_interfaces__srv__JointsNow_Response * msg = (big_arm_interfaces__srv__JointsNow_Response *)malloc(sizeof(big_arm_interfaces__srv__JointsNow_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(big_arm_interfaces__srv__JointsNow_Response));
  bool success = big_arm_interfaces__srv__JointsNow_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
big_arm_interfaces__srv__JointsNow_Response__destroy(big_arm_interfaces__srv__JointsNow_Response * msg)
{
  if (msg) {
    big_arm_interfaces__srv__JointsNow_Response__fini(msg);
  }
  free(msg);
}


bool
big_arm_interfaces__srv__JointsNow_Response__Sequence__init(big_arm_interfaces__srv__JointsNow_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  big_arm_interfaces__srv__JointsNow_Response * data = NULL;
  if (size) {
    data = (big_arm_interfaces__srv__JointsNow_Response *)calloc(size, sizeof(big_arm_interfaces__srv__JointsNow_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = big_arm_interfaces__srv__JointsNow_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        big_arm_interfaces__srv__JointsNow_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
big_arm_interfaces__srv__JointsNow_Response__Sequence__fini(big_arm_interfaces__srv__JointsNow_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      big_arm_interfaces__srv__JointsNow_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

big_arm_interfaces__srv__JointsNow_Response__Sequence *
big_arm_interfaces__srv__JointsNow_Response__Sequence__create(size_t size)
{
  big_arm_interfaces__srv__JointsNow_Response__Sequence * array = (big_arm_interfaces__srv__JointsNow_Response__Sequence *)malloc(sizeof(big_arm_interfaces__srv__JointsNow_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = big_arm_interfaces__srv__JointsNow_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
big_arm_interfaces__srv__JointsNow_Response__Sequence__destroy(big_arm_interfaces__srv__JointsNow_Response__Sequence * array)
{
  if (array) {
    big_arm_interfaces__srv__JointsNow_Response__Sequence__fini(array);
  }
  free(array);
}
