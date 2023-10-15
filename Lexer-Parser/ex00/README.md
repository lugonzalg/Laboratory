##LEXER

  Lexer gonna search for patterns within the yml file. For the v1 there are 3 patterns:

  1. Object[\ta-z:\n]: we are looking for tab(s) (indent level), a-z characters (the object definition), colon (end of definition) and new line (end of statement).
      - No character out of regex [\ta-z:\n].
      - Indentation level correct to the context.
      - A object is a sequence of [\ta-z:\n].
