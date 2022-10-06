cmake_minimum_required(VERSION 3.20)
project(Project1_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1_Starter_Code
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h Comma.h Comma.cpp Period.h Period.cpp Q_Mark.cpp Q_Mark.h Left_Paren.cpp Left_Paren.h Right_Paren.cpp Right_Paren.h Multiply.cpp Multiply.h Add.cpp Add.h Schemes.cpp Schemes.h Queries.cpp Queries.h Facts.cpp Facts.h Rules.cpp Rules.h ID.cpp ID.h String.cpp String.h Comment.cpp Comment.h parser.h datalogProgram.cpp datalogProgram.h predicate.h parameter.h rule.h parser.cpp)
