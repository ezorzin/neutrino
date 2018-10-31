/// @file

#ifndef utilities_hpp
#define utilities_hpp

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include <errno.h>

  void    load_file(char* neutrino_path, const char* file_name, char** file_buffer, size_t* file_size);
  void    write_file(const char* file_name, char* file_buffer);
  void    free_file(char* buffer);
  int     query_numeric(const char* caption, int min, int max);

#endif
