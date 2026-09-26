project(
  'shaderhelper', 'c',
  version : '0.1.0',
  default_options: ['warning_level=2'],
  license: 'BSD 2-Clause',
)

project_url = 'https://github.com/Numbchenchen/shaderhelper'

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
  description : 'A simple OpenGL shader utility library',
  version : meson.project_version(),
  subdirs : meson.project_name()
)

rpmspec_config = configuration_data(
  {
    'NAME'    : meson.project_name(),
    'VERSION' : meson.project_version(),
    'LICENSE' : meson.project_license()[0],
    'URL'     : project_url
  }
)

spec_cfgfile = configure_file(
  input: 'package.spec.in',
  output: 'package.spec',
  configuration: rpmspec_config
)

install_headers('include/shaderhelper.h')