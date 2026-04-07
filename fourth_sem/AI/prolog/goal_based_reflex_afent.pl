% -----------------------------
% Environment Facts
% -----------------------------
room(room1).
room(room2).
room(room3).

dirty(room1).
dirty(room2).
% room3 is clean, so no dirty(room3) fact

% Robot location
location(robot, room1).

% -----------------------------
% Actions
% -----------------------------

% Move robot to another room
move(Robot, Room) :-
    location(Robot, Current),
    Current \= Room,
    retract(location(Robot, Current)),
    assert(location(Robot, Room)),
    write(Robot), write(' moved from '), write(Current), write(' to '), write(Room), nl.

% Clean the room
clean(Robot, Room) :-
    location(Robot, Room),
    dirty(Room),
    retract(dirty(Room)),
    write(Robot), write(' cleaned '), write(Room), nl.

% -----------------------------
% Goal: Clean all rooms
% -----------------------------
goal_clean_all :-
    dirty(Room),
    location(robot, RobotRoom),
    (RobotRoom \= Room -> move(robot, Room) ; true),
    clean(robot, Room),
    fail.   % Continue until no dirty rooms left

goal_clean_all :- 
    write('All rooms are clean!'), nl.

% filepath: c:\Bsc_csit_labs\fourth_sem\Mark_Dangal_AI\prolog\goal_based_reflex_afent.pl
:- dynamic location/2.
:- dynamic dirty/1.

