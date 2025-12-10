Engine:

    - [ ] Consider using the analytical gradients for shading normals
    https://iquilezles.org/articles/distgradfunctions3d/
    (sphere & cylinder available);
    - [ ] Make SDFs always use origin
        - [x] implies implementing a way to translate and rotate space
        which would have to be used at sdf call site
            - might need determinant soon.
        - would make translating Inigo's code easier
    - [ ] Start work on sdf call structure
        - Linked list is hard to do without malloc
        - So the choice is a static array of structs or a static structure
        of arrays;
            - second option means shapes.h refactor
    - [ ] Start work on smooth shading, using raymarching
        - https://iquilezles.org/articles/rmshadows/
    - [ ] Inigo has intersection functions, could be a performance hail
    mary if it gets too bad but could take a while to implement
    - [w] Install perf to see the hot loops in the code
        - [x] needs bison
        - [x] needs flex
        - [ ] needs a bunch of libraries i am a bit lazy to fetch
            - [ ] also needs them in INCLUDES at runtime
