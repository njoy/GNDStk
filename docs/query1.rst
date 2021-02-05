
********************************************************************************
**Query System, Part 1**
********************************************************************************

========================================
Meta & Child
========================================

--------------------
Meta Class
--------------------

--------------------
Child Class
--------------------

========================================
Operators
========================================

========================================
Query Metadata
========================================

--------------------
Node.meta(string)
--------------------

.. literalinclude:: node-meta-string.cc
   :language: cpp
   :linenos:

--------------------
Node.meta(Meta)
--------------------

.. literalinclude:: node-meta-meta.cc
   :language: cpp
   :linenos:

--------------------
Node(Meta)
--------------------

.. literalinclude:: node-meta-call.cc
   :language: cpp
   :linenos:

========================================
Query Child Nodes
========================================

--------------------
Node.one(string)
--------------------

.. literalinclude:: node-one-string.cc
   :language: cpp
   :linenos:

--------------------
Node.many(string)
--------------------

.. literalinclude:: node-many-string.cc
   :language: cpp
   :linenos:

--------------------
Node.child(Child)
--------------------

.. literalinclude:: node-child-child.cc
   :language: cpp
   :linenos:

--------------------
Node(Child)
--------------------

.. literalinclude:: node-child-call.cc
   :language: cpp
   :linenos:
