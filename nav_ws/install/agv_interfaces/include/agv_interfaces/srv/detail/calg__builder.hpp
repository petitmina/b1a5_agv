// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from agv_interfaces:srv/Calg.idl
// generated code does not contain a copyright notice

#ifndef AGV_INTERFACES__SRV__DETAIL__CALG__BUILDER_HPP_
#define AGV_INTERFACES__SRV__DETAIL__CALG__BUILDER_HPP_

#include "agv_interfaces/srv/detail/calg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace agv_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::agv_interfaces::srv::Calg_Request>()
{
  return ::agv_interfaces::srv::Calg_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace agv_interfaces


namespace agv_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::agv_interfaces::srv::Calg_Response>()
{
  return ::agv_interfaces::srv::Calg_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace agv_interfaces

#endif  // AGV_INTERFACES__SRV__DETAIL__CALG__BUILDER_HPP_
