#include "link.hpp"

link::link()
{

}

/// # OpenCL error check function
/// ### Description:
/// Checks for an OpenCL error code and print it to stdout.
void link::check_error (
                        cl_int loc_error                                        // Error code.
                       )
{
  if(loc_error != CL_SUCCESS)                                                   // Checking local error code...
  {
    baseline -> error (get_error (loc_error));                                  // Printing error message...
    exit (EXIT_FAILURE);                                                        // Exiting...
  }
}

/// # Link init function
/// ### Description:
/// Initializes link object.
void link::init (
                 neutrino*  loc_baseline,                                       // Neutrino baseline.
                 GLsizeiptr loc_link_size                                       // Data array size.
                )
{
  cl_int       loc_error;                                                       // Error code.

  #ifdef USE_GRAPHICS
    GLsizeiptr i;                                                               // Index.
  #else
    size_t     i;                                                               // Index.
  #endif

  baseline       = loc_baseline;                                                // Getting Neutrino baseline...

  baseline -> action ("initializing \"link\" object...");                       // Printing message...

  link_size      = loc_link_size;                                               // Array size.
  link_buffer    = NULL;                                                        // OpenCL data buffer.
  opencl_context = baseline -> context_id;                                      // Getting OpenCL context...
  link_data      = new link[link_size];                                         // Link data array.

  for(i = 0; i < link_size; i++)                                                // Filling data arrays with default values...
  {
    // Initializing neighbour indexes:
    link_data . up_index    = i;                                                // Initializing "up" neighbour index...
    link_data . down_index  = i;                                                // Initializing "down" neighbour index...
    link_data . left_index  = i;                                                // Initializing "left" neighbour index...
    link_data . right_index = i;                                                // Initializing "right" neighbour index...

    // Initializing neighbour colors:
    init_color4 (link_data . up_color);                                         // Initializing "up" neighbour color...
    init_color4 (link_data . down_color);                                       // Initializing "down" neighbour color...
    init_color4 (link_data . left_color);                                       // Initializing "left" neighbour color...
    init_color4 (link_data . right_color);                                      // Initializing "right" neighbour color...

    // Initializing link properties:
    link_data . stiffness   = 0.0;                                              // Initializing link stiffness...
    link_data . damping     = 0.0;                                              // Initializing link damping...
  }

  #ifdef USE_GRAPHICS
    link_vao = 0;                                                               // Node data VAO.
    link_vbo = 0;                                                               // Node data VBO.

    // Generating VAO...
    glGenVertexArrays (
                       1,                                                       // # of VAOs to generate.
                       &link_vao                                                // VAOs array.
                      );
    glBindVertexArray (link_vao);                                               // Binding node VAO...

    // Generating VBO:
    glGenBuffers (
                  1,                                                            // # of VBOs to generate.
                  &link_vbo                                                     // VBOs array.
                 );

    // Binding VBO:
    glBindBuffer (
                  GL_ARRAY_BUFFER,                                              // VBO target.
                  link_vbo                                                      // VBO to bind.
                 );

    // Creating and initializing a buffer object's data store:
    glBufferData (
                  GL_ARRAY_BUFFER,                                              // VBO target.
                  (GLsizeiptr)(sizeof(link_data)*(link_size)),                  // VBO size.
                  link_data,                                                    // VBO data.
                  GL_DYNAMIC_DRAW                                               // VBO usage.
                 );

    // Enabling attribute in vertex shader:
    glEnableVertexAttribArray (
                               NODE;                                            // VAO index.
                              );

    // Binding VBO:
    glBindBuffer (
                  GL_ARRAY_BUFFER,                                              // VBO target.
                  link_vbo                                                      // VBO to bind.
                 );

    // Specifying the format for attribute in vertex shader:
    glVertexAttribPointer (
                           LINK,                                                // VAO index.
                           sizeof(link_data),                                   // VAO's # of components.
                           GL_FLOAT,                                            // Data type.
                           GL_FALSE,                                            // Not using normalized numbers.
                           0,                                                   // Data stride.
                           0                                                    // Data offset.
                          );

    // Creating OpenCL buffer from OpenGL buffer:
    link_buffer = clCreateFromGLBuffer (
                                        opencl_context,                         // OpenCL context.
                                        CL_MEM_READ_WRITE,                      // Memory flags.
                                        link_vbo,                               // VBO.
                                        &loc_error                              // Returned error.
                                       );
  #else
    // Creating OpenCL memory buffer:
    link_buffer = clCreateBuffer (
                                  opencl_context,                               // OpenCL context.
                                  CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,     // Memory flags.
                                  sizeof(link_data)*link_size,                  // Data buffer size.
                                  link_data,                                    // Data buffer.
                                  &loc_error                                    // Error code.
                                 );
  #endif

  check_error (loc_error);                                                      // Checking returned error code...

  baseline -> done ();                                                          // Printing message...
}

/// # Link neighbour index set function
/// ### Description:
/// Sets the neighbour indexes in link structure.
void link::set_neighbour_index (
                                GLsizeiptr loc_index,                           // Data index.
                                GLsizeiptr loc_value[4]                         // Data value.
                               )
{
  link_data . up_index[loc_index]    = loc_value[0];                            // Setting "up" neighbour index...
  link_data . down_index[loc_index]  = loc_value[1];                            // Setting "down" neighbour index...
  link_data . left_index[loc_index]  = loc_value[2];                            // Setting "left" neighbour index...
  link_data . right_index[loc_index] = loc_value[3];                            // Setting "right" neighbour index...
};

/// # Link neighbour color set function
/// ### Description:
/// Sets the neighbour color in link structure.
void link::set_neighbour_color (
                                GLsizeiptr loc_index,                           // Data index.
                                GLfloat    loc_value[4]                         // Data value.
                               )
{
  link_data . up_color[loc_index]    = loc_value[0];                            // Setting "up" neighbour color...
  link_data . down_color[loc_index]  = loc_value[1];                            // Setting "down" neighbour color...
  link_data . left_color[loc_index]  = loc_value[2];                            // Setting "left" neighbour color...
  link_data . right_color[loc_index] = loc_value[3];                            // Setting "right" neighbour color...
};

/// # Link stiffness set function
/// ### Description:
/// Sets the stiffness in link structure.
void node::set_stiffness (
                          GLsizeiptr loc_index,                                 // Data index.
                          GLfloat    loc_value                                  // Data value.
                         )
{
  link_data . stiffness[loc_index] = loc_value;                                 // Setting link stiffness...
};

/// # Link damping set function
/// ### Description:
/// Sets the damping in link structure.
void node::set_damping (
                        GLsizeiptr loc_index,                                   // Data index.
                        GLfloat    loc_value                                    // Data value.
                       )
{
  link_data . damping[loc_index] = loc_value;                                   // Setting link internal damping...
};
