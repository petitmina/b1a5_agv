// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from agv_interfaces:srv/Onoff.idl
// generated code does not contain a copyright notice

#ifndef AGV_INTERFACES__SRV__DETAIL__ONOFF__BUILDER_HPP_
#define AGV_INTERFACES__SRV__DETAIL__ONOFF__BUILDER_HPP_

#include "agv_interfaces/srv/detail/onoff__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace agv_interfaces
{

namespace srv
{

namespace builder
{

class Init_Onoff_Request_set
{
public:
  Init_Onoff_Request_set()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::agv_interfaces::srv::Onoff_Request set(::agv_interfaces::srv::Onoff_Request::_set_type arg)
  {
    msg_.set = std::move(arg);
    return std::move(msg_);
  }

private:
  ::agv_interfaces::srv::Onoff_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::agv_interfaces::srv::Onoff_Request>()
{
  return agv_interfaces::srv::builder::Init_Onoff_Request_set();
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
auto build<::agv_interfaces::srv::Onoff_Response>()
{
  return ::agv_interfaces::srv::Onoff_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace agv_interfaces

#endif  // AGV_INTERFACES__SRV__DETAIL__ONOFF__BUILDER_HPP_
