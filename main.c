#include "shaderhelper.h"

#include <stdlib.h>
#include <stdio.h>

int
compile_shader (GLenum type, const char *src, GLuint *res, GLint srclen)
{
  GLint success;
  GLint errlen;
  char *errmsg;
  GLuint shader = glCreateShader (type);

  glShaderSource (shader, 1, &src, srclen < 0 ? NULL : &srclen);
  glCompileShader (shader);
  glGetShaderiv (shader, GL_COMPILE_STATUS, &success);
  if (!success)
    {
      glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &errlen);
      errmsg = malloc (errlen);
      if (!errmsg)
        {
          glDeleteShader (shader);
          return -1;
        }
      glGetShaderInfoLog (shader, errlen, NULL, errmsg);
      fprintf (stderr, "Failed to Compile shader(type %x): %s", type, errmsg);

      glDeleteShader (shader);
      free (errmsg);
      return -1;
    }

  *res = shader;
  return 0;
}
