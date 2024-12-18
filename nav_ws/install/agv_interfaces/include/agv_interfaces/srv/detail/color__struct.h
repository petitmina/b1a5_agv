// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from agv_interfaces:srv/Color.idl
// generated code does not contain a copyright notice

#ifndef AGV_INTERFACES__SRV__DETAIL__COLOR__STRUCT_H_
#define AGV_INTERFACES__SRV__DETAIL__COLOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/Color in the package agv_interfaces.
typedef struct agv_interfaces__srv__Color_Request
{
  int64_t red;
  int64_t green;
  int64_t blue;
} agv_interfaces__srv__Color_Request;

// Struct for a sequence of agv_interfaces__srv__Color_Request.
typedef struct agv_interfaces__srv__Color_Request__Sequence
{
  agv_interfaces__srv__Color_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} agv_interfaces__srv__Color_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/Color in the package agv_interfaces.
typedef struct agv_interfaces__srv__Color_Response
{
  uint8_t structure_needs_at_least_one_member;
} agv_interfaces__srv__Color_Response;

// Struct for a sequence of agv_interfaces__srv__Color_Response.
typedef struct agv_interfaces__srv__Color_Response__Sequence
{
  agv_interfaces__srv__Color_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} agv_interfaces__srv__Color_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AGV_INTERFACES__SRV__DETAIL__COLOR__STRUCT_H_
