
********************************************************************************
**Building GNDStk**
********************************************************************************

We designed GNDStk with the hope that it will prove to be straightforward to
download, to install, and to use. GNDStk resides on Github, and uses CMake as
its primary build system.

The following description is based on commands that work for us, on a Linux
system. Adapt our instructions as necessary for your own platform.



========================================
Download
========================================

Enter the directory in which you'd like GNDStk to reside. This might be your
root user directory, e.g. ``/home/yourname/``, or perhaps, say, in a dedicated
directory that you use for your projects.

**Download:**

.. code:: bash

   git clone https://github.com/njoy/GNDStk.git

**Enter directory:**

.. code:: bash

   cd GNDStk

At this point you can, if you wish, check out a specific branch of GNDStk.
As is typical in ``git`` repositories, our main branch is called ``master``.
So, if you wish:

**Check out a branch:**

.. code:: bash

   git checkout master

With ``master`` that isn't necessary, but you can replace ``master`` with
something else.



========================================
Build & Test
========================================

Some people prefer, as you may, to create a ``build`` directory in which to
build the project. (Doing as much certainly helps to keep a project's base
directory more free of clutter.) Continuing from the ``GNDStk`` directory,
where we left off in the Downloading narrative above:

**Make and enter a build directory:**

.. code:: console

   mkdir build
   cd build

Now run ``cmake`` itself, being sure to point it one level up, to where the
``CMakeLists.txt`` file resides, if you're indeed down in ``build``.

**Run cmake:**

.. code:: bash

   cmake ..

The *good* news is that the above command should download GNDStk's
dependencies -- the modest number of outside C++ libraries on which
it depends -- automatically. The *bad* news is that the download may, for the
same reason, take quite some time. Resist the temptation to terminate the
command, perhaps believing that your computer has hung, and consider starting
``cmake ..`` before lunch hour if you have a slow Internet connection. The main
culprit appears to be the `nlohmann/json` library,
https://github.com/nlohmann/json. An excellent library, by all accounts, and
invaluable as the workhorse for GNDStk's JSON capabilities; but responsible,
at the time of the writing, for over 400MB -- about 95% -- of
the entire dependencies directory that the above command creates.

Finally, the ``Makefile`` that the above ``cmake`` command should have created,
can be used to build GNDStk's test suite.

**Build GNDStk's test suite:**

.. code:: bash

   make

Or, if you have for instance six processor cores available, then

**Multicore build:**

.. code:: bash

   make -j 6

will no doubt run far faster.

GNDStk was carefully designed to **not** be one of those infamous C++ libraries
that triggers hours-long, even many-minutes-long, compilations, leaving
beleaguered users wondering if they could more quickly find the data they're
looking for by loading a file into an editor, finding the data of interest,
and cutting-and-pasting in their own code.
The above ``make`` in fact compiles *several* codes, comprising our entire,
substantial GNDStk test suite with broad coverage across all of its considerable
capabilities. Even so, we hope and believe that you won't have the need to
report to us that a multicore build took more than a minute or two, at most,
on a modern and well-oiled home or office machine.

You can then invoke:

**Run GNDStk's tests:**

.. code:: bash

   make test

to *run* all of the tests. We hope that you will, at this point, have the same
pleasant experience that we do when we invoke ``make test`` on our ``master``
GNDStk branch: a report that :green:`100% tests passed`.

.. fixme write more here, regarding how to build individual user codes.



========================================
Summary
========================================

Here's a summary of the commands described above, from downloading GNDS from
our repository, through building and running its full suite of tests:

.. code:: console

   # Get GNDStk
   git clone https://github.com/njoy/GNDStk.git
   cd GNDStk
   git checkout master

   # Cmake; may take some time
   mkdir build
   cd build
   cmake ..

   # Make and run test suite
   make
   # ...or make -j 6
   make test



========================================
Your Own Application
========================================

Let's outline how you can interface your own application code with GNDStk,
using CMake.

First, you should have downloaded the GNDStk repository as described above.
Building and running its test suite isn't a prerequisite for our present
purposes, but certainly wouldn't hurt. Any problems you might encounter in
that process would no doubt show themselves again, in some form, here.

Now assume you have some directory, call it MyApp, for your application, with
the following file structure:

.. code:: text

   MyApp/
      CMakeLists.txt
      dependencies/
         GNDStk/
      src/
         app.cpp

