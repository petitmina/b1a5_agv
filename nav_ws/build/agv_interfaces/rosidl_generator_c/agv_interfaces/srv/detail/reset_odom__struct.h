// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from agv_interfaces:srv/ResetOdom.idl
// generated code does not contain a copyright notice

#ifndef AGV_INTERFACES__SRV__DETAIL__RESET_ODOM__STRUCT_H_
#define AGV_INTERFACES__SRV__DETAIL__RESET_ODOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ResetOdom in the package agv_interfaces.
typedef struct agv_interfaces__srv__ResetOdom_Request
{
  double x;
  double y;
  double theta;
} agv_interfaces__srv__ResetOdom_Request;

// Struct for a sequence of agv_interfaces__srv__ResetOdom_Request.
typedef struct agv_interfaces__srv__ResetOdom_Request__Sequence
{
  agv_interfaces__srv__ResetOdom_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} agv_interfaces__srv__ResetOdom_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ResetOdom in the package agv_interfaces.
typedef struct agv_interfaces__srv__ResetOdom_Response
{
  uint8_t structure_needs_at_least_one_member;
} agv_interfaces__srv__ResetOdom_Response;

// Struct for a sequence of agv_interfaces__srv__ResetOdom_Response.
typedef struct agv_interfaces__srv__ResetOdom_Response__Sequence
{
  agv_interfaces__srv__ResetOdom_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} agv_interfaces__srv__ResetOdom_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AGV_INTERFACES__SRV__DETAIL__RESET_ODOM__STRUCT_H_
