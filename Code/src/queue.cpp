/// @file     queue.cpp
/// @author   Erik ZORZIN
/// @date     24OCT2019
/// @brief    Definition of an OpenCL "queue" class.

#include "queue.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// "queue" class //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
queue::queue()
{
  queue_id   = NULL;                                                                                // Initializing queue id...
  context_id = NULL;                                                                                // Initializing context id...
  device_id  = NULL;                                                                                // Initializing device id...
}

void queue::init
(
 neutrino* loc_baseline
)
{
  cl_int loc_error;                                                                                 // Local error code.

  baseline   = loc_baseline;                                                                        // Getting Neutrino baseline...
  baseline->action ("creating OpenCL command queue...");                                            // Printing message...

  glFinish ();                                                                                      // Waiting for OpenGL to finish...

  context_id = baseline->context_id;                                                                // Initializing context id...
  device_id  = baseline->device_id;                                                                 // Initializing device id...

  // Creating OpenCL queue:
  queue_id   = clCreateCommandQueue
               (
                context_id,                                                                         // OpenCL context ID.
                device_id,                                                                          // Device ID.
                0,                                                                                  // Queue properties (con be used for enabling profiling).
                &loc_error
               );                                                                                   // Error code.

  baseline->check_error (loc_error);                                                                // Checking error...

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  baseline->done ();                                                                                // Printing message...
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////// "read" functions ///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
void queue::read
(
 int1*   loc_data,                                                                                  // int1 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Reading OpenCL buffer:
  loc_error = clEnqueueReadBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(cl_long)*loc_data->size,                                                      // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::read
(
 int2*   loc_data,                                                                                  // int2 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Reading OpenCL buffer:
  loc_error = clEnqueueReadBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(int2_structure)*loc_data->size,                                               // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::read
(
 int3*   loc_data,                                                                                  // int3 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Reading OpenCL buffer:
  loc_error = clEnqueueReadBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(int3_structure)*loc_data->size,                                               // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::read
(
 int4*   loc_data,                                                                                  // int4 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Reading OpenCL buffer:
  loc_error = clEnqueueReadBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(int4_structure)*loc_data->size,                                               // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::read
(
 float1* loc_data,                                                                                  // float1 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Reading OpenCL buffer:
  loc_error = clEnqueueReadBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(cl_float)*loc_data->size,                                                     // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::read
(
 float1G* loc_data,                                                                                 // Data object.
 cl_uint  loc_layout_index                                                                          // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Acquiring OpenGL buffer:
    acquire (
             loc_data,                                                                              // Data object.
             loc_layout_index                                                                       // OpenGL shader layout index.
            );
  }

  // Reading OpenCL buffer:
  loc_error = clEnqueueReadBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(GLfloat)*loc_data->size,                                                      // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);                                                                // Checking error...

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Releasing OpenGL buffer:
    release
    (
     loc_data,                                                                                      // Data object.
     loc_layout_index                                                                               // OpenGL shader layout index.
    );
  }

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::read
(
 float2* loc_data,                                                                                  // float2 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Reading OpenCL buffer:
  loc_error = clEnqueueReadBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(float2_structure)*loc_data->size,                                             // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::read
(
 float3* loc_data,                                                                                  // float3 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Reading OpenCL buffer:
  loc_error = clEnqueueReadBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(float3_structure)*loc_data->size,                                             // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::read
(
 float4* loc_data,                                                                                  // Data object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Reading OpenCL buffer:
  loc_error = clEnqueueReadBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(float4_structure)*loc_data->size,                                             // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::read
(
 float4G* loc_data,                                                                                 // Data object.
 cl_uint  loc_layout_index                                                                          // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Acquiring OpenGL buffer:
    acquire (
             loc_data,                                                                              // Data object.
             loc_layout_index                                                                       // OpenGL shader layout index.
            );
  }

  // Reading OpenCL buffer:
  loc_error = clEnqueueReadBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(float4G_structure)*loc_data->size,                                            // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);                                                                // Checking error...

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Releasing OpenGL buffer:
    release
    (
     loc_data,                                                                                      // Data object.
     loc_layout_index                                                                               // OpenGL shader layout index.
    );
  }

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// write "functions" ////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
void queue::write
(
 int1*   loc_data,                                                                                  // int1 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Writing OpenCL buffer:
  loc_error = clEnqueueWriteBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(cl_long)*loc_data->size,                                                      // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::write
(
 int2*   loc_data,                                                                                  // int2 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Writing OpenCL buffer:
  loc_error = clEnqueueWriteBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(int2_structure)*loc_data->size,                                               // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::write
(
 int3*   loc_data,                                                                                  // int3 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Writing OpenCL buffer:
  loc_error = clEnqueueWriteBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(int3_structure)*loc_data->size,                                               // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::write
(
 int4*   loc_data,                                                                                  // Data object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Writing OpenCL buffer:
  loc_error = clEnqueueWriteBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(int4_structure)*loc_data->size,                                               // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::write
(
 float1* loc_data,                                                                                  // float1 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Writing OpenCL buffer:
  loc_error = clEnqueueWriteBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(cl_float)*loc_data->size,                                                     // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::write
(
 float1G* loc_data,                                                                                 // Data object.
 cl_uint  loc_layout_index                                                                          // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Acquiring OpenGL buffer:
    acquire (
             loc_data,                                                                              // Data object.
             loc_layout_index                                                                       // OpenGL shader layout index.
            );
  }

  // Writing OpenCL buffer:
  loc_error = clEnqueueWriteBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(GLfloat)*loc_data->size,                                                      // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);                                                                // Checking error...

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Releasing OpenGL buffer:
    release
    (
     loc_data,                                                                                      // Data object.
     loc_layout_index                                                                               // OpenGL shader layout index.
    );
  }

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::write
(
 float2* loc_data,                                                                                  // float2 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Writing OpenCL buffer:
  loc_error = clEnqueueWriteBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(float2_structure)*loc_data->size,                                             // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::write
(
 float3* loc_data,                                                                                  // float3 object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Writing OpenCL buffer:
  loc_error = clEnqueueWriteBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(float3_structure)*loc_data->size,                                             // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::write
(
 float4* loc_data,                                                                                  // Data object.
 cl_uint loc_layout_index                                                                           // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Writing OpenCL buffer:
  loc_error = clEnqueueWriteBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(float4_structure)*loc_data->size,                                             // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::write
(
 float4G* loc_data,                                                                                 // Data object.
 cl_uint  loc_layout_index                                                                          // Layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Acquiring OpenGL buffer:
    acquire (
             loc_data,                                                                              // Data object.
             loc_layout_index                                                                       // OpenGL shader layout index.
            );
  }

  // Writing OpenCL buffer:
  loc_error = clEnqueueWriteBuffer
              (
               queue_id,                                                                            // OpenCL queue ID.
               loc_data->buffer,                                                                    // Data buffer.
               CL_TRUE,                                                                             // Blocking write flag.
               0,                                                                                   // Data buffer offset.
               sizeof(float4G_structure)*loc_data->size,                                            // Data buffer size.
               loc_data->data,                                                                      // Data buffer.
               0,                                                                                   // Number of events in the list.
               NULL,                                                                                // Event list.
               NULL                                                                                 // Event.
              );

  baseline->check_error (loc_error);                                                                // Checking error...

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Releasing OpenGL buffer:
    release
    (
     loc_data,                                                                                      // Data object.
     loc_layout_index                                                                               // OpenGL shader layout index.
    );
  }

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::acquire
(
 float1G* loc_data,                                                                                 // Data object.
 GLuint   loc_layout_index                                                                          // OpenGL shader layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Setting layout index in vertex shader...
  glDisableVertexAttribArray (loc_layout_index);                                                    // Unbinding data array...

  glFinish ();                                                                                      // Waiting for OpenGL to finish...

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Acquiring OpenCL buffer:
    loc_error = clEnqueueAcquireGLObjects
                (
                 queue_id,                                                                          // Queue.
                 1,                                                                                 // Number of memory objects.
                 &loc_data->buffer,                                                                 // Memory object array.
                 0,                                                                                 // Number of events in event list.
                 NULL,                                                                              // Event list.
                 NULL                                                                               // Event.
                );

    baseline->check_error (loc_error);                                                              // Checking returned error code...

    clFinish (queue_id);                                                                            // Waiting for OpenCL to finish...
  }
  else
  {
    // Binding node VAO...
    glBindVertexArray
    (
     loc_data->vao                                                                                  // VAOs array.
    );

    // Binding VBO:
    glBindBuffer
    (
     GL_ARRAY_BUFFER,                                                                               // VBO target.
     loc_data->vbo                                                                                  // VBO to bind.
    );

    // Creating and initializing a buffer object's data store:
    glBufferSubData
    (
     GL_ARRAY_BUFFER,                                                                               // VBO target.
     0,                                                                                             // VBO Offset.
     sizeof(GLfloat)*loc_data->size,                                                                // VBO size.
     loc_data->data                                                                                 // VBO data.
    );

    // Specifying the format for attribute in vertex shader:
    glVertexAttribPointer
    (
     loc_layout_index,                                                                              // VAO index.
     1,                                                                                             // VAO's number of components.
     GL_FLOAT,                                                                                      // Data type.
     GL_FALSE,                                                                                      // Not using normalized numbers.
     0,                                                                                             // Data stride.
     0                                                                                              // Data offset.
    );

    // Enabling attribute in vertex shader:
    glEnableVertexAttribArray
    (
     loc_layout_index                                                                               // VAO index.
    );

    // Binding VBO:
    glBindBuffer
    (
     GL_ARRAY_BUFFER,                                                                               // VBO target.
     loc_data->vbo                                                                                  // VBO to bind.
    );

    // Setting layout index in vertex shader...
    glDisableVertexAttribArray (loc_layout_index);                                                  // Unbinding data array...

    glFinish ();                                                                                    // Waiting for OpenGL to finish...

    // Writing OpenCL buffer:
    loc_error = clEnqueueWriteBuffer
                (
                 queue_id,                                                                          // OpenCL queue ID.
                 loc_data->buffer,                                                                  // Data buffer.
                 CL_TRUE,                                                                           // Blocking write flag.
                 0,                                                                                 // Data buffer offset.
                 sizeof(GLfloat)*loc_data->size,                                                    // Data buffer size.
                 loc_data->data,                                                                    // Data buffer.
                 0,                                                                                 // Number of events in the list.
                 NULL,                                                                              // Event list.
                 NULL                                                                               // Event.
                );
    baseline->check_error (loc_error);

    clFinish (queue_id);                                                                            // Waiting for OpenCL to finish...
  }
};

void queue::acquire
(
 float4G* loc_data,                                                                                 // Data object.
 GLuint   loc_layout_index                                                                          // OpenGL shader layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  // Setting layout index in vertex shader...
  glDisableVertexAttribArray (loc_layout_index);                                                    // Unbinding data array...

  glFinish ();                                                                                      // Waiting for OpenGL to finish...

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Acquiring OpenCL buffer:
    loc_error = clEnqueueAcquireGLObjects
                (
                 queue_id,                                                                          // Queue.
                 1,                                                                                 // Number of memory objects.
                 &loc_data->buffer,                                                                 // Memory object array.
                 0,                                                                                 // Number of events in event list.
                 NULL,                                                                              // Event list.
                 NULL                                                                               // Event.
                );
  }

  else
  {
    // Binding node VAO...
    glBindVertexArray
    (
     loc_data->vao                                                                                  // VAOs array.
    );

    // Binding VBO:
    glBindBuffer
    (
     GL_ARRAY_BUFFER,                                                                               // VBO target.
     loc_data->vbo                                                                                  // VBO to bind.
    );

    // Creating and initializing a buffer object's data store:
    glBufferSubData
    (
     GL_ARRAY_BUFFER,                                                                               // VBO target.
     0,                                                                                             // VBO Offset.
     sizeof(float4G_structure)*loc_data->size,                                                      // VBO size.
     loc_data->data                                                                                 // VBO data.
    );

    // Specifying the format for attribute in vertex shader:
    glVertexAttribPointer
    (
     loc_layout_index,                                                                              // VAO index.
     4,                                                                                             // VAO's number of components.
     GL_FLOAT,                                                                                      // Data type.
     GL_FALSE,                                                                                      // Not using normalized numbers.
     0,                                                                                             // Data stride.
     0                                                                                              // Data offset.
    );

    // Enabling attribute in vertex shader:
    glEnableVertexAttribArray
    (
     loc_layout_index                                                                               // VAO index.
    );

    // Binding VBO:
    glBindBuffer
    (
     GL_ARRAY_BUFFER,                                                                               // VBO target.
     loc_data->vbo                                                                                  // VBO to bind.
    );

    // Setting layout index in vertex shader...
    glDisableVertexAttribArray (loc_layout_index);                                                  // Unbinding data array...

    glFinish ();                                                                                    // Waiting for OpenGL to finish...

    // Writing OpenCL buffer:
    loc_error = clEnqueueWriteBuffer
                (
                 queue_id,                                                                          // OpenCL queue ID.
                 loc_data->buffer,                                                                  // Data buffer.
                 CL_TRUE,                                                                           // Blocking write flag.
                 0,                                                                                 // Data buffer offset.
                 sizeof(float4G_structure)*loc_data->size,                                          // Data buffer size.
                 loc_data->data,                                                                    // Data buffer.
                 0,                                                                                 // Number of events in the list.
                 NULL,                                                                              // Event list.
                 NULL                                                                               // Event.
                );
  }

  baseline->check_error (loc_error);                                                                // Checking returned error code...

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...
};

void queue::release
(
 float1G* loc_data,                                                                                 // Data object.
 GLuint   loc_layout_index                                                                          // OpenGL shader layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    glFinish ();                                                                                    // Waiting for OpenGL to finish...
    clFinish (queue_id);                                                                            // Waiting for OpenCL to finish...

    // Releasing openCL buffer:
    loc_error = clEnqueueReleaseGLObjects
                (
                 queue_id,                                                                          // Queue.
                 1,                                                                                 // Number of memory objects.
                 &loc_data->buffer,                                                                 // Memory object array.
                 0,                                                                                 // Number of events in event list.
                 NULL,                                                                              // Event list.
                 NULL                                                                               // Event.
                );

    clFinish (queue_id);                                                                            // Waiting for OpenCL to finish...

    glEnableVertexAttribArray (loc_layout_index);

    baseline->check_error (loc_error);                                                              // Checking returned error code...

    // Binding data:
    glBindBuffer (GL_ARRAY_BUFFER, loc_data->vbo);                                                  // Binding VBO...
    glVertexAttribPointer
    (
     loc_layout_index,                                                                              // VAO index.
     1,                                                                                             // Number of components of data vector.
     GL_FLOAT,                                                                                      // Data type.
     GL_FALSE,                                                                                      // Fixed-point data normalization.
     0,                                                                                             // Data stride.
     0                                                                                              // Data offset.
    );

    glFinish ();                                                                                    // Waiting for OpenGL to finish...
  }
  else
  {
    glFinish ();                                                                                    // Waiting for OpenGL to finish...
    clFinish (queue_id);                                                                            // Waiting for OpenCL to finish...

    // Checking layout index:
    if(loc_layout_index != loc_data->layout)
    {
      baseline->error ("Layout index mismatch!");                                                   // Printing message...
      exit (EXIT_FAILURE);                                                                          // Exiting...
    }

    // Reading OpenCL buffer:
    loc_error = clEnqueueReadBuffer
                (
                 queue_id,                                                                          // OpenCL queue ID.
                 loc_data->buffer,                                                                  // Data buffer.
                 CL_TRUE,                                                                           // Blocking write flag.
                 0,                                                                                 // Data buffer offset.
                 sizeof(GLfloat)*loc_data->size,                                                    // Data buffer size.
                 loc_data->data,                                                                    // Data buffer.
                 0,                                                                                 // Number of events in the list.
                 NULL,                                                                              // Event list.
                 NULL                                                                               // Event.
                );

    baseline->check_error (loc_error);

    clFinish (queue_id);                                                                            // Waiting for OpenCL to finish...
  }
};

void queue::release
(
 float4G* loc_data,                                                                                 // Data object.
 GLuint   loc_layout_index                                                                          // OpenGL shader layout index.
)
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  // Checking layout index:
  if(loc_layout_index != loc_data->layout)
  {
    baseline->error ("Layout index mismatch!");                                                     // Printing message...
    exit (EXIT_FAILURE);                                                                            // Exiting...
  }

  if(baseline->interop)                                                                             // Checking for interoperability...
  {
    // Releasing openCL buffer:
    loc_error = clEnqueueReleaseGLObjects
                (
                 queue_id,                                                                          // Queue.
                 1,                                                                                 // Number of memory objects.
                 &loc_data->buffer,                                                                 // Memory object array.
                 0,                                                                                 // Number of events in event list.
                 NULL,                                                                              // Event list.
                 NULL                                                                               // Event.
                );
  }

  else
  {
    // Reading OpenCL buffer:
    loc_error = clEnqueueReadBuffer
                (
                 queue_id,                                                                          // OpenCL queue ID.
                 loc_data->buffer,                                                                  // Data buffer.
                 CL_TRUE,                                                                           // Blocking write flag.
                 0,                                                                                 // Data buffer offset.
                 sizeof(float4G_structure)*loc_data->size,                                          // Data buffer size.
                 loc_data->data,                                                                    // Data buffer.
                 0,                                                                                 // Number of events in the list.
                 NULL,                                                                              // Event list.
                 NULL                                                                               // Event.
                );
  }

  baseline->check_error (loc_error);                                                                // Checking returned error code...

  clFinish (queue_id);                                                                              // Ensuring that all OpenCL has completed all operations...

  glEnableVertexAttribArray (loc_layout_index);

  // Binding data:
  glBindBuffer (GL_ARRAY_BUFFER, loc_data->vbo);                                                    // Binding VBO...
  glVertexAttribPointer
  (
   loc_layout_index,                                                                                // VAO index.
   4,                                                                                               // Number of components of data vector.
   GL_FLOAT,                                                                                        // Data type.
   GL_FALSE,                                                                                        // Fixed-point data normalization.
   0,                                                                                               // Data stride.
   0                                                                                                // Data offset.
  );

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
};

queue::~queue()
{
  cl_int loc_error;                                                                                 // Local error code.

  glFinish ();                                                                                      // Waiting for OpenGL to finish...
  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  baseline->action ("releasing OpenCL command queue...");                                           // Printing message...

  loc_error = clReleaseCommandQueue (queue_id);                                                     // Releasing OpenCL queue...

  baseline->check_error (loc_error);                                                                // Checking error...

  clFinish (queue_id);                                                                              // Waiting for OpenCL to finish...

  baseline->done ();                                                                                // Printing message...
}
