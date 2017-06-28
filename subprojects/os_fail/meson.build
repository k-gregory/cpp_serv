project('os_fail', 'cpp', default_options : ['cpp_std=c++1z'])
exception_wrap_dep = dependency('exception_wrap',
				fallback: ['exception_wrap', 'proj_dep'])

i = include_directories('include')
proj_dep = declare_dependency(include_directories:i,
			      dependencies: exception_wrap_dep)
