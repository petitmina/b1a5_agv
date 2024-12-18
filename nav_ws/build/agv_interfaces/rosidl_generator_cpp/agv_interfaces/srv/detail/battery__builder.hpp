// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from agv_interfaces:srv/Battery.idl
// generated code does not contain a copyright notice

#ifndef AGV_INTERFACES__SRV__DETAIL__BATTERY__BUILDER_HPP_
#define AGV_INTERFACES__SRV__DETAIL__BATTERY__BUILDER_HPP_

#include "agv_interfaces/srv/detail/battery__struct.hpp"
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
auto build<::agv_interfaces::srv::Battery_Request>()
{
  return ::agv_interfaces::srv::Battery_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace agv_interfaces


namespace agv_interfaces
{

namespace srv
{

namespace builder
{

class Init_Battery_Response_current
{
public:
  explicit Init_Battery_Response_current(::agv_interfaces::srv::Battery_Response & msg)
  : msg_(msg)
  {}
  ::agv_interfaces::srv::Battery_Response current(::agv_interfaces::srv::Battery_Response::_current_type arg)
  {
    msg_.current = std::move(arg);
    return std::move(msg_);
  }

private:
  ::agv_interfaces::srv::Battery_Response msg_;
};

class Init_Battery_Response_soc
{
public:
  explicit Init_Battery_Response_soc(::agv_interfaces::srv::Battery_Response & msg)
  : msg_(msg)
  {}
  Init_Battery_Response_current soc(::agv_interfaces::srv::Battery_Response::_soc_type arg)
  {
    msg_.soc = std::move(arg);
    return Init_Battery_Response_current(msg_);
  }

private:
  ::agv_interfaces::srv::Battery_Response msg_;
};

class Init_Battery_Response_volt
{
public:
  Init_Battery_Response_volt()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Battery_Response_soc volt(::agv_interfaces::srv::Battery_Response::_volt_type arg)
  {
    msg_.volt = std::move(arg);
    return Init_Battery_Response_soc(msg_);
  }

private:
  ::agv_interfaces::srv::Battery_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::agv_interfaces::srv::Battery_Response>()
{
  return agv_interfaces::srv::builder::Init_Battery_Response_volt();
}

}  // namespace agv_interfaces

#endif  // AGV_INTERFACES__SRV__DETAIL__BATTERY__BUILDER_HPP_
