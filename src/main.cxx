#include <os_fail/fcntl.hpp>
#include <os_fail/sys/epoll.hpp>
#include <os_fail/sys/socket.hpp>

#include <cstdlib>
#include <stdexcept>
#include <iostream>

using namespace k_gregory;
using namespace k_gregory::os_fail;

namespace k_gregory{
  namespace cpp_serv{       
    class server{
    public:
      void run(){      
      }
    };
  }
}

int main(){
  cpp_serv::server server; 
  try{
    cxx_fcntl(-1,2,3);
    server.run();
    return EXIT_SUCCESS;
  } catch(std::exception& e){
    std::cout<<"Exception happaned: "<<e.what()<<std::endl;
    return EXIT_FAILURE;
  };
}
