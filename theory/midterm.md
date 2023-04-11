Topics

Models of Computation

Turing Machine - State machine with a read/write head and a tape.  All traditional models of computation are equivalent to this one.

There are problems that cannot be solved.  the Halting problem states that no software can look at (program + input) and decide if that program will eventually halt on that input (or be an infinite loop).

Most common model: Von Neumann Machine (Stack + Heap + Text + an actor (CPU) stepping through the code).

Neural Network: A graph of nodes flowing left to right.  The far left are inputs, and the far right are outputs.  Middle nodes are computed as the sum of their predecessors and then mapped through a "sigmoid" function usually something f(x) = x if x >= 0, else 
0.1 * x if x < 0. The output is a "fuzzy boolean logic" usually using the highest value as the one most likely to be true.

Quantum Model of Computation:  Think of it as a traditional computer, but where the values have probabilites instead of specific choices.   Ex: x = 1 with prob 0.75 = 2 with prob 0.10, and  = 3 with prob 0.15.

These can do more than traditional computers. These can break security.  These are general called "probabalistic computing models" these are nice when working with real world simulations or models.

Middle ground model: DNA computation.  DNA ~ 1000 cycles / second.   Reasonable to have 10^20 DNA strands in 1 CC of fluid.  (10^23 cycles per second vastly exceeds all current traditional computational resources).

Language Models

Procedural - Recipe book style programming.  Take steps to transform inputs into outputs.

Functional - 

(out1,out2,out3) = f(g(in1),h(in2))

The functions are "math" functions not just programming functions. No side effects like global variables or i/o that happen "inside a function".

Logic (Contstraints) -

Database of things that are true.  Action is to make something true.

Common case is layout / typesetting.  The developer specifies the constraints using some language (CSS for example), and then a constraints engine uses those constraints to layout a view for a given user on their preferred dimensions.

Object oriented

Map problems to typical model of language in a human.  Humans can only keep track of about 4 pm 1 things at a time.  So grouping ideas into categories (classes) is the only way to resolve complexity if humans are involved.

class (Nouns) verbs tend to be methods.
There should be private parts (inside / outside).

Is very useful to describe categories in terms of other (more generic) categories.  Polymorphism is how this is done.

Regular Expressions



Grammars

Compiler Structure

Language and Security

Halting problem is a security problem.  So non-turing complete languages are important to constrain the problem space.

General purpose languages are a security problem.  So be be thougful about what you allow and where.