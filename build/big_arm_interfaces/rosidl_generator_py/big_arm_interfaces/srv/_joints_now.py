# generated from rosidl_generator_py/resource/_idl.py.em
# with input from big_arm_interfaces:srv/JointsNow.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_JointsNow_Request(type):
    """Metaclass of message 'JointsNow_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('big_arm_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'big_arm_interfaces.srv.JointsNow_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__joints_now__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__joints_now__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__joints_now__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__joints_now__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__joints_now__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class JointsNow_Request(metaclass=Metaclass_JointsNow_Request):
    """Message class 'JointsNow_Request'."""

    __slots__ = [
        '_enable',
    ]

    _fields_and_field_types = {
        'enable': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.enable = kwargs.get('enable', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.enable != other.enable:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def enable(self):
        """Message field 'enable'."""
        return self._enable

    @enable.setter
    def enable(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enable' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'enable' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._enable = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_JointsNow_Response(type):
    """Metaclass of message 'JointsNow_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('big_arm_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'big_arm_interfaces.srv.JointsNow_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__joints_now__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__joints_now__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__joints_now__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__joints_now__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__joints_now__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class JointsNow_Response(metaclass=Metaclass_JointsNow_Response):
    """Message class 'JointsNow_Response'."""

    __slots__ = [
        '_success',
        '_th1',
        '_th2',
        '_th3',
        '_th4',
        '_th5',
        '_th6',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'th1': 'double',
        'th2': 'double',
        'th3': 'double',
        'th4': 'double',
        'th5': 'double',
        'th6': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.th1 = kwargs.get('th1', float())
        self.th2 = kwargs.get('th2', float())
        self.th3 = kwargs.get('th3', float())
        self.th4 = kwargs.get('th4', float())
        self.th5 = kwargs.get('th5', float())
        self.th6 = kwargs.get('th6', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.th1 != other.th1:
            return False
        if self.th2 != other.th2:
            return False
        if self.th3 != other.th3:
            return False
        if self.th4 != other.th4:
            return False
        if self.th5 != other.th5:
            return False
        if self.th6 != other.th6:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @property
    def th1(self):
        """Message field 'th1'."""
        return self._th1

    @th1.setter
    def th1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'th1' field must be of type 'float'"
        self._th1 = value

    @property
    def th2(self):
        """Message field 'th2'."""
        return self._th2

    @th2.setter
    def th2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'th2' field must be of type 'float'"
        self._th2 = value

    @property
    def th3(self):
        """Message field 'th3'."""
        return self._th3

    @th3.setter
    def th3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'th3' field must be of type 'float'"
        self._th3 = value

    @property
    def th4(self):
        """Message field 'th4'."""
        return self._th4

    @th4.setter
    def th4(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'th4' field must be of type 'float'"
        self._th4 = value

    @property
    def th5(self):
        """Message field 'th5'."""
        return self._th5

    @th5.setter
    def th5(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'th5' field must be of type 'float'"
        self._th5 = value

    @property
    def th6(self):
        """Message field 'th6'."""
        return self._th6

    @th6.setter
    def th6(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'th6' field must be of type 'float'"
        self._th6 = value


class Metaclass_JointsNow(type):
    """Metaclass of service 'JointsNow'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('big_arm_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'big_arm_interfaces.srv.JointsNow')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__joints_now

            from big_arm_interfaces.srv import _joints_now
            if _joints_now.Metaclass_JointsNow_Request._TYPE_SUPPORT is None:
                _joints_now.Metaclass_JointsNow_Request.__import_type_support__()
            if _joints_now.Metaclass_JointsNow_Response._TYPE_SUPPORT is None:
                _joints_now.Metaclass_JointsNow_Response.__import_type_support__()


class JointsNow(metaclass=Metaclass_JointsNow):
    from big_arm_interfaces.srv._joints_now import JointsNow_Request as Request
    from big_arm_interfaces.srv._joints_now import JointsNow_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
