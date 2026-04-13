# Arena 259
> A group project for the SOU CS259 class on Object Oriented Programming [OOP] that aims to create a text-based object battle arena in which each student creates a derived class of an object with methods and attributes that simulate 1v1 combat. Over the course of the term (Spring 2026), the class will develop each aspect of the program including the necessary helper classes and functions following along with the instruction in _Y. Liang_'s _Introduction to C++ Programming and Data Structures 5e_. The culmination of the project will be a tournament-style battle in which each of the student-created objects battle each other student-created object. The object with the most wins will be declared the victor. At the end of the tournament, students will be able to discuss why the object with high win percentage were more successful. 
____

# Creature Base Class!
> All battling creatures should be a derived class of Creature to ensure that the contracts for creature to creature interaction remain consistent. To change a contract, we modify the base class first and then enforce all derived classes to comply at instantiation.

# Attribute Points
> Each class will have attributes, such as HP, Defense, Damage, etc...
If we say each class can have n attribute points, each classmate can distribute the points into their class accross all the stats.
With some tinkering, this could be a good step for ensuring balance.

# Buff Debuff Class
add a buff/debuff class that stores any modifiers that will be added to a creature.

# Agent Class
Gets called at specific points in a battle: when a player is getting too powerful, a villain can automatically called to the battle; or Helper classes which assist players who are doing poorly like mending their weapons or healing them, etc.
# Balanced attributes
e.g. if a character is heavy, they will move slow but have more health, if they are light, they can move quick but has less health

# Battle Machanics
 >We should add chance modifiers such as critical hits and dodging. We can also add some sort of energy or power mechanic.