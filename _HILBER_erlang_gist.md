https://gist.github.com/dergraf/6038748

space filling hilbert curve that maps two-dimensional space to a one-dimensional space
Raw

```erlang
-module(hilbert).
-export([curve/1, curve/7, point_to_hilbert/3]).

-define(HILBERTMAP, [
        {a, [{{0,0},{0,d}}, {{0,1},{1,a}}, {{1,0},{3,b}}, {{1,1},{2,a}}]},
        {b, [{{0,0},{2,b}}, {{0,1},{1,b}}, {{1,0},{3,a}}, {{1,1},{0,c}}]},
        {c, [{{0,0},{2,c}}, {{0,1},{3,d}}, {{1,0},{1,c}}, {{1,1},{0,b}}]},
        {d, [{{0,0},{0,a}}, {{0,1},{3,c}}, {{1,0},{1,d}}, {{1,1},{2,d}}]}
        ]).

curve(N) ->
    curve(0, 0, 1, 0, 0, 1, N).

curve(X0, Y0, Xi, Xj, Yi, Yj, 0) ->
    X = X0 + ((Xi + Yi) / 2),
    Y = Y0 + ((Xj + Yj) / 2),
    io:format("~p, ~p~n", [X, Y]);
curve(X0, Y0, Xi, Xj, Yi, Yj, N) ->
    curve(X0,               Y0,               Yi/2, Yj/2, Xi/2, Xj/2, N - 1),
    curve(X0 + Xi/2,        Y0 + Xj/2,        Xi/2, Xj/2, Yi/2, Yj/2, N - 1),
    curve(X0 + Xi/2 + Yi/2, Y0 + Xj/2 + Yj/2, Xi/2, Xj/2, Yi/2, Yj/2, N - 1),
    curve(X0 + Xi/2 + Yi,   Y0 + Xj/2 + Yj,  -Yi/2,-Yj/2,-Xi/2,-Xj/2, N - 1).

point_to_hilbert(X, Y, N) ->
    CurrentSquare = a,
    Position = 0,
    point_to_hilbert(X, Y, N - 1, CurrentSquare, Position).

point_to_hilbert(_, _, N, _, Position) when N < 0 -> Position;
point_to_hilbert(X, Y, N, CurrentSquare, Position) ->
    NewPos = Position bsl 2,
    QuadX = case X band (1 bsl N) of 0 -> 0; _ -> 1 end,
    QuadY = case Y band (1 bsl N) of 0 -> 0; _ -> 1 end,
    {QuadPos, NewCurrentSquare} = proplists:get_value({QuadX, QuadY}, proplists:get_value(CurrentSquare, ?HILBERTMAP)),
    point_to_hilbert(X, Y, N - 1, NewCurrentSquare, NewPos bor QuadPos).
```
