#pragma once

#include <cerrno>
#include <system_error>

namespace k_gregory{
  namespace exception_wrap {
    /*
     * \brief Functor which checks that argument of type R is equal to -1
     */
    template<typename R>
    class is_minus_one {
    public:
      bool operator()(const R& x) const {
	return x == -1;
      }
    };

    /*
     * \brief Allows wrapping functions to throw exception on error
     * \param FailFunctor Functor used to detect whether error happened 
     */
    template<template<typename> class FailFunctor>
    class exception_wrapper{
    public:
      template<typename R, typename... ArgsT>
      static auto wrap(R (*func)(ArgsT...)){    
	return [func](ArgsT... args){
	  FailFunctor<R> fail;
	  R res = func(args...);
	  if(!fail(res)){
	    return res;
	  } else{
	    throw std::system_error(errno, std::system_category());	
	  }
	};
      }
    };

    using std_except = exception_wrapper<is_minus_one>;
  }
}
