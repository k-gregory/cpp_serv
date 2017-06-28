#pragma once

#include <exception_wrap/core.hpp>
#include <sys/epoll.h>

namespace k_gregory{
  namespace os_fail{
    namespace sys{
      using exception_wrap::core::std_except;
      const auto cxx_epoll_create = std_except::wrap(::epoll_create);
      const auto cxx_epoll_create1 = std_except::wrap(::epoll_create1);
      const auto cxx_epoll_ctl = std_except::wrap(::epoll_ctl);
      const auto cxx_epoll_wait = std_except::wrap(::epoll_wait);
    }
  }
}
