project(
  'shaderhelper', 'c',
  version : '0.1.0',
  default_options: ['warning_level=2'],
)

srcs = [
  'main.c'
]

header_dir = include_directories('include')

self_lib = library('shaderhelper', srcs, 
  include_directories : header_dir,
  dependencies : [dependency('epoxy')],
  install : true,
)

pkg = import('pkgconfig')

pkg.generate(
  self_lib,
  name : meson.project_name(),
  filebase : meson.project_name(),
  description : 'A simple OpenGL shader utils',
  version : meson.project_version(),
  subdirs : meson.project_name()
)

