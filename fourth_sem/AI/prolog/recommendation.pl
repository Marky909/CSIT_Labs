% -----------------------------
% Knowledge Base
% -----------------------------

% Movies and their genres
movie(the_matrix, sci_fi).
movie(inception, sci_fi).
movie(interstellar, sci_fi).
movie(the_godfather, crime).
movie(pulp_fiction, crime).
movie(toy_story, animation).
movie(frozen, animation).

% User preferences
likes(mark, sci_fi).
likes(mark, animation).
likes(alex, crime).
likes(sam, animation).

% -----------------------------
% Rules
% -----------------------------

% Recommend a movie to a user based on their preferred genre
recommend(User, Movie) :-
    likes(User, Genre),
    movie(Movie, Genre).
