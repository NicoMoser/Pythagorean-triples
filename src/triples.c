#include <stdio.h>
#include <stdlib.h>

typedef int (*py_callback)(unsigned int x, unsigned int y, unsigned int z);

int py_triples(unsigned int n, py_callback cb)
{
  unsigned int i = 0, x, y, z;
  for (z = 1; ; z++)
    {
      for (x = 1; x <= z+1; x++)
	{
	  for (y = x; y <= z+1; y++)
	    {
	      if (x*x + y*y == z*z)
		{
		  cb(x,y,z);
		  i++;
		  if (i >= n)
		    {
		      return 0;
		    }
		}
	    }
	}
    }
}

int print_py(unsigned int x, unsigned int y, unsigned int z)
{
  return printf("%d^2 + %d^2 == %d^2\n", x, y, z);
}

int main(int argc, char* argv[])
{
  int n = 0;
  if (argc > 1)
    {
      n = atoi(argv[1]);
      if (n > 0)
	{
	  py_triples(n, print_py);
	  return 0;
	}
    }
  return 1;
}
