project('cpp_serv', 'cpp', default_options : ['cpp_std=c++1z'])
exception_wrap_dep = dependency('os_fail', fallback: ['os_fail','proj_dep'])

executable('server',
	   'src/main.cxx',
	   dependencies: [exception_wrap_dep],
	   cpp_pch: 'pch/precompiled.hpp'
	  )
