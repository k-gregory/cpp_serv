#pragma once

#include <cerrno>
#include <system_error>

namespace k_gregory{
  namespace exception_wrap {
    namespace core{
      namespace fail_policy{
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
      }

      /*
       * \brief Allows wrapping functions to throw exception on error
       * \param FailFunctor Functor used to detect whether error happened 
       */
      template<template<typename> class FailFunctor>
      class exception_wrapper{
      public:
	/*
	 *\brief Wraps func to throw exception on error
	 */
	template<typename R, typename... ArgsT>
	static auto wrap(R (*func)(ArgsT...)) {    
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

	
	/*
	 *\brief Used for c-style vararg functions
	 *\param F function signature
	 *\param x function name
	 */
	template<typename F, F x>
	class vararg_wrapper{
	  //TODO: Get rid of this class
	public:
	  template<typename... ArgsT>
	  auto operator()(ArgsT... args) const {
	    auto res = x(args...);
	    FailFunctor<decltype(res)> fail;
	    if(!fail(res)){
	      return res;
	    } else {
	      throw std::system_error(errno, std::system_category());
	    }
	  }
	};	
      };

      using std_except = exception_wrapper<fail_policy::is_minus_one>;
    }
  }
}
