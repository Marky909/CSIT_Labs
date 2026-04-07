% -----------------------------
% Family Facts
% -----------------------------

% parent(Parent, Child)
parent(john, alice).
parent(mary, alice).
parent(john, bob).
parent(mary, bob).
parent(robert, john).
parent(linda, john).
parent(robert, susan).
parent(linda, susan).
parent(susan, charlie).
parent(david, charlie).

# Here we have a small family tree:
# John & Mary → parents of Alice and Bob
# Robert & Linda → parents of John and Susan
# Susan & David → parents of Charlie