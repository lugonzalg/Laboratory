## LEXER

  Lexer gonna search for patterns within the yml file. For the v1 there are 4 patterns:

  1. Object[\ta-z:\n]: tab(s) (indent level), a-z characters (key definition), colon (end of definition) and new line (end of statement).
      
  2. Attribute[\ta-z:a-z\n]: tab(s) (indent level), a-z characters (key definition), colon (end of key), a-z characters (value definition) and new line (end of statement).
      
  3. Item/Object[\t-a-z:\n]: tab(s) (indent level), dash (array marker), a-z characters (key definition), colon (end of definition) and new line (end of statement).
      
  4. Item/Attribute[\t-a-z:a-z\n]: tab(s) (indent level), dash (array marker), a-z characters (key definition), colon (end of definition), a-z characters (value definition) and new line (end of statement).
    
  ### DIAGRAM

  ![Lexer diagram](https://raw.githubusercontent.com/lugonzalg/Data_Structures/main/Lexer-Parser/ex00/StateMachine.jpg)

### STATE MACHINE

  ![Lexer diagram](https://raw.githubusercontent.com/lugonzalg/Data_Structures/main/Lexer-Parser/ex00/state_machine.jpg)
