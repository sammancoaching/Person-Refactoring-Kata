Person Refactoring Kata
=======================

Can you spot any code smells? We think you should be able to find Primitive Obsession. Refactor to remove it.

If you want to really practice doing refactorings safely, you'll want to do it in a series of small, safe steps. This is the outline of a path that will take you there:

1. [Encapsulate Variable](https://sammancoaching.org/refactorings/encapsulate_variable.html) on the "personalNumber" field.
2. [Replace Primitive with Object](https://sammancoaching.org/refactorings/replace_primitive_with_object.html) on the "personalNumber" field. You'll create a class "PersonalNumber".
3. [Move Function](https://sammancoaching.org/refactorings/move_function.html) to move the "birthYear" function to the "PersonalNumber" class. 

At this point you should have fixed the primitive being used for the swedish personal number. 

4. Repeat the steps for the phoneNumber field. Create a class PhoneNumber and move countryCode to it.
5. Repeat the steps for the role field. Create a class Role and move canDeleteUsers to it.



