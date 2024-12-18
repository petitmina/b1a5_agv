// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from agv_interfaces:srv/Calg.idl
// generated code does not contain a copyright notice

#ifndef AGV_INTERFACES__SRV__DETAIL__CALG__STRUCT_HPP_
#define AGV_INTERFACES__SRV__DETAIL__CALG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__agv_interfaces__srv__Calg_Request __attribute__((deprecated))
#else
# define DEPRECATED__agv_interfaces__srv__Calg_Request __declspec(deprecated)
#endif

namespace agv_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Calg_Request_
{
  using Type = Calg_Request_<ContainerAllocator>;

  explicit Calg_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Calg_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    agv_interfaces::srv::Calg_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const agv_interfaces::srv::Calg_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<agv_interfaces::srv::Calg_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<agv_interfaces::srv::Calg_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      agv_interfaces::srv::Calg_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<agv_interfaces::srv::Calg_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      agv_interfaces::srv::Calg_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<agv_interfaces::srv::Calg_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<agv_interfaces::srv::Calg_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<agv_interfaces::srv::Calg_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__agv_interfaces__srv__Calg_Request
    std::shared_ptr<agv_interfaces::srv::Calg_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__agv_interfaces__srv__Calg_Request
    std::shared_ptr<agv_interfaces::srv::Calg_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Calg_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Calg_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Calg_Request_

// alias to use template instance with default allocator
using Calg_Request =
  agv_interfaces::srv::Calg_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace agv_interfaces


#ifndef _WIN32
# define DEPRECATED__agv_interfaces__srv__Calg_Response __attribute__((deprecated))
#else
# define DEPRECATED__agv_interfaces__srv__Calg_Response __declspec(deprecated)
#endif

namespace agv_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Calg_Response_
{
  using Type = Calg_Response_<ContainerAllocator>;

  explicit Calg_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Calg_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    agv_interfaces::srv::Calg_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const agv_interfaces::srv::Calg_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<agv_interfaces::srv::Calg_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<agv_interfaces::srv::Calg_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      agv_interfaces::srv::Calg_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<agv_interfaces::srv::Calg_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      agv_interfaces::srv::Calg_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<agv_interfaces::srv::Calg_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<agv_interfaces::srv::Calg_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<agv_interfaces::srv::Calg_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__agv_interfaces__srv__Calg_Response
    std::shared_ptr<agv_interfaces::srv::Calg_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__agv_interfaces__srv__Calg_Response
    std::shared_ptr<agv_interfaces::srv::Calg_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Calg_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Calg_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Calg_Response_

// alias to use template instance with default allocator
using Calg_Response =
  agv_interfaces::srv::Calg_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace agv_interfaces

namespace agv_interfaces
{

namespace srv
{

struct Calg
{
  using Request = agv_interfaces::srv::Calg_Request;
  using Response = agv_interfaces::srv::Calg_Response;
};

}  // namespace srv

}  // namespace agv_interfaces

#endif  // AGV_INTERFACES__SRV__DETAIL__CALG__STRUCT_HPP_
