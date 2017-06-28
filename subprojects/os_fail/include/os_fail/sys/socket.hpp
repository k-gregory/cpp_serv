#pragma once

#include <sys/types.h>
#include <sys/socket.h>

#include <exception_wrap/core.hpp>

namespace k_gregory{
  namespace os_fail{
    namespace sys{
      using exception_wrap::core::std_except;
      const auto cxx_socket = std_except::wrap(::socket);
      const auto cxx_bind = std_except::wrap(::bind);
      const auto cxx_listen = std_except::wrap(::listen);	
    }
  }
}
