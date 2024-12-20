// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from agv_interfaces:srv/Color.idl
// generated code does not contain a copyright notice
#include "agv_interfaces/srv/detail/color__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
agv_interfaces__srv__Color_Request__init(agv_interfaces__srv__Color_Request * msg)
{
  if (!msg) {
    return false;
  }
  // red
  // green
  // blue
  return true;
}

void
agv_interfaces__srv__Color_Request__fini(agv_interfaces__srv__Color_Request * msg)
{
  if (!msg) {
    return;
  }
  // red
  // green
  // blue
}

bool
agv_interfaces__srv__Color_Request__are_equal(const agv_interfaces__srv__Color_Request * lhs, const agv_interfaces__srv__Color_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // red
  if (lhs->red != rhs->red) {
    return false;
  }
  // green
  if (lhs->green != rhs->green) {
    return false;
  }
  // blue
  if (lhs->blue != rhs->blue) {
    return false;
  }
  return true;
}

bool
agv_interfaces__srv__Color_Request__copy(
  const agv_interfaces__srv__Color_Request * input,
  agv_interfaces__srv__Color_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // red
  output->red = input->red;
  // green
  output->green = input->green;
  // blue
  output->blue = input->blue;
  return true;
}

agv_interfaces__srv__Color_Request *
agv_interfaces__srv__Color_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  agv_interfaces__srv__Color_Request * msg = (agv_interfaces__srv__Color_Request *)allocator.allocate(sizeof(agv_interfaces__srv__Color_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(agv_interfaces__srv__Color_Request));
  bool success = agv_interfaces__srv__Color_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
agv_interfaces__srv__Color_Request__destroy(agv_interfaces__srv__Color_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    agv_interfaces__srv__Color_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
agv_interfaces__srv__Color_Request__Sequence__init(agv_interfaces__srv__Color_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  agv_interfaces__srv__Color_Request * data = NULL;

  if (size) {
    data = (agv_interfaces__srv__Color_Request *)allocator.zero_allocate(size, sizeof(agv_interfaces__srv__Color_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = agv_interfaces__srv__Color_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        agv_interfaces__srv__Color_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
agv_interfaces__srv__Color_Request__Sequence__fini(agv_interfaces__srv__Color_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      agv_interfaces__srv__Color_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

agv_interfaces__srv__Color_Request__Sequence *
agv_interfaces__srv__Color_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  agv_interfaces__srv__Color_Request__Sequence * array = (agv_interfaces__srv__Color_Request__Sequence *)allocator.allocate(sizeof(agv_interfaces__srv__Color_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = agv_interfaces__srv__Color_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
agv_interfaces__srv__Color_Request__Sequence__destroy(agv_interfaces__srv__Color_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    agv_interfaces__srv__Color_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
agv_interfaces__srv__Color_Request__Sequence__are_equal(const agv_interfaces__srv__Color_Request__Sequence * lhs, const agv_interfaces__srv__Color_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!agv_interfaces__srv__Color_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
agv_interfaces__srv__Color_Request__Sequence__copy(
  const agv_interfaces__srv__Color_Request__Sequence * input,
  agv_interfaces__srv__Color_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(agv_interfaces__srv__Color_Request);
    agv_interfaces__srv__Color_Request * data =
      (agv_interfaces__srv__Color_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!agv_interfaces__srv__Color_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          agv_interfaces__srv__Color_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!agv_interfaces__srv__Color_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
agv_interfaces__srv__Color_Response__init(agv_interfaces__srv__Color_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
agv_interfaces__srv__Color_Response__fini(agv_interfaces__srv__Color_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
agv_interfaces__srv__Color_Response__are_equal(const agv_interfaces__srv__Color_Response * lhs, const agv_interfaces__srv__Color_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
agv_interfaces__srv__Color_Response__copy(
  const agv_interfaces__srv__Color_Response * input,
  agv_interfaces__srv__Color_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

agv_interfaces__srv__Color_Response *
agv_interfaces__srv__Color_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  agv_interfaces__srv__Color_Response * msg = (agv_interfaces__srv__Color_Response *)allocator.allocate(sizeof(agv_interfaces__srv__Color_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(agv_interfaces__srv__Color_Response));
  bool success = agv_interfaces__srv__Color_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
agv_interfaces__srv__Color_Response__destroy(agv_interfaces__srv__Color_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    agv_interfaces__srv__Color_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
agv_interfaces__srv__Color_Response__Sequence__init(agv_interfaces__srv__Color_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  agv_interfaces__srv__Color_Response * data = NULL;

  if (size) {
    data = (agv_interfaces__srv__Color_Response *)allocator.zero_allocate(size, sizeof(agv_interfaces__srv__Color_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = agv_interfaces__srv__Color_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        agv_interfaces__srv__Color_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
agv_interfaces__srv__Color_Response__Sequence__fini(agv_interfaces__srv__Color_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      agv_interfaces__srv__Color_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

agv_interfaces__srv__Color_Response__Sequence *
agv_interfaces__srv__Color_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  agv_interfaces__srv__Color_Response__Sequence * array = (agv_interfaces__srv__Color_Response__Sequence *)allocator.allocate(sizeof(agv_interfaces__srv__Color_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = agv_interfaces__srv__Color_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
agv_interfaces__srv__Color_Response__Sequence__destroy(agv_interfaces__srv__Color_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    agv_interfaces__srv__Color_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
agv_interfaces__srv__Color_Response__Sequence__are_equal(const agv_interfaces__srv__Color_Response__Sequence * lhs, const agv_interfaces__srv__Color_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!agv_interfaces__srv__Color_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
agv_interfaces__srv__Color_Response__Sequence__copy(
  const agv_interfaces__srv__Color_Response__Sequence * input,
  agv_interfaces__srv__Color_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(agv_interfaces__srv__Color_Response);
    agv_interfaces__srv__Color_Response * data =
      (agv_interfaces__srv__Color_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!agv_interfaces__srv__Color_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          agv_interfaces__srv__Color_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!agv_interfaces__srv__Color_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
