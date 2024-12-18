// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from agv_interfaces:srv/ResetOdom.idl
// generated code does not contain a copyright notice

#ifndef AGV_INTERFACES__SRV__DETAIL__RESET_ODOM__TRAITS_HPP_
#define AGV_INTERFACES__SRV__DETAIL__RESET_ODOM__TRAITS_HPP_

#include "agv_interfaces/srv/detail/reset_odom__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<agv_interfaces::srv::ResetOdom_Request>()
{
  return "agv_interfaces::srv::ResetOdom_Request";
}

template<>
inline const char * name<agv_interfaces::srv::ResetOdom_Request>()
{
  return "agv_interfaces/srv/ResetOdom_Request";
}

template<>
struct has_fixed_size<agv_interfaces::srv::ResetOdom_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<agv_interfaces::srv::ResetOdom_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<agv_interfaces::srv::ResetOdom_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<agv_interfaces::srv::ResetOdom_Response>()
{
  return "agv_interfaces::srv::ResetOdom_Response";
}

template<>
inline const char * name<agv_interfaces::srv::ResetOdom_Response>()
{
  return "agv_interfaces/srv/ResetOdom_Response";
}

template<>
struct has_fixed_size<agv_interfaces::srv::ResetOdom_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<agv_interfaces::srv::ResetOdom_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<agv_interfaces::srv::ResetOdom_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<agv_interfaces::srv::ResetOdom>()
{
  return "agv_interfaces::srv::ResetOdom";
}

template<>
inline const char * name<agv_interfaces::srv::ResetOdom>()
{
  return "agv_interfaces/srv/ResetOdom";
}

template<>
struct has_fixed_size<agv_interfaces::srv::ResetOdom>
  : std::integral_constant<
    bool,
    has_fixed_size<agv_interfaces::srv::ResetOdom_Request>::value &&
    has_fixed_size<agv_interfaces::srv::ResetOdom_Response>::value
  >
{
};

template<>
struct has_bounded_size<agv_interfaces::srv::ResetOdom>
  : std::integral_constant<
    bool,
    has_bounded_size<agv_interfaces::srv::ResetOdom_Request>::value &&
    has_bounded_size<agv_interfaces::srv::ResetOdom_Response>::value
  >
{
};

template<>
struct is_service<agv_interfaces::srv::ResetOdom>
  : std::true_type
{
};

template<>
struct is_service_request<agv_interfaces::srv::ResetOdom_Request>
  : std::true_type
{
};

template<>
struct is_service_response<agv_interfaces::srv::ResetOdom_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AGV_INTERFACES__SRV__DETAIL__RESET_ODOM__TRAITS_HPP_
