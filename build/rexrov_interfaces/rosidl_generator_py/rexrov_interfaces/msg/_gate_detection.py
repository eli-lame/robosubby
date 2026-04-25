# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rexrov_interfaces:msg/GateDetection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GateDetection(type):
    """Metaclass of message 'GateDetection'."""

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
            module = import_type_support('rexrov_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rexrov_interfaces.msg.GateDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gate_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gate_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gate_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gate_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gate_detection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GateDetection(metaclass=Metaclass_GateDetection):
    """Message class 'GateDetection'."""

    __slots__ = [
        '_detected',
        '_error_x',
        '_distance',
        '_pixel_x',
        '_pixel_y',
    ]

    _fields_and_field_types = {
        'detected': 'boolean',
        'error_x': 'float',
        'distance': 'float',
        'pixel_x': 'int32',
        'pixel_y': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.detected = kwargs.get('detected', bool())
        self.error_x = kwargs.get('error_x', float())
        self.distance = kwargs.get('distance', float())
        self.pixel_x = kwargs.get('pixel_x', int())
        self.pixel_y = kwargs.get('pixel_y', int())

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
        if self.detected != other.detected:
            return False
        if self.error_x != other.error_x:
            return False
        if self.distance != other.distance:
            return False
        if self.pixel_x != other.pixel_x:
            return False
        if self.pixel_y != other.pixel_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def detected(self):
        """Message field 'detected'."""
        return self._detected

    @detected.setter
    def detected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'detected' field must be of type 'bool'"
        self._detected = value

    @property
    def error_x(self):
        """Message field 'error_x'."""
        return self._error_x

    @error_x.setter
    def error_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'error_x' field must be of type 'float'"
        self._error_x = value

    @property
    def distance(self):
        """Message field 'distance'."""
        return self._distance

    @distance.setter
    def distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance' field must be of type 'float'"
        self._distance = value

    @property
    def pixel_x(self):
        """Message field 'pixel_x'."""
        return self._pixel_x

    @pixel_x.setter
    def pixel_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pixel_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'pixel_x' field must be an integer in [-2147483648, 2147483647]"
        self._pixel_x = value

    @property
    def pixel_y(self):
        """Message field 'pixel_y'."""
        return self._pixel_y

    @pixel_y.setter
    def pixel_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pixel_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'pixel_y' field must be an integer in [-2147483648, 2147483647]"
        self._pixel_y = value
