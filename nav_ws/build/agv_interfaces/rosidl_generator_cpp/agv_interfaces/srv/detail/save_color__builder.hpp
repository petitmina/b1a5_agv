// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from agv_interfaces:srv/SaveColor.idl
// generated code does not contain a copyright notice

#ifndef AGV_INTERFACES__SRV__DETAIL__SAVE_COLOR__BUILDER_HPP_
#define AGV_INTERFACES__SRV__DETAIL__SAVE_COLOR__BUILDER_HPP_

#include "agv_interfaces/srv/detail/save_color__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace agv_interfaces
{

namespace srv
{

namespace builder
{

class Init_SaveColor_Request_blue
{
public:
  explicit Init_SaveColor_Request_blue(::agv_interfaces::srv::SaveColor_Request & msg)
  : msg_(msg)
  {}
  ::agv_interfaces::srv::SaveColor_Request blue(::agv_interfaces::srv::SaveColor_Request::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::agv_interfaces::srv::SaveColor_Request msg_;
};

class Init_SaveColor_Request_green
{
public:
  explicit Init_SaveColor_Request_green(::agv_interfaces::srv::SaveColor_Request & msg)
  : msg_(msg)
  {}
  Init_SaveColor_Request_blue green(::agv_interfaces::srv::SaveColor_Request::_green_type arg)
  {
    msg_.green = std::move(arg);
    return Init_SaveColor_Request_blue(msg_);
  }

private:
  ::agv_interfaces::srv::SaveColor_Request msg_;
};

class Init_SaveColor_Request_red
{
public:
  Init_SaveColor_Request_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveColor_Request_green red(::agv_interfaces::srv::SaveColor_Request::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_SaveColor_Request_green(msg_);
  }

private:
  ::agv_interfaces::srv::SaveColor_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::agv_interfaces::srv::SaveColor_Request>()
{
  return agv_interfaces::srv::builder::Init_SaveColor_Request_red();
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
auto build<::agv_interfaces::srv::SaveColor_Response>()
{
  return ::agv_interfaces::srv::SaveColor_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace agv_interfaces

#endif  // AGV_INTERFACES__SRV__DETAIL__SAVE_COLOR__BUILDER_HPP_
