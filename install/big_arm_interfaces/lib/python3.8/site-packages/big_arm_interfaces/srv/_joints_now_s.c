// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from big_arm_interfaces:srv/JointsNow.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "big_arm_interfaces/srv/detail/joints_now__struct.h"
#include "big_arm_interfaces/srv/detail/joints_now__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool big_arm_interfaces__srv__joints_now__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("big_arm_interfaces.srv._joints_now.JointsNow_Request", full_classname_dest, 52) == 0);
  }
  big_arm_interfaces__srv__JointsNow_Request * ros_message = _ros_message;
  {  // enable
    PyObject * field = PyObject_GetAttrString(_pymsg, "enable");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enable = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * big_arm_interfaces__srv__joints_now__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of JointsNow_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("big_arm_interfaces.srv._joints_now");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "JointsNow_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  big_arm_interfaces__srv__JointsNow_Request * ros_message = (big_arm_interfaces__srv__JointsNow_Request *)raw_ros_message;
  {  // enable
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->enable);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enable", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "big_arm_interfaces/srv/detail/joints_now__struct.h"
// already included above
// #include "big_arm_interfaces/srv/detail/joints_now__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool big_arm_interfaces__srv__joints_now__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("big_arm_interfaces.srv._joints_now.JointsNow_Response", full_classname_dest, 53) == 0);
  }
  big_arm_interfaces__srv__JointsNow_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // th1
    PyObject * field = PyObject_GetAttrString(_pymsg, "th1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->th1 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // th2
    PyObject * field = PyObject_GetAttrString(_pymsg, "th2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->th2 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // th3
    PyObject * field = PyObject_GetAttrString(_pymsg, "th3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->th3 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // th4
    PyObject * field = PyObject_GetAttrString(_pymsg, "th4");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->th4 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // th5
    PyObject * field = PyObject_GetAttrString(_pymsg, "th5");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->th5 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // th6
    PyObject * field = PyObject_GetAttrString(_pymsg, "th6");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->th6 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * big_arm_interfaces__srv__joints_now__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of JointsNow_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("big_arm_interfaces.srv._joints_now");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "JointsNow_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  big_arm_interfaces__srv__JointsNow_Response * ros_message = (big_arm_interfaces__srv__JointsNow_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // th1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->th1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "th1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // th2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->th2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "th2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // th3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->th3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "th3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // th4
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->th4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "th4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // th5
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->th5);
    {
      int rc = PyObject_SetAttrString(_pymessage, "th5", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // th6
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->th6);
    {
      int rc = PyObject_SetAttrString(_pymessage, "th6", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
