# Pythagorean-triples
c code for Pythagorean triples

Inspired by http://aras-p.info/blog/2018/12/28/Modern-C-Lamentations/ which was inspired by http://ericniebler.com/2018/12/05/standard-ranges/

I find many C++ features incomprehensible and the ones illustrated in Niebler's example are among them.

A challenge with "toy" or illustrative examples is that they are subject to criticism that they are poorly equipped to generalize in any of dozens of ways. Often another language is suggested as a better approach since the particular generalization is particularly easy in that language.

In this case the complaint that caught my eye was "What if I want to do any number of things (besides print the values) when there is a match? Then I have to rewrite my code for each case, because the 'what do I do' and 'how do I get there' parts are inextricable."

I've spent most of my programming life writing C and nothing that would be called "modern" C++ (yes I know Niebler was illustrating forthcoming features) so I couldn't resist writing a C solution that provides a mechanism to allow the caller to specify what to do when the algorithm found a match by using a callback function.

There are plenty of ways to criticize this, among them - suppose you want your callback to also take the counter so it can use the fact that it's on the 'i-th' triple. You would have to change the callback typedef, which would break all the existing callbacks.

A way to anticipate that is to change the function signature so that it has a version and a void pointer. The pointer passed is to a struct that strictly corresponds to the version argument. New structs would only append fields. Assume existing field layout doesn't change when appending members. Existing functions would only use the members corresponding the version they were built to handle. If the passed-in version were lower than the function could handle, it's probably an error. This scheme is meant to handle the case of existing functions getting a higher version than they were built for but just using the struct members corresponding to their verison.

The initial version, struct would be
    0, { unsigned int x, y, z; }

and the following version, struct would be
    1, { unsigned int, x, y, z;
         unsigned int i;
       }

There are ways to handle structs with variable length fields etc. but that's beyond this scope.
