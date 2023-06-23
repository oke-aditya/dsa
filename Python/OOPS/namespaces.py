# A namespace is a mapping from names to objects. 
# Most namespaces are currently implemented as Python dictionaries, 
# but that’s normally not noticeable in any way (except for performance), 
# and it may change in the future. 
# Examples of namespaces are: the set of built-in names (containing functions such as abs(), 
# and built-in exception names); the global names in a module; and the local names in a 
# function invocation. In a sense the set of attributes of an object also form a namespace. 
# The important thing to know about namespaces is that there is absolutely no relation between 
# names in different namespaces; for instance, two different modules 
# may both define a function maximize without confusion — 
# users of the modules must prefix it with the module name.

# Attributes may be read-only or writable. In the latter case, 
# assignment to attributes is possible. Module attributes are writable: you can write modname.the_answer = 42. 
# Writable attributes may also be deleted with the del statement. 
# For example, del modname.the_answer will remove the attribute the_answer from the object named by modname.

# Namespaces are created at different moments and have different lifetimes. 
# The namespace containing the built-in names is created when the Python interpreter starts up,
# and is never deleted. The global namespace for a module is created when t
# he module definition is read in; normally, module namespaces also last until the interpreter quits. 
# The statements executed by the top-level invocation of the interpreter, either read from 
# a script file or interactively, are considered part of a module called __main__, so they have 
# their own global namespace. (The built-in names actually also live in a module; this is called builtins.
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
# The local namespace for a function is created when the function is called, 
# and deleted when the function returns or raises an exception that is not 
# handled within the function. (Actually, forgetting would be a better way to describe what actually happens.) 
# Of course, recursive invocations each have their own local namespace.
    
