#pragma once

#include <epoxy/gl.h>

/**
 * compile_shader - 编译OpenGL着色器
 * 
 * @type   : shader 类型, 比如 GL_VERTEX_SHADER
 * @src    : OpenGL Shader Language 源代码字符串
 * @res    : 将写入 glCreateShader() 返回的 id
 * @srclen : 编译器源码的长度, 如果以源码字符串 null 字符结尾则可以填-1
 * 
 * 返回值 : 成功将返回0, 出现错误则返回-1
 *
 * 如果成功, 需要使用 glDeleteShader() 释放资源
 * 错误时可能在 stderr 打印错误信息
 * 
 */
int compile_shader (GLenum type, const char *src, GLuint *res, GLint srclen);