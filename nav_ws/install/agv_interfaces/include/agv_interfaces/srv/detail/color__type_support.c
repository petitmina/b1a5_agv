// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from agv_interfaces:srv/Color.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "agv_interfaces/srv/detail/color__rosidl_typesupport_introspection_c.h"
#include "agv_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "agv_interfaces/srv/detail/color__functions.h"
#include "agv_interfaces/srv/detail/color__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Color_Request__rosidl_typesupport_introspection_c__Color_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  agv_interfaces__srv__Color_Request__init(message_memory);
}

void Color_Request__rosidl_typesupport_introspection_c__Color_Request_fini_function(void * message_memory)
{
  agv_interfaces__srv__Color_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Color_Request__rosidl_typesupport_introspection_c__Color_Request_message_member_array[3] = {
  {
    "red",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(agv_interfaces__srv__Color_Request, red),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "green",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(agv_interfaces__srv__Color_Request, green),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "blue",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(agv_interfaces__srv__Color_Request, blue),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Color_Request__rosidl_typesupport_introspection_c__Color_Request_message_members = {
  "agv_interfaces__srv",  // message namespace
  "Color_Request",  // message name
  3,  // number of fields
  sizeof(agv_interfaces__srv__Color_Request),
  Color_Request__rosidl_typesupport_introspection_c__Color_Request_message_member_array,  // message members
  Color_Request__rosidl_typesupport_introspection_c__Color_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Color_Request__rosidl_typesupport_introspection_c__Color_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Color_Request__rosidl_typesupport_introspection_c__Color_Request_message_type_support_handle = {
  0,
  &Color_Request__rosidl_typesupport_introspection_c__Color_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_agv_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, agv_interfaces, srv, Color_Request)() {
  if (!Color_Request__rosidl_typesupport_introspection_c__Color_Request_message_type_support_handle.typesupport_identifier) {
    Color_Request__rosidl_typesupport_introspection_c__Color_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Color_Request__rosidl_typesupport_introspection_c__Color_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "agv_interfaces/srv/detail/color__rosidl_typesupport_introspection_c.h"
// already included above
// #include "agv_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "agv_interfaces/srv/detail/color__functions.h"
// already included above
// #include "agv_interfaces/srv/detail/color__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Color_Response__rosidl_typesupport_introspection_c__Color_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  agv_interfaces__srv__Color_Response__init(message_memory);
}

void Color_Response__rosidl_typesupport_introspection_c__Color_Response_fini_function(void * message_memory)
{
  agv_interfaces__srv__Color_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Color_Response__rosidl_typesupport_introspection_c__Color_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(agv_interfaces__srv__Color_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Color_Response__rosidl_typesupport_introspection_c__Color_Response_message_members = {
  "agv_interfaces__srv",  // message namespace
  "Color_Response",  // message name
  1,  // number of fields
  sizeof(agv_interfaces__srv__Color_Response),
  Color_Response__rosidl_typesupport_introspection_c__Color_Response_message_member_array,  // message members
  Color_Response__rosidl_typesupport_introspection_c__Color_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Color_Response__rosidl_typesupport_introspection_c__Color_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Color_Response__rosidl_typesupport_introspection_c__Color_Response_message_type_support_handle = {
  0,
  &Color_Response__rosidl_typesupport_introspection_c__Color_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_agv_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, agv_interfaces, srv, Color_Response)() {
  if (!Color_Response__rosidl_typesupport_introspection_c__Color_Response_message_type_support_handle.typesupport_identifier) {
    Color_Response__rosidl_typesupport_introspection_c__Color_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Color_Response__rosidl_typesupport_introspection_c__Color_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "agv_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "agv_interfaces/srv/detail/color__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers agv_interfaces__srv__detail__color__rosidl_typesupport_introspection_c__Color_service_members = {
  "agv_interfaces__srv",  // service namespace
  "Color",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // agv_interfaces__srv__detail__color__rosidl_typesupport_introspection_c__Color_Request_message_type_support_handle,
  NULL  // response message
  // agv_interfaces__srv__detail__color__rosidl_typesupport_introspection_c__Color_Response_message_type_support_handle
};

static rosidl_service_type_support_t agv_interfaces__srv__detail__color__rosidl_typesupport_introspection_c__Color_service_type_support_handle = {
  0,
  &agv_interfaces__srv__detail__color__rosidl_typesupport_introspection_c__Color_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, agv_interfaces, srv, Color_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, agv_interfaces, srv, Color_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_agv_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, agv_interfaces, srv, Color)() {
  if (!agv_interfaces__srv__detail__color__rosidl_typesupport_introspection_c__Color_service_type_support_handle.typesupport_identifier) {
    agv_interfaces__srv__detail__color__rosidl_typesupport_introspection_c__Color_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)agv_interfaces__srv__detail__color__rosidl_typesupport_introspection_c__Color_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, agv_interfaces, srv, Color_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, agv_interfaces, srv, Color_Response)()->data;
  }

  return &agv_interfaces__srv__detail__color__rosidl_typesupport_introspection_c__Color_service_type_support_handle;
}
