#pragma once

#include <exception_wrap/core.hpp>

#include <unistd.h>
#include <fcntl.h>

namespace k_gregory{
  namespace os_fail{
    using exception_wrap::core::std_except;
    const std_except::vararg_wrapper<int (*)(int, int,...), fcntl> cxx_fcntl;
  }
}
