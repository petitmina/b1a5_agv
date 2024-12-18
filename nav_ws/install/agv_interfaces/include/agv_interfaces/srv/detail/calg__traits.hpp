// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from agv_interfaces:srv/Calg.idl
// generated code does not contain a copyright notice

#ifndef AGV_INTERFACES__SRV__DETAIL__CALG__TRAITS_HPP_
#define AGV_INTERFACES__SRV__DETAIL__CALG__TRAITS_HPP_

#include "agv_interfaces/srv/detail/calg__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<agv_interfaces::srv::Calg_Request>()
{
  return "agv_interfaces::srv::Calg_Request";
}

template<>
inline const char * name<agv_interfaces::srv::Calg_Request>()
{
  return "agv_interfaces/srv/Calg_Request";
}

template<>
struct has_fixed_size<agv_interfaces::srv::Calg_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<agv_interfaces::srv::Calg_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<agv_interfaces::srv::Calg_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<agv_interfaces::srv::Calg_Response>()
{
  return "agv_interfaces::srv::Calg_Response";
}

template<>
inline const char * name<agv_interfaces::srv::Calg_Response>()
{
  return "agv_interfaces/srv/Calg_Response";
}

template<>
struct has_fixed_size<agv_interfaces::srv::Calg_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<agv_interfaces::srv::Calg_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<agv_interfaces::srv::Calg_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<agv_interfaces::srv::Calg>()
{
  return "agv_interfaces::srv::Calg";
}

template<>
inline const char * name<agv_interfaces::srv::Calg>()
{
  return "agv_interfaces/srv/Calg";
}

template<>
struct has_fixed_size<agv_interfaces::srv::Calg>
  : std::integral_constant<
    bool,
    has_fixed_size<agv_interfaces::srv::Calg_Request>::value &&
    has_fixed_size<agv_interfaces::srv::Calg_Response>::value
  >
{
};

template<>
struct has_bounded_size<agv_interfaces::srv::Calg>
  : std::integral_constant<
    bool,
    has_bounded_size<agv_interfaces::srv::Calg_Request>::value &&
    has_bounded_size<agv_interfaces::srv::Calg_Response>::value
  >
{
};

template<>
struct is_service<agv_interfaces::srv::Calg>
  : std::true_type
{
};

template<>
struct is_service_request<agv_interfaces::srv::Calg_Request>
  : std::true_type
{
};

template<>
struct is_service_response<agv_interfaces::srv::Calg_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AGV_INTERFACES__SRV__DETAIL__CALG__TRAITS_HPP_
