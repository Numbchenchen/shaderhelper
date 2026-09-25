# ShaderHelper

> 简单的库, 用与编译OpenGL Shader

## 可用函数

```c
#include "shaderhelper.h"


/* 编译着色器, 出现错误返回-1, 成功则返回0 */
int compile_shader (GLenum type, const char *src, GLuint *res, GLint srclen);
```

## 构建

```bash
meson setup builddir -Dbuildtype=release
meson compile -C builddir
```

## 示例

```c
#include "shaderhelper.h"

int main(void)
{
  const char src[] = 
"\
#version 330 core\n\
\n\
out vec4 color;\n\
\n\
void main()\n\
{\n\
	color = vec4(1.0, 1.0, 1.0, 1.0);\n\
}\n\
"

  GLuint shader;
  int res;

  res = compile_shader (
    GL_FRAGMENT_SHADER,
    src,
    &shader,
    -1 /* 因为src以'\0'结尾 */
  );

  if (res < 0)
    {
  	  return 1;
    }

  /* ... */

  glDeleteShader (shader);
}
```