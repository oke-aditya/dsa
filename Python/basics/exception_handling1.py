# BaseException is the common base class of all exceptions. 
# One of its subclasses, Exception, is the base class of all the non-fatal exceptions. 
# Exceptions which are not subclasses of Exception are not typically handled, 
# because they are used to indicate that the program should terminate. 
# They include SystemExit which is raised by sys.exit() and KeyboardInterrupt 
# which is raised when a user wishes to interrupt the program.

# Exception can be used as a wildcard that catches (almost) everything. 
# However, it is good practice to be as specific as possible with the types 
# of exceptions that we intend to handle, and to allow any unexpected exceptions to propagate on.
# The most common pattern for handling Exception is to print or log the exception and 
# then re-raise it (allowing a caller to handle the exception as well):

import sys

try:
    f = open('myfile.txt')
    s = f.readline()
    i = int(s.strip())
except OSError as err:
    print("OS error:", err)
except ValueError:
    print("Could not convert data to an integer.")
except Exception as err:
    print(f"Unexpected {err=}, {type(err)=}")
    raise


# When an exception is created in order to be raised, it is 
# usually initialized with information that describes the error that has occurred. 
# There are cases where it is useful to add information after the exception was caught.
# For this purpose, exceptions have a method add_note(note) that accepts a string and adds it 
# to the exception’s notes list. 
# The standard traceback rendering includes all notes, 
# in the order they were added, after the exception.

try:

    raise TypeError('bad type')

except Exception as e:

    e.add_note('Add some information')

    e.add_note('Add some more information')

    raise