``GNDStk/`` is the cloned GNDStk repository. (If you downloaded it elsewhere
and don't want a duplicate, then perhaps make it a symlink here , a.k.a. a
shortcut, to the cloned repo.) Next, for our simple illustration here, let
``app.cpp`` be a single C++ source file that contains all of your code to be
used with GNDStk. The remaining structure is typical for applications that
use CMake.

A working ``CMakeLists.txt`` for the above is as follows:

.. literalinclude:: files/build-cmake/MyApp/CMakeLists.txt

And, the simplest possible GNDStk-aware ``app.cpp`` would be:

.. literalinclude:: files/build-cmake/MyApp/src/app.cpp

Finally, building ``app`` should be as simple as this:

.. code:: console

   cd MyApp  # <== If you're not there already
   mkdir build
   cd build
   cmake ..
   make

If all went well, ``app.cpp`` should have been compiled into an executable
file called ``app``.



========================================
Alternative: Bash Script
========================================

An important goal for us is that GNDStk be accessible, with as minimally
intrusive a build process as possible, to a wide variety of researchers.

If you're using libraries other than GNDStk, they may impose their own build
systems -- possibly ones you like, possibly ones you don't, but ones you're
stuck with, regardless, for better or for worse. You may, on the other hand,
be using your preferred and well-liked build system. Independent of what you
may or may not be working with in that respect, we want GNDStk to impose as
little additional complexity as it can.

In the above spirit, and if you're using a Linux or Linux-based machine, you
may find that the contents of the following simple shell script can be adapted
easily to your needs:

.. literalinclude:: files/build-bash/bash-build-script.sh

Begin, as you can see, by specifying the base GNDStk directory you cloned. The
script immediately uses this value to create a simple compilation command, in
this case one that uses ``g++`` as its C++ compiler. Next, the script checks
to see if a certain ``.cpp`` file, from one of GNDStk's dependencies, has been
compiled. If it hasn't been, yet, then it is now. Finally, another compilation
command builds your own application -- illustrated in this simple example as
a single C++ source file called ``app.cpp``. Consider trying this first with
the minimal ``app.cpp`` that was shown in the section on CMake builds.

You're welcome to adapt our script, or its contents, as may be necessary or
helpful within your own build regime.

**Some caveats**. Use of the sample bash script assumes that you've downloaded
GNDStk, and run ``cmake ..`` (and in a ``build`` directory), as outlined
earlier. You can easily adjust the script if, for whatever reason, you
configured things in a different manner. Realize, however, that
the ``cmake ..`` in some form, or steps that created the same effect, must
have happened in order for GNDStk's dependencies to have been downloaded
into the ``_deps`` directory that makes several appearances throughout the
script's compilation command.

Be aware also that the script reflects dependencies, and their locations in
directories, that are correct at the time of this writing. While we intend to
update these instructions if and when we make relevant changes to GNDStk, it's
possible that some detective work may prove to be necessary if we drop the
documentation ball after dependencies do, for whatever reason, change. If, for
instance, we decide to explore someday one of those deep mysteries of the
universe that regularly visits our world through computers, such as why
``pugixml.cpp`` ended up in ``src/src/`` rather than just in ``src/``, then
it's possible, even as much as we try to behave, that we'll make a quick change
to our own make system's actions without updating these instructions for a
simple script in an entirely timely manner.



========================================
Header-Only Library
========================================

GNDStk, proper, is a C++ *header-only library*. You can find plenty of
information online if you're unfamiliar with the concept. In our opinion,
header-only libraries provide a multitude of advantages, such as making builds
far less complex than they'd otherwise be; and their disadvantages, generally
distilling down to some variation of "builds can take longer," are
straightforward to mitigate with careful design. We designed GNDStk carefully.

Our library does, however, have one *dependency*, ``pugixml``
(https://pugixml.org/), that has a single C++ source (not header) file. That's
why our sample shell script, if you read that section, needed to compile one
``.cpp`` file, other than your own, directly.

We mention our library's header-only nature not so as to conclude this chapter
with any particular profound point, but largely for informational purposes. If
you're unfamiliar with the header-only concept, or with how to write or to use
such libraries in C++, then you might find it helpful -- or more importantly,
fun -- to learn more. With respect to GNDStk, knowing that it's formulated in
this fashion may allow you, in one way or another, to make the best use of
GNDStk in your own build system, and in your own application.
