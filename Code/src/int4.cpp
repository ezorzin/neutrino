#include "int4.hpp"

int4::int4(cl_context thecontext, int num_data)
{
  x = new cl_int[num_data];                                                     // "x" data array.
  y = new cl_int[num_data];                                                     // "y" data array.
  z = new cl_int[num_data];                                                     // "z" data array.
  w = new cl_int[num_data];                                                     // "w" data array.

  size = num_data;                                                              // Array size (the same for all of them).
  vao = 0;                                                                      // OpenGL data VAO.
  vbo = 0;                                                                      // OpenGL data VBO.
  buffer = NULL;                                                                // OpenCL data buffer.
  LAYOUT_0 = 0;                                                                 // Setting layout = 0;
  context = thecontext;                                                         // Getting OpenCL context...

  for (i = 0; i < num_data; i++)                                                // Filling arrays with default data...
  {
    x[i] = 0;                                                                   // Setting "x" data...
    y[i] = 0;                                                                   // Setting "y" data...
    z[i] = 0;                                                                   // Setting "z" data...
    w[i] = 1;                                                                   // Setting "w" data...
  }
}

void int4::init()
{
  data = new GLint[4*size];                                                   // Creating array for unfolded data...

  for (i = 0; i < size; i++)                                                    // Filling unfolded data array...
  {
    data[4*i + 0] = x[i];                                                       // Filling "x"...
    data[4*i + 1] = y[i];                                                       // Filling "y"...
    data[4*i + 2] = z[i];                                                       // Filling "z"...
    data[4*i + 3] = w[i];                                                       // Filling "w"...
  }

  glGenVertexArrays(1, &vao);                                                   // Generating VAO...
  glBindVertexArray(vao);                                                       // Binding VAO...
  glGenBuffers(1, &vbo);                                                        // Generating VBO...
  glBindBuffer(GL_ARRAY_BUFFER, vbo);                                           // Binding VBO...
  glBufferData(GL_ARRAY_BUFFER, 4*sizeof(GLint)*(size), data, GL_DYNAMIC_DRAW); // Creating and initializing a buffer object's data store...
  glEnableVertexAttribArray(LAYOUT_0);                                          // Enabling "layout = 0" attribute in vertex shader...
  glBindBuffer(GL_ARRAY_BUFFER, vbo);                                           // Binding VBO...
  glVertexAttribPointer(LAYOUT_0, 4, GL_INT, GL_FALSE, 0, 0);                   // Specifying the format for "layout = 0" attribute in vertex shader...
  buffer = clCreateFromGLBuffer(context, CL_MEM_READ_WRITE, vbo, &err);         // Creating OpenCL buffer from OpenGL buffer...

  delete[] data;                                                                // Deleting array for unfolded data...

  if(err < 0)
  {
    printf("\nError:  %s\n", get_error(err));
    exit(EXIT_FAILURE);
  }
}

void int4::set(kernel* k, int kernel_arg)
{
  err = clSetKernelArg(k->thekernel, kernel_arg, sizeof(cl_mem), &buffer);      // Setting buffer as OpenCL kernel argument...

  if(err < 0)
  {
    printf("\nError:  %s\n", get_error(err));
    exit(EXIT_FAILURE);
  }
}

void int4::push(queue* q, kernel* k, int kernel_arg)
{
  err = clEnqueueAcquireGLObjects(q->thequeue, 1, &buffer, 0, NULL, NULL);      // Passing "points" to OpenCL kernel...

  if(err != CL_SUCCESS)
  {
    printf("\nError:  %s\n", get_error(err));
    exit(err);
  }
}

void int4::pop(queue* q, kernel* k, int kernel_arg)
{
  err = clEnqueueReleaseGLObjects(q->thequeue, 1, &buffer, 0, NULL, NULL);      // Releasing "points" from OpenCL kernel...

  if(err != CL_SUCCESS)
  {
    printf("\nError:  %s\n", get_error(err));
    exit(err);
  }
}

int4::~int4()
{
  printf("Action: releasing \"float1\" object... ");

  if(buffer != NULL)
  {
    err = clReleaseMemObject(buffer);                                           // Releasing OpenCL buffer object...

    if(err != CL_SUCCESS)
    {
      printf("\nError:  %s\n", get_error(err));
      exit(err);
    }
  }

  glDeleteBuffers(1, &vbo);                                                     // Releasing OpenGL VBO...
  glDeleteBuffers(1, &vao);                                                     // Releasing OpenGL VAO...

  delete[] x;
  delete[] y;
  delete[] z;
  delete[] w;

  printf("DONE!\n");
}