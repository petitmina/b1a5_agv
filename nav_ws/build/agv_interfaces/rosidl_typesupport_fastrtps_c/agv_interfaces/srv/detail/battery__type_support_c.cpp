// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from agv_interfaces:srv/Battery.idl
// generated code does not contain a copyright notice
#include "agv_interfaces/srv/detail/battery__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "agv_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "agv_interfaces/srv/detail/battery__struct.h"
#include "agv_interfaces/srv/detail/battery__functions.h"
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


using _Battery_Request__ros_msg_type = agv_interfaces__srv__Battery_Request;

static bool _Battery_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Battery_Request__ros_msg_type * ros_message = static_cast<const _Battery_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

static bool _Battery_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Battery_Request__ros_msg_type * ros_message = static_cast<_Battery_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_agv_interfaces
size_t get_serialized_size_agv_interfaces__srv__Battery_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Battery_Request__ros_msg_type * ros_message = static_cast<const _Battery_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Battery_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_agv_interfaces__srv__Battery_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_agv_interfaces
size_t max_serialized_size_agv_interfaces__srv__Battery_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _Battery_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_agv_interfaces__srv__Battery_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Battery_Request = {
  "agv_interfaces::srv",
  "Battery_Request",
  _Battery_Request__cdr_serialize,
  _Battery_Request__cdr_deserialize,
  _Battery_Request__get_serialized_size,
  _Battery_Request__max_serialized_size
};

static rosidl_message_type_support_t _Battery_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Battery_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, agv_interfaces, srv, Battery_Request)() {
  return &_Battery_Request__type_support;
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
// #include "agv_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "agv_interfaces/srv/detail/battery__struct.h"
// already included above
// #include "agv_interfaces/srv/detail/battery__functions.h"
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


using _Battery_Response__ros_msg_type = agv_interfaces__srv__Battery_Response;

static bool _Battery_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Battery_Response__ros_msg_type * ros_message = static_cast<const _Battery_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: volt
  {
    cdr << ros_message->volt;
  }

  // Field name: soc
  {
    cdr << ros_message->soc;
  }

  // Field name: current
  {
    cdr << ros_message->current;
  }

  return true;
}

static bool _Battery_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Battery_Response__ros_msg_type * ros_message = static_cast<_Battery_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: volt
  {
    cdr >> ros_message->volt;
  }

  // Field name: soc
  {
    cdr >> ros_message->soc;
  }

  // Field name: current
  {
    cdr >> ros_message->current;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_agv_interfaces
size_t get_serialized_size_agv_interfaces__srv__Battery_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Battery_Response__ros_msg_type * ros_message = static_cast<const _Battery_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name volt
  {
    size_t item_size = sizeof(ros_message->volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name soc
  {
    size_t item_size = sizeof(ros_message->soc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current
  {
    size_t item_size = sizeof(ros_message->current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Battery_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_agv_interfaces__srv__Battery_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_agv_interfaces
size_t max_serialized_size_agv_interfaces__srv__Battery_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: volt
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: soc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: current
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Battery_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_agv_interfaces__srv__Battery_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Battery_Response = {
  "agv_interfaces::srv",
  "Battery_Response",
  _Battery_Response__cdr_serialize,
  _Battery_Response__cdr_deserialize,
  _Battery_Response__get_serialized_size,
  _Battery_Response__max_serialized_size
};

static rosidl_message_type_support_t _Battery_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Battery_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, agv_interfaces, srv, Battery_Response)() {
  return &_Battery_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "agv_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "agv_interfaces/srv/battery.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Battery__callbacks = {
  "agv_interfaces::srv",
  "Battery",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, agv_interfaces, srv, Battery_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, agv_interfaces, srv, Battery_Response)(),
};

static rosidl_service_type_support_t Battery__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Battery__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, agv_interfaces, srv, Battery)() {
  return &Battery__handle;
}

#if defined(__cplusplus)
}
#endif
